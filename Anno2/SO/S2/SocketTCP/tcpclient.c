#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#define PORT 5000
#define BUFFERSIZE 1000

char buffer[BUFFERSIZE];

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;    
    inet_pton(serveraddr.sin_family, "127.0.0.1", &serveraddr.sin_addr);
    /*Reminder: inet_pton fa parte della libreria arpa_inet, e converte un indirizzo dalla forma leggibile alla rappresentazione binaria per l'uso da parte del network.
    Parametrizzazione:
    1)Specifica la famiglia di indirizzi usata(e quindi il formato di conversione).
    2)Specifica l'indirizzo in formato presentation, come char[]. Ricorda che 127.0.0.1 è la convenzione per la comunicazione con la stessa macchina.
    3)Specifica dove salvare l'indirizzo in formato network. */
    serveraddr.sin_port = htons(PORT);

    if (((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) == -1) {
        perror("socket"); /*Check di errore per la creazione della socket. */
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect"); /*Check di errore per l'associazione al server come destinatario predefinito.*/ 
        close(sockfd); 
        exit(EXIT_FAILURE);
    }

    memset(&buffer, 0, sizeof(buffer)); /*Impostiamo ogni cella del buffer a 0.*/

    if (fgets((char *)&buffer, sizeof(buffer), stdin)) {
        if (send(sockfd, &buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    /*Questo è un processo in due fasi. Prima invochiamo fgets, che permette di leggere da un input e depositare il contenuto in un'area di memoria.
    Parametrizzazione:
    1)Dove verrà depositato il contenuto letto dall'input. Nota che fgets restituisce un puntatore, indipercui la conversione del buffer originariamente statico.
    2)Quanti dati potrà leggere al massimo.
    3)L'input. Con stdin, legge da tastiera.
    Una volta letto da tastiera e scritto il contenuto su buffer, dunque, il risulrato viene mandato al server, con annesso controllo di errore.*/


        shutdown(sockfd, SHUT_WR);
        /*Shutdown() disabilita la comunicazione con la socket indicata dal descrittore del primo parametro. In particolare, il secondo parametro specifica la modalità.
        SHUT_RD: disabilita ulteriore ricezione di dati dalla socket interessata.
        SHUT_WR: disabilita ulteriore invio di dati alla socket.
        SHUT_RDWR: fa entrambi insieme.*/

        ssize_t nread;
        while ((nread = recv(sockfd, &buffer, sizeof(buffer), 0)) > 0) {
            write(STDOUT_FILENO, buffer, nread);
        }
        /*Hai già visto rcv, non ci sono differenze eccezionali.
        Tuttavia, nota due cose:
        A)Questa volta cè un ciclo while, il che vuol dire che la socket client continuerà a predisporsi per la ricezione di dati fin quando
        il numero di byte letti è maggiore di 0(memorizzato in nread), implicando che possano esserci altri possibili dati da ricevere.
        B)L'uso di STDOUT_FILENO, che è il descriptor dell'out standard.*/
        if (nread == -1) {
            perror("recv");
            close(sockfd);
            exit(EXIT_FAILURE);

        }
    }
    
    fsync(STDOUT_FILENO); /*Controlla la corretta, totale e coerente scrittura su disco di tutti i dati ricevuti nel buffer. Per STDOUT come sopra.*/

    close(sockfd);

    return EXIT_SUCCESS;

}