#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>


int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd == -1)
    {
        perror("Errore creazione socket.");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = 60;
    timeout.tv_usec = 0;

    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1)
    {
        perror("Errore assegnazione timer.");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(7000);

    printf("Parola da capitalizzare: ");
    char target_word[1024]; // Buffer per la parola da inserire
    fgets(target_word, sizeof(target_word), stdin);
    
    ssize_t write_count = sendto(sockfd, target_word, strlen(target_word), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(write_count == -1)
    {
        perror("Errore nell'invio dei dati.");
        close(sockfd);
        exit(1);
    }

    char res[1024]; // Buffer per la risposta
    ssize_t read_count = recvfrom(sockfd, res, sizeof(res), 0, NULL, NULL);
    if(read_count == -1)
    {
        perror("Errore nella ricezione dei dati.");
        close(sockfd);
        exit(1);
    }
    else
    {
        res[read_count] = '\0'; // Assicurati che la stringa ricevuta sia terminata correttamente
        printf("La stringa ora capitalizzata è: %s\n", res);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
