#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t odd_child, even_child;
    int pipe1[2];
    int pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    srand(time(NULL));
    odd_child = fork();

    if (odd_child == 0)
    {
        close(pipe1[PIPE_RD]);
        close(pipe2[PIPE_WR]);
        while (1)
        {
            int rn = rand() % 101;
            if (rn % 2 != 0)
            {
                write(pipe1[PIPE_WR], &rn, sizeof(rn)); // Write prende in input puntatori
            }
        }
    }//NON CHIAMARE LA FORK nel contesto del figlio. Significherebbe che sia il padre che il figlio effettuano una fork. Indenta un else o un if(pid>0) per ritornare alla gestione del parent.
    else
    {
        even_child = fork();
        if (even_child == 0)
        {
            close(pipe1[PIPE_WR]);
            close(pipe2[PIPE_RD]);
            while (1)
            {
                int rn2 = rand() % 101;
                if (rn2 % 2 == 0)
                {
                    write(pipe2[PIPE_WR], &rn2, sizeof(rn2)); // Write prende puntatori
                }
            }
        }
        else
        {
            close(pipe1[PIPE_WR]);
            close(pipe2[PIPE_WR]);
            int buffer[2];
            int sum = 0;

            while (1)
            {
                read(pipe1[PIPE_RD], &buffer[0], sizeof(int));
                read(pipe2[PIPE_RD], &buffer[1], sizeof(int)); // Read prende puntatori
                sum = buffer[0] + buffer[1];
                if (sum < 190)
                {
                    printf("La somma è %d. Processi non terminati\n", sum);
                }
                else
                {
                    printf("La somma è %d. Terminerò i processi\n", sum);
                    kill(odd_child, SIGTERM);//Oss: non ci sono differenze salienti con SIGKILL in termini di segnali di terminazione. Sarà rilevante solo al momento della gestione degli eventi, in quanto ovviamente segnali diversi.
                    kill(even_child, SIGTERM); // Utilizzo di SIGTERM per terminazione controllata
                    exit(0);
                }
            }
        }
    }

    return 0;
}
