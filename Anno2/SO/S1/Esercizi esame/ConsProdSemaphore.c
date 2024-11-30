/*Due thread, il produttore inserisce numeri pari da 0 a 100 in posizioni pari,
 e numeri dispari da 100 a 200 in posizioni dispari all'interno di un buffer di N elementi, iniziliazzato a -1, il consumatore legge dal buffer un numero pari e un numero dispari, li somma e stampa la loro somma. */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define True 1
#define False 0
#define N 10

sem_t mutex;
pthread_t cons, prod;
int buffer[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void print_buffer(int *buf)
{
    int i;
    printf("Stato attuale del buffer:\n");
    for(i = 0; i < N; i++)
    {
        printf(" %d ", buf[i]);
    }
    printf("\n");
}

void init_buffer(int *buf)
{

}
