
#include <sys/types.h> /* per compatibilita' con vari sistemi */
#include <stdlib.h> /* per EXIT_SUCCESS*/
#include <sys/socket.h> /* per socket, struct sockaddr, sockaddr_storage, bind, listen */
#include <netinet/in.h> /* per IPPROTO_TCP, htonl, htons, INET_ADDRSTRLEN */
#include <string.h>  /* per memset */
#include <stdio.h> /* per perror */
#include <arpa/inet.h> /* per inet_ntop */
#include <stddef.h>
#include <unistd.h> /* per close, fork */

/* Definisco alcune costanti come macro */
#define PORT 5000 
#define BACKLOG 10 
#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    /* 
        Dichiaro due variabili, rispettivamente per la listening socket e una per la connected socket.
        La prima si occuperà SOLO ed ESCLUSIVAMENTE di accettare richieste di connessione in arrivo, che verranno accodate fino all'accettazione da parte del server.
        La seconda si occuperà della comunicazione effettiva con il client.
     */
    int listenfd, connfd;

    /*
        Dichiaro due variabili che conterrano l'indirizzo del server e del client.
        Nota l'uso di sockaddr_storage(invece di in). È, notabilmente:
        1)Un contenitore sia per indirizzi IPv4 che IPv6.(In è solo per IPv4).
        2)Più capiente, generalmente, di qualsiasi sockaddr_XX.
    */
    struct sockaddr_storage myaddr, clientaddr;
    socklen_t myaddrlen;
    socklen_t clientaddrlen;

    char ipstr[INET6_ADDRSTRLEN]; // INET6_ADDSTRLEN è una costante per la lunghezza predefinita di un indirizzo IPv6. Per gli indirizzi IPv4, useremo INET_ADDSTRLEN.

    char buffer[BUFFER_SIZE];
    /*
        Si sarebbe potuto usare getaddrinfo per ottere un indirizzo IP appropriato: si noti che questa
        e' una estensione POSIX che deve essere esplicitamente abilitata in gcc.
        Per semplicita', cabliamo l'uso di 0.0.0.0 IPv4
    */
    memset(&myaddr, 0, sizeof(myaddr));
    struct sockaddr_in *addrptr = (struct sockaddr_in *)&myaddr; //Trasformiamo la struct myaddr in un puntatore.
    addrptr->sin_family = AF_INET;
    inet_pton(addrptr->sin_family, "0.0.0.0", &addrptr->sin_addr); //Associamo, come indirizzo di myaddr, l'indirizzo 0.0.0.0.
    addrptr->sin_port = htons(5000);
    myaddrlen = sizeof(struct sockaddr_in);

    /*
        Creo la socket. Si noti l'uso di SOCK_STREAM come tipo di socket,
        ovvero la semantica della comunicazione, nello specifico comunicazione
        orienta alla connessione, basata sul trafsferimento affidabile, bidirezionale
        di un flusso di byte.

        Si noti che in questo momento la socket non ha ancora un indirizzo e non puo'
        inviare ne' ricevere dati.

        Nota: restituisce il file descriptor della socket, oppure -1 in caso di errore (dettagliato in errno)
    */
    if ((listenfd = socket(myaddr.ss_family, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* 
        Uso bind per associare alla socket un indirizzo locale (indirizzo IP e numero di porta).
    */
    if (bind(listenfd, (struct sockaddr *) &myaddr, myaddrlen) == -1) { /* restituisce 0 in caso di successo; -1 altrimenti */
        perror("bind");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    /*
        Preparo la socket per accettare connessioni, usando la funzione listen().Il primo
        argomento indica il descriptor della socket che effettuerà il listen. Il secondo argomento(Backlog) è una costante, edindica
        la lunghezza massima della coda di connessioni in attesa di accettazione da parte del server.

        Il valore del secondo argomento viene troncato se superiore a un valore massimo
        di sistema, che si può trovare qui: /proc/sys/net/core/somaxconn
    */
    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        close(listenfd);
        exit(EXIT_FAILURE);
    }


    while (1) {
        memset(&clientaddr, 0, sizeof(clientaddr));
        clientaddrlen = sizeof(clientaddr);

        /*
            Accetta una connessione in attesa sulla listening socket. Restituisce il file descriptor
            della socket connessa (al peer remoto), oppure -1 in caso di errore (dettagliato nella varibile errno)    
        */
        if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen)) == -1) 
        { 
            /* accept si blocca finche' non c'è una connessione */
            perror("accept");
            continue; /* passa avanti e tenta di accettare una nuova connessione */
        }

        /* Converto l'indirizzo del client in stringa.*/
        inet_ntop(clientaddr.ss_family, &clientaddr, ipstr, sizeof(ipstr));
 
        /* Stampa di debug */
        fprintf(stderr, "Accepted connection from: network address = %s ; port = %d\n",
            ipstr,
            clientaddr.ss_family == AF_INET ? ((struct sockaddr_in *)&clientaddr)->sin_port : ((struct sockaddr_in6 *)&clientaddr)->sin6_port);

        /* Echo server che reinvia i dati ricevuti! */
        while (1) {
            ssize_t nread = recv(connfd, &buffer, sizeof(buffer), 0);
            if (nread == -1) { /* restituisce il numero di byte letti oppure -1 in caso di errore*/
                perror("recv");
                break; /* esce dal ciclo infinito, in modo da raggiungere l'istruzione che chiude la connessione.*/
            }

            if (nread == 0) {
                break; // il client ha chiuso la connessione, quindi il sever esce dal ciclo e eventualmente chiudera' il suo lato.
            }


            ssize_t nwritten = send(connfd, &buffer, nread, 0);
            if (nwritten == -1) { /* restituisce il numero di byte scritti oppure -1 in caso di errore*/
                perror("send");
                break; /* esce dal ciclo infinito, in modo da raggiungere l'istruzione che chiude la connessione*/
            }

        }

        fprintf(stderr, "Closing connection to: network address = %s ; port = %d\n",
            ipstr,
            clientaddr.ss_family == AF_INET ? ((struct sockaddr_in *)&clientaddr)->sin_port : ((struct sockaddr_in6 *)&clientaddr)->sin6_port);



        if (close(connfd) == -1) {
            perror("close");
        }
    }

    /* In realta' questa porizione di codice non viene mai eseguita! Per terminare il programma, bisogna killarlo */
    if (close(listenfd) == -1) {
        perror("listenfd close: ");
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}