/* Il processo eseguito inizialmente crea come buffer un array di 11 interi, inizializzati a 0.
 In seguito verranno generati 2 figli secondo le seguenti specifiche.
 Il primo processo sceglie casualmente una cella del buffer e la invia al padre. Il padre modifica quella posizione a 1.
 Il secondo fa lo stesso, ma modifica a -1. Dopo ogni scrittura, ci sono tra 0 e 3 secondi di sleep.
 Dopo ogni modifica, il padre controlla se ci sono ancora degli 0. In caso affermativo conta gli 1 e -1, stampa il risultato
 e termina i processi. */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define True 1
#define False 0
#define buf_size 11

int check_buffer(int *buffer, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if (buffer[i] == 0)
        {
            return False;
        }
    }
    return True;
}

void print_buffer(int *buffer, int n)
{
    int i;
    printf("Stato attuale del buffer: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d", buffer[i]);
    }
    printf("\n");
}


int main()
{
    pid_t pos_child, neg_child;
    int pipe1[2], pipe2[2];
    srand(time(NULL));
    int sleep_time = rand() % 4;

    if(pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        printf("Errore creazione pipe!");
        exit(1);
    }

    pos_child = fork();
    if(pos_child == 0)
    {
        while(True)
            {
                int rand_pos_space = rand() % 12;
                close(pipe1[PIPE_RD]);
                write(pipe1[PIPE_WR], &rand_pos_space, sizeof(rand_pos_space));
                sleep(sleep_time);
            }
    }
    else
    {
        neg_child = fork();
        if (neg_child == 0)
        {
            while(True)
            {
                int rand_neg_space = rand() & 12;
                close(pipe2[PIPE_RD]);
                write(pipe2[PIPE_WR], &rand_neg_space, sizeof(rand_neg_space));
                sleep(sleep_time);
            }
        }
        else
        {
            int buffer[buf_size];
            int pipe_buffer[2];

            while(True)
            {
                close(pipe1[PIPE_WR]);
                close(pipe2[PIPE_WR]);

                read(pipe1[PIPE_RD], &pipe_buffer[0], sizeof(int));
                read(pipe2[PIPE_RD], &pipe_buffer[1], sizeof(int));

                buffer[pipe_buffer[0]] = 1;
                buffer[pipe_buffer[1]] = -1;

                print_buffer(buffer, buf_size);
                if(check_buffer(buffer, buf_size) == True)
                {
                    kill(pos_child, SIGTERM);
                    kill(neg_child, SIGTERM);
                    printf("Buffer riempito.");
                    print_buffer(buffer, buf_size);
                    exit(0);
                }
            }

        }
    }
    return 0;
}
