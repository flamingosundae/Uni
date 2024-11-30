/*

Scrivere un programma C che segue le seguenti specifiche. Il processo eseguito, inizialmente crea un buffer come array di 11 numeri interi, inizializzati a zero. In seguito genera tre thread utilizzando le librerie POSIX secondo le seguenti specifiche:

    Il primo thread sceglie casualmente una cella del buffer e vi scrive il numero +1, qualsiasi sia il valore presente nella cella.
    Il secondo thread sceglie casualmente una cella del buffer e vi scrive il numero -1, qualsiasi sia il valore presente nella cella.
    Il terzo thread controlla se tutte le celle del buffer sono state inizializzate. In caso positivo, determina se il numero di celle contententi un valore pari a +1 è maggiore di quelle con -1 e termina tutti e tre i thread. Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi. Una volta che un thread ha acceduto in lettura o scrittura al buffer, deve attendere un numero di secondi random tra 0 e 3

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define True 1
#define False 0


pthread_t writer1, writerminus1, checker;
pthread_mutex_t mutex;
pthread_cond_t condcheck;
int buf[11] = {0};

void print_buffer(int *buffer, int buffer_size)
{
    int i;
    printf("Stato attuale del buffer:\n");
    for(i = 0; i < buffer_size; i++)
    {
        printf(" %d ", buffer[i]);
    }
    printf("\n");
}

void insert_item(int *buffer, int value)
{
    int pos = rand() % 11;
    buffer[pos] = value;
    printf("Ho inserito %d nella posizione %d\n", value, pos);
}

int buffer_check(int *buffer, int buffer_size)
{
    int i;
    for(i = 0; i < buffer_size; i++)
    {
        if(buffer[i] == 0)
        {
            return False;
        }
    }
     printf("Buffer riempito.\n");
     return True;
}

void *insert_1()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        insert_item(buf, 1);
        print_buffer(buf, 11);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condcheck);
        sleep(rand() % 4);
    }
}

void *insert_minus1()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        insert_item(buf, -1);
        print_buffer(buf, 11);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condcheck);
        sleep(rand() % 4);
    }
}

void *buf_checker()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        while(buffer_check(buf, 11) == 0)
        {
            pthread_cond_wait(&condcheck, &mutex);
            sleep(rand() % 4);
        }
        int i;
        int count_one = 0;
        int count_minusone = 0;
        for(i = 0; i < 11; i++)
        {
            if(buf[i] == 1)
            {
                count_one++;
            }
            else
            {
                count_minusone++;
            }
        }
        printf("Buffer inizializzato completamente, con %d 1 e %d -1.\n", count_one, count_minusone);
        kill(writer1, SIGTERM);
        kill(writerminus1, SIGTERM);
        exit(0);
    }
}


int main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condcheck, NULL);

    int t1 = pthread_create(&writer1, NULL, insert_1, NULL);
    int t2 = pthread_create(&writerminus1, NULL, insert_minus1, NULL);
    int t3 = pthread_create(&checker, NULL, buf_checker, NULL);
    if(t1 == -1 || t2 == -1 || t3 == -1)
    {
        perror("Errore creazione thread.\n");
        exit(1);
    }

    pthread_join(writer1, NULL);
    pthread_join(writerminus1, NULL);
    pthread_join(checker, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condcheck);

    return 0;

}

