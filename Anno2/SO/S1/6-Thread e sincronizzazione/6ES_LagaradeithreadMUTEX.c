#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
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
pthread_mutex_t mutex; //Mutex per l'accesso al buffer.
pthread_cond_t condition; //condizione per la riattivazione del checker.
pthread_t writer1, writerminus1, checker; //rispettivi thread.

void sig_handler(int signo)
{
    if(signo = SIGINT)
    {
        printf ("Segnale ricevuto! Termino thread");
        pthread_exit(0);
    }
}


void insert_item(int val)
{
    int pos = rand() % 12; //genera una posizione casuale dove inserire il valore nel buffer.
    printf("Modificato il posto %d a valore %d \n", pos, val); //stampa quale valore è stato modificato.
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
    signal(SIGINT, sig_handler);
    while(TRUE)
    {
        pthread_mutex_lock(&mutex);
        insert_item(1);
        print_buffer();
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condition);
        sleep(rand() % 4);
    }
}

void *writeminus1(void *arg)
{
    signal(SIGINT, sig_handler);
    while(TRUE)
    {
        pthread_mutex_lock(&mutex);
        insert_item(-1);
        print_buffer();
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condition);
        sleep(rand() % 4);
    }
}

int buf_check()
{
    int i;
    for(i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void *check()
{
    int i, num_one, num_minusone;
    while(TRUE)
    {
        pthread_mutex_lock(&mutex);
        while(buf_check() == 0)
        {
            pthread_cond_wait(&condition, &mutex);
        }
        for(i = 0; i < BUFFER_SIZE; i++ )
        {
            if (buffer[i] == 1)
            {
                num_one++;
            }
            else
            {
                num_minusone++;
            }
        }

        {
            if(num_one>num_minusone)
            {
                printf("Ha vinto il thread degli 1, con %d 1 posizionati\n.", num_one);
            }
            else
            {
                printf("Ha vinto il thread dei -1, con %d -1 posizionati\n." , num_minusone);
            }
        pthread_kill(writer1, SIGINT);
        pthread_kill(writerminus1, SIGINT);
        }
    }
}

void main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&writer1, NULL, write1, NULL);
    pthread_create(&writerminus1, NULL, writeminus1, NULL);
    pthread_create(&checker, NULL, check, NULL);

    pthread_join(writer1, NULL);
    pthread_join(writerminus1, NULL);
    pthread_join(checker, NULL);

    pthread_cond_destroy(&condition);
    pthread_mutex_destroy(&mutex);
}
