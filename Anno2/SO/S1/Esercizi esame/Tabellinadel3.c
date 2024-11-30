#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <fcntl.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define PERM 0600

pid_t child;
int pipe1[2];
char buf[10];
char endline = '\n';

void USR1_catcher(int signal)
{
    if (signal == SIGUSR1)
    {
        printf("Conferma ricevuta dal figlio.\n");
    }
}

int main()
{
    int tab = creat("tab3.txt", PERM);
    pipe(pipe1);  // Inizializza la pipe

    child = fork();

    if (child == 0)
    {
        while (1)
        {
            close(pipe1[PIPE_WR]);
            read(pipe1[PIPE_RD], &buf, sizeof(char)*10);
            tab = open("tab3.txt", O_RDWR | O_APPEND);
            write(tab, &buf, sizeof(buf));
            write(tab, &endline, sizeof(endline));
            close(tab);
            kill(getppid(), SIGUSR1);
        }
    }
    else
    {
        signal(SIGUSR1, USR1_catcher);
        int j = 0;
        int i = 0;
        char val[10];
        while (1)
        {
            if (j == 11)
            {
                kill(child, SIGTERM);
                exit(0);
            }

            sprintf(val, "%d", i);
            close(pipe1[PIPE_RD]);
            write(pipe1[PIPE_WR], &val, sizeof(char)*10);
            j++;
            i = 3 * j;
            pause();
        }
    }
    return 0;
}

