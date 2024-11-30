/*

Generare due processi figli che comunicano con il padre.

    Uno dei processi genera numeri casuali [0-50] ed invia al padre solo i numeri multipli di 3.
    L'altro processo genera numeri casuali [51-100] ed invia al padre solo i numeri multipli di 2.
    Il padre stampa i numeri ricevuti ed esegue la loro somma quando la somma > 130.

*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>


#define true 1
#define false 0
#define PIPE_RD 0
#define PIPE_WR 1

int pipe1[2], pipe2[2];
pid_t child1, child2;

int main()
{
    srand(time(NULL));
    if(pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("Errore creazione pipe!");
        exit(1);
    }

    child1 = fork();
    if(child1 == 0)
    {
        while(true)
        {
            int rn_value = rand() % 51;
            if(rn_value % 3 == 0)
            {
                close(pipe1[PIPE_RD]);
                write(pipe1[PIPE_WR], &rn_value, sizeof(rn_value));
            }
        }
    }
    else
    {
        child2 = fork();
        if(child2 == 0)
        {
            while(true)
                {
                    int rn_value = (rand() % 51) + 50;
                    if(rn_value % 2 == 0)
                    {
                        close(pipe2[PIPE_RD]);
                        write(pipe2[PIPE_WR], &rn_value, sizeof(rn_value));
                    }
                }
        }
        else
        {
            while(1)
            {
                int buf1 = 0;
                int buf2 = 0;
                close(pipe1[PIPE_WR]);
                close(pipe2[PIPE_WR]);
                read(pipe1[PIPE_RD], &buf1, sizeof(int));
                read(pipe2[PIPE_RD], &buf2, sizeof(int));
                int sum = buf1 + buf2;
                if(sum > 130)
                {
                    printf("Numero ricevuto da child1: %d\n", buf1);
                    printf("Numero ricevuto da child2: %d\n", buf2);
                    printf("E la loro somma è: %d\n", sum);
                }

            }
        }
    }
    return 0;
}
