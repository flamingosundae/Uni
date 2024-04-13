#include <stdio.h>
void incrementa_int(int*);


void main()
{
    int n = 1, x = 10;
    int a, b;
    int d;
    char s[] = "123";
    incrementa_int(&x); //con l'operatore & passiamo ad una funzione non la variabile in sé, ma il suo indirizzo di memoria. Molto utile per processi che coinvolgano puntatori.
    printf("%d\n", x); //come far sì che questa riga stampi 11?


    scanf("%d", &n); //la funzione scanf di C blocca l'esecuzione del programma affinché l'utente inserisca qualcosa in input. Più specificamente, una stringa, su cui può essere anche effettuato parsing(estrazione di informazioni).
    //In questo caso, per esempio, la funzione cercherà di interpretare l'input come un intero(se la stringa è compatibile), e lo salva in un puntatore(il secondo parametro).
    printf("%d", n); //se la conversione fallisce, verrà stampato il valore precedente di n(1).

    scanf("%d;%d", &a, &b); //possiamo anche più conversioni in una sola scanf. Attenzione alla sintassi: non ci vanno spazi, e ogni input diverso va separato da punto e virgola, anche in input, nel formato (a;b). Senza spazi.
    printf("%d, %d", a, b);

    sscanf(s, "%d", d); //Sscanf opera come scanf, ma agisce su una stringa preimpostata invece che un input dell'utente. A parte ciò, ha lo stesso funzionamento e formattazione di scanf.

}


void incrementa_int(int *z)
{
    //prendere in input x e aumentarlo di 1 non funzionerebbe. Staremmo modificando soltanto la variabile locale z, e non x. Per raggiungere il nostro obiettivo, dovremmo passare alla funzione un puntatore a x.
    (*z)++;
}