/*
 *

    Scrivere un programma in C con tre thread che operano su due array di dimensione N inizialmente a 0.
    Il primo thread scrive in un array A numeri casuali tra 1 e 150, scrivendo un numero per volta in posizioni randomiche.
    Il secondo thread scrive in un array B numeri cassuali tra 150 e 300, scrivendo un numero per volta in posizioni randomiche.
    Il terzo thread controlla se entrambi gli array sono stati inizializzati, in caso affermativo calcola il massimo in A e in B, calcola il minimo in A e in B. Infine determina il max{max(A), max(B)} e il min{min(A), min(B)}.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <time.h>

#define True 1
#define False 0
#define BUF_SIZE 10

int bufA[10] = {0};
int bufB[10] = {0};

pthread_t AModder, BModder, checker;
pthread_mutex_t mutex;
pthread_cond_t condcheck;

void print_buffer(int *buffer, char buffer_id)
{
    int i;
    printf("Stato attuale del buffer %c:\n", buffer_id);
    for(i = 0; i < BUF_SIZE; i++)
    {
        printf(" %d ", buffer[i]);
    }
    printf("\n");
}

void insert_item(int *buffer, int value, char buffer_id)
{
    int pos = rand() % 10;
    buffer[pos] = value;
    printf("Ho inserito %d nella posizione %d del buffer %c\n", value, pos, buffer_id);
}


int buffer_checker(int *buffer, char buffer_id)
{
    int i;
    for(i = 0; i < BUF_SIZE; i++)
    {
        if(buffer[i] == 0)
        {
            return False;
        }
    }
    printf("Buffer %c inizializzato completamente.\n", buffer_id);
    return True;
}


void *AMod()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        int val = (rand() % 150) + 1;
        insert_item(bufA, val, 'A');
        print_buffer(bufA, 'A');
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condcheck);
        sleep(rand() % 4);
    }
}

void *BMod()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        int val = (rand() % 151) + 150;
        insert_item(bufB, val, 'B');
        print_buffer(bufB, 'B');
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condcheck);
        sleep(rand() % 4);
    }
}

int calc_max(int *buffer, int buf_size)
{
    int max = 0;
    int i;
    for(i = 0; i < buf_size; i++)
    {
        if (buffer[i] > max)
        {
            max = buffer[i];
        }
    }
    printf("Il massimo nel buffer è %d\n", max);
    return max;
}

int calc_min(int *buffer, int buf_size)
{
    int min = buffer[0];
    int i;
    for(i = 0; i < buf_size; i++)
    {
        if (buffer[i] < min)
        {
            min = buffer[i];
        }
    }
    printf("Il minimo nel buffer è %d\n", min);
    return min;
}

void *check()
{
    while(True)
    {
        pthread_mutex_lock(&mutex);
        while(buffer_checker(bufA, 'A') == False || buffer_checker(bufB, 'B') == False)
        {
            pthread_cond_wait(&condcheck, &mutex);
            sleep(rand() % 4);
        }
        int maxA = calc_max(bufA, BUF_SIZE);
        int minA = calc_min(bufA, BUF_SIZE);
        int maxB = calc_max(bufB, BUF_SIZE);
        int minB = calc_min(bufB, BUF_SIZE);
        int bufMax[2] = {maxA, maxB};
        int bufMin[2] = {minA, minB};
        int totMax = calc_max(bufMax, 2);
        int totMin = calc_min(bufMin, 2);
        kill(AModder, SIGTERM);
        kill(BModder, SIGTERM);
        exit(0);
    }
}



int main()
{
    int mut = pthread_mutex_init(&mutex, NULL);
    if(mut == -1)
    {
        perror("Errore inizializzazione mutex");
        exit(1);
    }
    int cond = pthread_cond_init(&condcheck, NULL);
    if(cond == -1)
    {
        perror("Errore inizializzazione cond");
        exit(1);
    }

    int t1 = pthread_create(&AModder, NULL, AMod, NULL);
    int t2 = pthread_create(&BModder, NULL, BMod, NULL);
    int t3 = pthread_create(&checker, NULL, check, NULL);

    if(t1 == -1 || t2 == -1 || t3 == -1)
    {
        perror("Errore creazione thread");
        exit(1);
    }

    pthread_join(AModder, NULL);
    pthread_join(BModder, NULL);
    pthread_join(checker, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condcheck);
}
