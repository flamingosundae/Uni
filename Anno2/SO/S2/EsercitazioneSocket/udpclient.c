#include <stdlib.h>
#include <sys/types.h>     
#include <sys/socket.h>    /* per struct setsockopt */
#include <errno.h>
#include <stdio.h>    /* per scanf */
#include <sys/time.h> /* per struct timeval */
#include <unistd.h>
#include <string.h>   /* per memcmp */
#include <arpa/inet.h> 

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    /*Nota una differenza fondamentale: sockaddr_in definisce le informazioni di INDIRIZZO per la socket(numero di porta, famiglia di IP, IP di origine). 
    Descrive basilarmente i campi di intestazione della socket, senza essere una socket. D'altro canto, la funzione socket restituisce una socket GIÀ creata.*/

    /*Nota, inoltre, i parametri di socket:
    1)Specifica la famiglia di indirizzi IP. Già visti con AF_INET e AF_INET6.
    2)Specifica il tipo di socket: raw, stream o datagram? SOCK_DGRAM è solitamente usata per la definizione di socket UDP.
    3)Specifica il protocollo della socket: IPPROTO_TCP/UDP/SCTP forniscono, appunto, TCP/UDP/SCTP. Se lasciato 0 l'OS sceglie automaticamente.*/
    if (sockfd == -1) {
        perror("Errore nella creazione della socket"); //Classico meccanismo di controllo visto già anche con i thread. Se il descrittore è -1, ha fallito.
        exit(EXIT_FAILURE);
    }

    /* Indica un intervallo di tempo come numero di secondi piu' un certo numero di microsecondi (sempre inferiore a 1 milione)*/
    struct timeval timeout;      
    timeout.tv_sec = 60;
    timeout.tv_usec = 0;
    /*È l'intervallo di tempo per la ricezione prima che il pacchetto sia considerato perso. Vedi RDT 2.2 sul libro.*/

    /* 
        Imposta l'ozione (a livello di socket) per il timeout di ricezione.
        Restituisce 0 in caso di successo, -1 in caso di errore.
    */
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("Errore nella impostazione del timeout di ricezione");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    /*Parametrizzazione:
    1)Descrittore della socket che abbiamo già creato con socket().
    2)Livello su cui l'opzione è applicata. In questo caso applichiamo a livello socket, ma ci sono anche opzioni proprie al TCP (e useremmo IPPROTO_TCP) così come 
    per IP (e useremmo IPPROTO_IP).
    3)Specifica l'opzione per il timeout usata. Usando, per esempio SO_SNDTIMEO, avremmo usato il timer per il timeout di invio(e la ritrasmissione di pacchetto).

    /* Indirizzo del server. Si noti l'uso di INADDR_LOOPBACK (cioe' 127.0.0.1), usato per comunicare sulla stessa macchina */
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(7000);

    printf("Primo operando: ");
    int first_operand;
    scanf("%d", &first_operand);

    printf("Secondo operando: ");
    int second_operand;
    scanf("%d", &second_operand);


    uint32_t input[] = { htonl(first_operand), htonl(second_operand) }; /* converto entrami gli operandi in network byte order (BE)*/

    ssize_t write_count = sendto(sockfd, &input, sizeof(input), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (write_count == -1) {
        perror("Impossibile inviare la richiesta al server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in replier_addr;
    socklen_t replier_addr_len = sizeof(replier_addr);
    memset(&replier_addr, 0, sizeof(replier_addr));

    uint32_t sum;

    while (1) { /* cicla finche' non riceve un messaggio dal server oppure si verifica un errore (incluso il timeout) */
        ssize_t read_count = recvfrom(sockfd, &sum, sizeof(sum), 0, (struct sockaddr *)&replier_addr, &replier_addr_len); //Non dovremmo ricevere da server_addr?
        /*Parametrizzazione:
        1)Descrive la socket da cui vogliamo ricevere dati. Abbiamo già definito la socket, come menzionato.
        2)Buffer su cui andremo a scrivere il messaggio ricevuto.
        3)Grandezza prevista del messaggio. 
        4)Flag per modificare il comportamento di ricezione. Con 0 non ne viene impostata nessuna.
        5)Indirizzo del mittente previsto.
        6)Dimensione della struct dell'indirizzo.*/


        if (read_count == -1) {
            perror("Impossibile ricevere la risposta dal server");
            close(sockfd);
            exit(EXIT_FAILURE);
        } 
        
        if (read_count != sizeof(sum)) {
            fprintf(stderr, "Attesi %ld byte ma letti %ld\n", sizeof(sum), read_count);
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        /* Verifica che l'indirizzo del mittente della risposta sia il server, usando la funzione memcmp per un confronto byte a byte */
        if (replier_addr_len != sizeof(replier_addr) || memcmp(&replier_addr, &server_addr, sizeof(replier_addr)) != 0) {
            fprintf(stderr, "Ignora messaggio in ingresso non proveniente dal server");
            continue;
        } else {
            break;
        }
    }

    close(sockfd); /* Chiude la socket */

    sum = ntohl(sum); /* Converte il risultato dal byte order di rete a quello dell'host */

    printf("%d + %d = %d\n", first_operand, second_operand, sum);


    return EXIT_SUCCESS;
}
/*Quindi, in soldoni, cosa fa il programma:
1)Crea una socket, che riempiremo con i dati del server.
2)Definisce la struct per i campi della socket server. Nota che inseriamo, nel campo address, (INADRR_LOOPBACK), che è 127.0.0.1 e corrisponde alla macchina stessa.
3)Definiamo l'input dei due numeri da sommare e li mettiamo in un array in formato htonl.
4)Mandiamo l'input alla socket server.
5)Riceviamo l'out con rcvfrom(da replier_addr che comunque fa parte dell'host server. Ci serve per non sovrascrivere la variabile dell'addr destinatario
al momento in cui otteniamo la somma, e se tecnicamente l'host è lo stesso server_addr e receiver addr_coincideranno).
6)Scriviamo la somma.*/