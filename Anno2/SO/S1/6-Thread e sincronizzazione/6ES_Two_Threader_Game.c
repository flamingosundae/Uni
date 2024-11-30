#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1
#define FALSE 0
    /*Inizializza una variabile globale int counter a 0.
    Crea due thread, player_A e player_B.
    Il gioco consiste in 10 turni. Ad ogni turno, il giocatore corrente incrementa counter di un valore casuale compreso tra 1 e 5.
    Ogni thread, prima di incrementare counter, controlla se è possibile eseguire il proprio turno confrontando counter con un valore massimo prefissato (ad esempio, 20). Se counter supera tale valore, il giocatore corrente termina e il gioco finisce.
    Ogni giocatore, prima di eseguire la propria mossa, deve attendere un numero di millisecondi casuale compreso tra 100 e 500.
    Il giocatore che raggiunge per primo o supera il valore massimo (20) vince la partita.*/


int counter = 0;
int turn = 0;
pthread_t player_A, player_B;
pthread_mutex_t mutex;


void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("Segnale SIGINT ricevuto. Terminazione thread.");
        pthread_exit(0);
    }
}


void termination_protocol(char player)
{
    if(player == 'A')
    {
        pthread_kill(player_B, SIGINT);
    }
    else
    {
        pthread_kill(player_A, SIGINT);
    }
    pthread_exit(0);
}



void *make_a_move(void *player)
{
    signal(SIGINT, sig_handler);
    char player_name = (char)player;

    while(TRUE)
    {
        pthread_mutex_lock(&mutex);
        if(turn == 10)
        {
            printf("Limite di turni superato.\n");
            termination_protocol(player_name);
        }
        int value_added = (rand() % 5) + 1;
        counter = counter + value_added;
        turn++;
        printf("Sono il thread %c e ho aggiunto %d al counter. Il suo valore è ora %d.\n", player_name, value_added, counter);
        if(counter >= 20)
    {
        printf("Il counter ha superato 20. Vince il player %c!\n", player_name);
        termination_protocol(player_name);
    }
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 5);
    }
}




int main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&player_A, NULL, make_a_move, ((void*)('A')));
    pthread_create(&player_B, NULL, make_a_move, ((void*)('B')));

    pthread_join(player_A, NULL);
    pthread_join(player_B, NULL);

    pthread_mutex_destroy(&mutex);
}
