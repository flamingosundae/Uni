#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
/*Si scriva un programma C per ambiente Unix tale che venga emulata una
struttura di processi organizzati master-slave; si supponga di dover gestire 3 slave.
Ogni slave deve mandare un segnale di tipo SIGUSR1 al master; tale messaggio può
essere mandato solo previa autorizzazione del master mediante un segnale di tipo
SIGUSR2. Quando il master ha ricevuto tutti e tre i messaggi, uccide gli slave con un
messaggio di tipo SIGKILL.
La logica del programma è la seguente:
a) Ogni slave deve inviare la master un segnale di tipo sigusr1(sincronizzazione)
b) Tale messaggio può essere inviato solo dopo che il master ha autorizzato lo slave
tramite un segnale di tipo sigusr2 (sincronizzazione)
c) Quando il master ha ricevuto tutti e tre i messaggi, uccide (cioè fa terminare ) i tre
processi slave (da lui generati !!!), tramite un segnale di di tipo sigkill*/


pid_t slave1, slave2, slave3;
int kill_counter = 0;


void slave_response(int signo)
{
    if (signo == SIGUSR2)
    {
        printf("Sono un processo slave e ho recepito un SIGUSR2\n");
        kill(getppid(), SIGUSR1);
    }
}

void master_response(int signo)
{
    if(signo = SIGUSR1)
    {
        printf("Sono il processo master e ho recepito un SIGUSR1\n ");
        kill_counter++;
    }
}

void main()
{

    slave1 = fork();

    if(slave1 == 0)
    {
        signal(SIGUSR2, slave_response);
        pause();
    }
    else
    {
        slave2 = fork();
        if(slave2 == 0)
        {
            signal(SIGUSR2, slave_response);
            pause();
        }
        else
        {
            slave3 = fork();
            if(slave3 == 0)
            {
                signal(SIGUSR2, slave_response);
                pause();
            }
            else
            {
                signal(SIGUSR1, master_response);
                kill(slave1, SIGUSR2);
                pause();
                kill(slave2, SIGUSR2);
                pause();
                kill(slave3, SIGUSR2);
                pause();
                if(kill_counter == 3)
                {
                    kill(slave1, SIGTERM);
                    kill(slave2, SIGTERM);
                    kill(slave3, SIGTERM);
                    exit(0);
                }

            }
        }
    }
}
