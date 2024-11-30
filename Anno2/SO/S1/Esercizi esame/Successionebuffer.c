/*

Si scriva un programma con tre thread che risolvono il seguente problema: Un buffer di n elementi inizializzato con a -1 viene riempito nel seguente modo:

    Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
    Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
    Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
    buff[0] = buff[0]; buff[1] = buff[1] + buff[0]; buff[2] = buff[1] + buff[2]. Si proponga una soluzione di mutua esclusione.

*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>

#define True 1
#define False 0
#define BUF_SIZE 10

pthread_t add_even, add_odd, buffer_mod;
pthread_mutex_t mutex;
int buffer[BUF_SIZE] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void print_buffer(int *buffer)
{
    int i;
    printf("Stato attuale del buffer: \n");
    for(i = 0; i < BUF_SIZE; i++)
    {
        printf(" %d ", buffer[i]);
    }
    printf("\n");
}

void insert_value(int *buffer, int val, int pos)
{
    buffer[pos] = val;
    printf("Ho inserito %d in posizione %d\n", val, pos);
}


void *insert_even()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        int value = rand() % 101;
        int position = (rand() % 5) * 2;
        insert_value(buffer, value, position);
        print_buffer(buffer);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

void *insert_odd()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        int value = (rand() % 101) * 2;
        int position = (((rand() % 5) *2) + 1);
        insert_value(buffer, value, position);
        print_buffer(buffer);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

void *modify_start_pos()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        buffer[1] = buffer[1] + buffer[0];
        buffer[2] = buffer[1] + buffer[2];
        printf("Ho modificato buffer[1] a %d e buffer[2] a %d\n", buffer[1], buffer[2]);
        print_buffer(buffer);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}


int main()
{
    srand(time(NULL));
    int mut = pthread_mutex_init(&mutex, NULL);

    if(mut == -1)
    {
        perror("Errore creazione mutex");
        exit(1);
    }

    int t1 = pthread_create(&add_even, NULL, insert_even, NULL);
    int t2 = pthread_create(&add_odd, NULL, insert_odd, NULL);
    int t3 = pthread_create(&buffer_mod, NULL, modify_start_pos, NULL);
    if(t1 == -1 || t2 == -1 || t3 == -1)
    {
        perror("Errore creazione thread");
        exit(1);
    }

    pthread_join(add_even, NULL);
    pthread_join(add_odd, NULL);
    pthread_join(buffer_mod, NULL);

    pthread_mutex_destroy(&mutex);
}
