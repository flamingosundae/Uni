
#include <sys/types.h>  /* per compatibilita' con vari sistemi */
#include <stdlib.h>     /* per EXIT_SUCCESS*/
#include <sys/socket.h> /* per socket, struct sockaddr, sockaddr_storage, bind, listen */
#include <netinet/in.h> /* per IPPROTO_TCP, htonl, htons, INET_ADDRSTRLEN */
#include <string.h>     /* per memset */
#include <stdio.h>      /* per perror, fprintf */
#include <arpa/inet.h>  /* per inet_ntop */
#include <stddef.h>
#include <unistd.h> /* per close, fork */
#include <signal.h>
#include <errno.h>    /* per errno */
#include <sys/wait.h> /* per waitpid e WNOHANG */

/* Definisco alcune costanti come macro */
#define PORT 5000
#define BACKLOG 10
#define BUFFER_SIZE 100

void sigchld_handler(int signum)
{
    int saved_errno = errno;
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
    printf("Figlio morto\n");
    signal(signum, &sigchld_handler);
    errno = saved_errno;

    /*Gestore di segnali per il controllo dei figli morti. Nota alcune cose interessanti:
    A)L'uso di SIGCHILD come segnale per l'attivazione dell'handler.
    B)Il salvataggio di errno, il codice di errore al momento del fallimento, per sapere con certezza quale funzione ha fallito, ed evitare che un'altra funzione
    (come waitpid) lo sovrascriva durante la gestione dell'errore.*/
}

