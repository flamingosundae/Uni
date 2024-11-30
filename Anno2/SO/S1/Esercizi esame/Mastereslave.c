/*Si scriva un programma C per ambiente Unix tale che venga emulata una
struttura di processi organizzati master-slave; si supponga di dover gestire 3 slave.
Ogni slave deve mandare un segnale di tipo SIGUSR1 al master; tale messaggio può
essere mandato solo previa autorizzazione del master mediante un segnale di tipo
SIGUSR2. Quando il master ha ricevuto tutti e tre i messaggi, uccide gli slave con un
messaggio di tipo SIGKILL. */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <time.h>

pid_t slave1, slave2, slave3;
int sig_count = 0;

void USR2_catcher(int signal)
{
    if(signal == SIGUSR2)
    {
        kill(getppid(), SIGUSR1);
    }
}

void USR1_catcher(int signal)
{
    if(signal == SIGUSR1)
    {
        sig_count++;
        printf("Numero di risposte ricevute: %d \n", sig_count);
    }
}

int main()
{
    slave1 = fork();

    if(slave1 == 0)
    {
        signal(SIGUSR2, USR2_catcher);
        while(1)
        {
        pause();
        }
    }
    else
    {
        slave2 = fork();
        if(slave2 == 0)
        {
            signal(SIGUSR2, USR2_catcher);
            while(1)
            {
            pause();
            }
        }
        else
        {
            slave3 = fork();
            if(slave3 == 0)
            {
                signal(SIGUSR2, USR2_catcher);
                while(1)
                {
                    pause();
                }
            }
            else
            {
                signal(SIGUSR1, USR1_catcher);
                    while(1)
                    {
                        kill(slave1, SIGUSR2);
                        kill(slave2, SIGUSR2);
                        kill(slave3, SIGUSR2);
                        pause();
                        if(sig_count == 3)
                        {
                            printf("Ricevuta conferma da ogni slave. Avvio terminazione");
                            kill(slave1, SIGKILL);
                            kill(slave2, SIGKILL);
                            kill(slave3, SIGKILL);
                            exit(0);
                        }
                    }
                }

            }
        }
    return 0;
}







