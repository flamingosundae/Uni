/*


Scrivere un programma C che svolge le seguenti richieste:

    Un processo padre genera due processi figli. Ciascun processo inizializza un proprio array di N interi.
    Il primo processo invia al processo padre solo i numeri in posizioni pari, e il secondo processo solo i numeri in posizioni dispari.
    Il padre riceve questi numeri e li scrive in un array di N interi, mettendo il posizioni pari i numeri ricevuti dal primo figlio, e in posizioni dispari i numeri ricevuti dal secondo filgio.
    Il padre stampa l'array e calcola il max e il min.

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <time.h>

#define PIPE_WR 1
#define PIPE_RD 0
#define BUF_SIZE 10

int pipe1[2], pipe2[2];
pid_t child1, child2;

void print_buffer(int *buf, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d  ", buf[i]);
    }
    printf("\n");
}

int calc_max_buffer(int *buf, int size)
{
    int max = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        if(buf[i] > max)
        {
            max = buf[i];
        }
    }
    printf("Il massimo nel buffer è %d \n", max);
    return max;
}

int calc_min_buffer(int *buf, int size)
{
    int min;
    int i;
    min = buf[0];
    for(i = 0; i < size; i++)
    {
        if(buf[i] < min)
        {
            min = buf[i];
        }
    }
    printf("Il minimo nel buffer è %d \n", min);
    return min;
}

int main()
{
    srand(time(NULL));
    if(pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("Errore nella creazione delle pipe.");
        exit(1);
    }

    child1 = fork();
    if(child1 == 0)
    {
        int i;
        int j;
        int k = 0;
        int buf[BUF_SIZE];
        int even_buf[BUF_SIZE/2];

        for(i = 0; i < BUF_SIZE; i++)
        {
            buf[i] = rand() % 100;
        }
        print_buffer(buf, BUF_SIZE);

        for(j = 0; j < BUF_SIZE/2; j++)
        {
            even_buf[j] = buf[k];
            k += 2;
        }
        print_buffer(even_buf, BUF_SIZE/2);
        close(pipe1[PIPE_RD]);
        write(pipe1[PIPE_WR], &even_buf, sizeof(even_buf));
    }
    else
    {
        child2 = fork();
        if(child2 == 0)
        {
            int i;
            int j;
            int k = 1;
            int buf[BUF_SIZE];
            int odd_buf[BUF_SIZE/2];

            for(i = 0; i < BUF_SIZE; i++)
            {
                buf[i] = rand() % 100;
            }
            print_buffer(buf, BUF_SIZE);

            for(j = 0; j < BUF_SIZE/2; j++)
            {
                odd_buf[j] = buf[k];
                k += 2;
            }
            print_buffer(odd_buf, BUF_SIZE/2);
            close(pipe2[PIPE_RD]);
            write(pipe2[PIPE_WR], &odd_buf, sizeof(odd_buf));
        }
        else
        {
            int ev_nums[BUF_SIZE/2];
            int odd_nums[BUF_SIZE/2];
            int buf[BUF_SIZE];
            int i;
            int j = 0;
            close(pipe1[PIPE_WR]);
            close(pipe2[PIPE_WR]);
            read(pipe1[PIPE_RD], &ev_nums, sizeof(ev_nums));
            read(pipe2[PIPE_RD], &odd_nums, sizeof(odd_nums));
            for(i = 0; i < BUF_SIZE; i += 2)
            {
                buf[i] = ev_nums[j];
                j++;
            }
            j = 0;
            for(i = 1; i < BUF_SIZE; i += 2)
            {
                buf[i] = odd_nums[j];
                j++;
            }

            print_buffer(buf, BUF_SIZE);
            calc_max_buffer(buf, BUF_SIZE);
            calc_min_buffer(buf, BUF_SIZE);
        }
    }
    return 0;
}
