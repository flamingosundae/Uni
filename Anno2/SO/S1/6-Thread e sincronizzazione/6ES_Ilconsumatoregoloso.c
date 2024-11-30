#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>

#define True 1
#define False 0
#define buffer_size 10

/*Scrivere un programma C che implementi il problema classico del Produttore-Consumatore con un buffer. Inizialmente, il processo crea un buffer come un array circolare di 10 elementi, inizializzati a zero.

Successivamente, generare due tipi di thread utilizzando le librerie POSIX:

    Produttore: In un ciclo infinito, il produttore sceglie casualmente una cella vuota del buffer e vi scrive un numero intero generato casualmente. Ogni volta che un valore viene prodotto, il produttore deve attendere un numero casuale di millisecondi tra 0 e 500 prima di produrre il successivo.

    Consumatore: In un ciclo infinito, il consumatore sceglie casualmente una cella piena del buffer e legge il valore. Ogni volta che un valore viene consumato, il consumatore deve attendere un numero casuale di millisecondi tra 0 e 500 prima di consumare il successivo.

Il programma dovrebbe terminare quando il consumatore ha letto un numero totale di valori che supera una soglia prefissata (ad esempio, 100). Assicurarsi che il buffer circolare sia gestito in modo sicuro, evitando la possibilità di letture/scritture concorrenti.*/

int cons_count = 0;
int full_spaces = 0;
int buffer[buffer_size] = {0};
pthread_t prod, cons;
pthread_mutex_t mutex;
pthread_cond_t condc, condp;

void signal_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("SIGINT ricevuto. Terminazione thread.\n");
        pthread_exit(0);
    }
}


void print_buffer()
{
    int i;
    for(i = 0; i < buffer_size; i++)
    {
        printf("%d", buffer[i]);
    }
}

void insert_item()
{
    int i = rand() % buffer_size;
    int inserted_value = rand() % buffer_size;
    buffer[i] = inserted_value;
    full_spaces++;
    printf("Ho inserito %d in posizione %d\n", inserted_value, i);
    printf("Lo stato del buffer è ora");
    print_buffer();
    printf("\n");
}


void consume_item()
{
    int i = rand() % buffer_size;
    while(buffer[i] == 0)
    {
        i = rand() % buffer_size;
    }
    cons_count = cons_count + buffer[i];
    full_spaces--;
    printf("Ho consumato %d in posizione %d\n", buffer[i], i);
    buffer[i] = 0;
    printf("Lo stato del buffer è ora");
    print_buffer();
    printf("\n");
}


void *producer(void *args)
{
    signal(SIGINT, signal_handler);
    while(True)
    {
        pthread_mutex_lock(&mutex);
        while(full_spaces != 0)
        {
            pthread_cond_wait(&condp, &mutex);
        }
        insert_item();
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condc);
        int sleep_time = rand() % 6;
        sleep(sleep_time);
    }
}


void *consumer(void *args)
{
    signal(SIGINT, signal_handler);
    while(True)
    {
        pthread_mutex_lock(&mutex);
        while(full_spaces == 0)
        {
            pthread_cond_wait(&condc, &mutex);
        }
        consume_item();
        if(cons_count >= 10)
        {
            printf("Consumato %d.\n", cons_count);
            pthread_kill(prod, SIGINT);
            pthread_exit(0);
        }
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&condp);
        int sleep_time = rand() % 6;
        sleep(sleep_time);
    }
}



void main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condp, NULL);
    pthread_cond_init(&condc, NULL);


    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
}

