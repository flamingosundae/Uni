#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
#define BUFFER_SIZE 11
#define TRUE 1
#define FALSE 0
/*Scrivere un programma C che segue le seguenti specifiche.
Il processo eseguito, inizialmente crea un buffer come array di 11 numeri interi, inizializzati a zero. In seguito genera tre thread utilizzando le librerie POSIX secondo le seguenti specifiche:
•  Il primo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero +1, qualsiasi sia il valore presente nella cella.
•  Il secondo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero -1, qualsiasi sia il valore presente nella cella.
•  Il terzo thread in un ciclo infinito controlla se tutte le celle del buffer sono state inizializzate ad un valore diverso da 0. In caso positivo, determina se il numero di celle contenenti un valore pari a +1 è maggiore di quelle con -1 e termina tutti e tre i thread.
•  Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi.
•  Una volta che un thread ha acceduto in lettura o scrittura al buffer, deve attendere un numero di secondi random tra 0 e 3*/

int buffer[BUFFER_SIZE] = {0}; //Inizializza un buffer di soli 0.
int cond = 0; //Condizione di terminazione del checker. Una volta reso 1, vuol dire che c'è un stato riscontro positivo e tutti i thread devono terminare.
sem_t mutex; //semaforo per l'accesso al buffer.

void down(sem_t *sem)
{
    sem_wait(sem);
}

void up(sem_t *sem)
{
    sem_post(sem);
}


void insert_item(int val)
{
    int pos = rand() % 12; //genera una posizione casuale dove inserire il valore nel buffer.
    printf("Modificato il posto %d a valore %d \n", pos+1, val); //stampa quale valore è stato modificato.
    buffer[pos] = val;
}

void print_buffer()
{
    int i;
    printf("Stato buffer:");
    for(i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d", buffer[i]);
    }
    printf("\n");
}

void *write1(void *arg)
{
    while(TRUE)
    {
        if(cond == 1)
        {
            pthread_exit(0);
        }
        down(&mutex);
        insert_item(1);
        print_buffer();
        up(&mutex);
        sleep(rand() % 4);
    }
}

void *writeminus1(void *arg)
{
    while(TRUE)
    {
        if(cond == 1)
        {
            pthread_exit(0);
        }
        down(&mutex);
        insert_item(-1);
        print_buffer();
        up(&mutex);
        sleep(rand() % 4);
    }
}

void *buf_checker(void *arg)
{
    while(TRUE)
    {
        down(&mutex);
        int is_done = TRUE;
        int i;
        int num_one = 0;
        int num_minusone = 0;
        for(i = 0; i < BUFFER_SIZE; i++ )
        {
            if(buffer[i] == 0)
            {
                is_done = FALSE;
            }
            else if(buffer[i] == 1)
            {
                num_one++;
            }
            else
            {
                num_minusone++;
            }
        }
        if(is_done == TRUE)
        {
            if(num_one>num_minusone)
            {
                printf("Ha vinto il thread degli 1, con %d 1 posizionati\n.", num_one);
            }
            else
            {
                printf("Ha vinto il thread dei -1, con %d -1 posizionati\n." , num_minusone);
            }
            cond = 1;
            up(&mutex);
            pthread_exit(0);
        }
        up(&mutex);
        sleep(rand() % 4);
    }

}

void main()
{
    pthread_t writer1, writerminus1, checker;
    sem_init(&mutex, 0, 1);
    pthread_create(&writer1, NULL, write1, NULL);
    pthread_create(&writerminus1, NULL, writeminus1, NULL);
    pthread_create(&checker, NULL, buf_checker, NULL);

    pthread_join(writer1, NULL);
    pthread_join(writerminus1, NULL);
    pthread_join(checker, NULL);

    sem_destroy(&mutex);
}
