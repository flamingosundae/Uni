#include <netinet/in.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>

char *capitalizator(char *in);

char *capitalizator(char *in)
{
    int n = strlen(in);
    int i;
    for(i = 0; i < n; i++)
    {
        in[i] = in[i] + 'a';
    }
    return in;
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd == -1)
    {
        perror("Errore creazione socket.");
        exit(1);
    }

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(7000);

    int rv = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(rv == -1)
    {
        perror("bind");
        close(sockfd);
        exit(1);
    }

    while(1)
    {
        char input[1024]; // Buffer per ricevere il messaggio dal client
        socklen_t client_len = sizeof(client_addr); // Dimensione della struttura client_addr

        ssize_t read_count = recvfrom(sockfd, input, sizeof(input), 0, (struct sockaddr*)&client_addr, &client_len);
        if(read_count == -1)
        {
            perror("recvfrom");
            close(sockfd);
            exit(1);
        }

        input[read_count] = '\0'; // Assicurati che la stringa ricevuta sia terminata correttamente

        char *res = capitalizator(input);

        ssize_t write_count = sendto(sockfd, res, strlen(res) + 1, 0, (struct sockaddr*)&client_addr, client_len);
        if(write_count == -1)
        {
            perror("sendto");
            close(sockfd);
            exit(1);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