int main(int argc, char *argv[])
{
    signal(SIGCHLD, &sigchld_handler);

    // Dichiaro due variabili per la listening e connected socket.
    int listenfd, connfd;

    /*
        Dichiaro due variabili che conterrano l'indirizzo del server e del client.
        Sto usando struct sockaddr_storage che è definita in modo che:
        è piu' grande di qualunque struct sockaddr_XX,e possa essere facilmente
        convertita in un puntatore ad una qualsiasi struct sockaddr_xx.
    */
    struct sockaddr_storage myaddr, clientaddr; /*Il motivo per cui, a differenza degli altri casi, abbiamo creato uno storage per POI castarlo a sockaddr_in è
    che la struct storage ci permette di lavorare sia con indirizzi IPv4 che IPv6, creando quindi una socket che funziona indipendentemente dal protocollo.
    Questa è pratica comune quando si lavora con codice che dovrebbe funzionare indipendentemente dal protocollo IP specifico.*/

    in_port_t clientport;

    socklen_t myaddrlen;
    socklen_t clientaddrlen;

    char ipstr[INET6_ADDRSTRLEN]; // usiamo una costante per la lunghezza di un indirizzo IPv6 (altrimenti, INET_ADDRSTRLEN per IPv4)

    char buffer[BUFFER_SIZE];
    /*
        Si sarebbe potuto usare getaddrinfo(prende in input un host, come "http" o un numero di socket.
        Restituisce una lista di struct addrinfo contenenti info per connettersi a quell'host) per ottere un indirizzo IP appropriato: si noti che questa
        e' una estensione POSIX che deve essere esplicitamente abilitata in gcc.
        Per semplicita', cabliamo l'uso di 0.0.0.0 IPv4.
    */
    memset(&myaddr, 0, sizeof(myaddr));
    struct sockaddr_in *addrptr = (struct sockaddr_in *)&myaddr;
    /*Convertiamo il sockaddr_storage che rappresenta l'indirizzo del server(o il nostro indirizzo, in
    altre parole) in un sockaddr_in.*/
    addrptr->sin_family = AF_INET; // corrisponde al campo sin_family delle struct sockaddr_XX.
    inet_pton(addrptr->sin_family, "0.0.0.0", &addrptr->sin_addr);
    addrptr->sin_port = htons(PORT);
    myaddrlen = sizeof(struct sockaddr_in);

    /*
        Creo la socket. Si noti l'uso di SOCK_STREAM come tipo di socket,
        ovvero la semantica della comunicazione, nello specifico comunicazione
        orienta alla connessione, basata sul trafsferimento affidabile, bidirezionale
        di un flusso di byte. (In UDP avremo sock_dgram).

        Si noti che in questo momento la socket non ha ancora un indirizzo e non puo'
        inviare ne' ricevere dati.

        Nota: restituisce il file descriptor della socket, oppure -1 in caso di errore (dettagliato in errno).
    */
    if ((listenfd = socket(myaddr.ss_family, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /*
        Uso bind per associare alla socket un indirizzo locale (indirizzo IP e numero di porta).
    */
    if (bind(listenfd, (struct sockaddr *)&myaddr, myaddrlen) == -1)
    { /* restituisce 0 in caso di successo; -1 altrimenti */
        perror("bind");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    /*
        Preparo la socket per accettare connessioni. Il secondo argomento indica
        (correntemente) il numero di connessioni completamente stabilite per possono
        essere accodate in attesa di essere accettate dal server.

        Il valore del secondo argomento viene trocato se superiore a un valore massimo
        di sistema, che si può trovare qui: /proc/sys/net/core/somaxconn
    */
    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("listen");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        memset(&clientaddr, 0, sizeof(clientaddr));
        clientaddrlen = sizeof(clientaddr);

        /*
            Accetta una connessione in attesa sulla listening socket. Restituisce il file descriptor
            della socket connessa (al peer remoto), oppure -1 in caso di errore (dettagliato nella varibile errno)
        */
        if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen)) == -1)
        { /* accept si blocca finche' non c'è una connessione */
            perror("accept");
            continue; /* passa avanti e tenta di accettare una nuova connessione */
        }

        /* Converto l'indirizzo del client in stringa. Nota: non dovrebbero esserci errori*/
        if (clientaddr.ss_family == AF_INET)
        {
            inet_ntop(clientaddr.ss_family, &((struct sockaddr_in *)&clientaddr)->sin_addr, ipstr, sizeof(ipstr));
        }
        else
        {
            inet_ntop(clientaddr.ss_family, &((struct sockaddr_in6 *)&clientaddr)->sin6_addr, ipstr, sizeof(ipstr));
        }

        clientport = ntohs(clientaddr.ss_family == AF_INET ? ((struct sockaddr_in *)&clientaddr)->sin_port : ((struct sockaddr_in6 *)&clientaddr)->sin6_port);

        /* Stampa di debug */
        fprintf(stderr, "Accepted connection from: network address = %s ; port = %d\n",
                ipstr,
                clientport);

        pid_t child = fork();

        if (child == -1)
        { /* errore nella fork, passa avanti */
            perror("fork");
            close(connfd);
            continue;
        }
        else if (child == 0)
        {                    /* figlio! */
            close(listenfd); /* il figlio chiude la socket in ascolto */

            /* Echo server che reinvia i dati ricevuti! */
            while (1)
            {
                ssize_t nread = recv(connfd, &buffer, sizeof(buffer), 0);
                if (nread == -1)
                { /* restituisce il numero di byte letti oppure -1 in caso di errore*/
                    perror("recv");
                    break; /* esce dal ciclo infinito, in modo da raggiungere l'istruzione che chiude la connessione*/
                }

                if (nread == 0)
                {
                    break; // il client ha chiuso la connessione, quindi il sever esce dal ciclo e eventualmente chiudera' il suo lato
                }

                ssize_t nwritten = send(connfd, &buffer, nread, 0);
                if (nwritten == -1)
                { /* restituisce il numero di byte scritti oppure -1 in caso di errore*/
                    perror("send");
                    break; /* esce dal ciclo infinito, in modo da raggiungere l'istruzione che chiude la connessione*/
                }
            }

            fprintf(stderr, "Closing connection to: network address = %s ; port = %d\n",
                    ipstr,
                    clientport);

            if (close(connfd) == -1)
            {
                perror("close");
            }

            exit(EXIT_SUCCESS);
        }

        /* padre! */
        close(connfd); /* il padre chiude la socket connessa */
    }

    /* In realta' questa porizione di codice non viene mai eseguita! Per terminare il programma, bisogna killarlo */
    if (close(listenfd) == -1)
    {
        perror("listenfd close: ");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}