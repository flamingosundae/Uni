#include <stdio.h>
#include <stdlib.h>
void change_array(int d[], int n);
int *copy_array(int *x, int n);
int *array_append(int *x, int n);


void change_array(int d[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        d[i] = i * 10;
    }
}
/*
int copy_array_prototipo(int x[], int n)
{
    int i;
    int a[n]; //anche se a[] venisse creato(e in questa versione non succede), ci sarebbe un problema fondamentale: una volta chiuso il framework, la memoria dedicata ad a[] verrebbe deallocata, e l'array smette di esistere.
    //Tutto ciò che viene creato in una funzione è interno alla funzione, a meno che non venga specificato diversamente.
    
    for(i = 0; i < n; i++)
    {
        a[i] = x[i];
    }
    return a;

}
*/

int *copy_array(int *x, int n) //simile(non esattamente equivalente) a (int x[], int n).
{
    int i;
    int *a = malloc(sizeof(int) * n); //la funzione malloc prende in input un x intero, alloca una x quantità di memoria per una sequenza di dati, e ritorna l'indirizzo del primo elemento. Così facendo, di fatto, rendiamo a un array.

    if(a == NULL) //se la malloc fallisce, di solito perché non trova memoria contigua sufficiente, il puntatore restituito sarà un puntatore a NULL.
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            a[i] = x[i];
        }
    }

    return a;
}



void main()
{
    int d[15] = {0, 10, 20, 30, 40};
    int i;
    int len_d = sizeof(d)/sizeof(int);
    int *p; //Questo è un puntatore. è un intero contenente l'indirizzo di memoria di un determinato dato. In questo caso, abbiamo un puntatore ad intero.
    //Se volessimo trovare una somiglianza, potremmo considerare p un alias di d. Ma quello che ci interessa davvero sapere è che con questo puntatore possiamo finalmente creare un copy array funzionale.
    int *q;
    int *k;
    int b[10] = {1, 2};
    int len_q = sizeof(d) / sizeof(int);

    change_array(d, len_d);
    for(i = 0; i < len_d; i++)
    {
        printf("%d", d[i]);
    }
    printf("\n");
    p = copy_array(d, len_d);
    if(p!= NULL)
    {
        for (i = 0; i < len_d; i++)
        {
            printf("%d", p[i]); // non è strettamente sbagliato che non ci sia corrispondenza tra tipo di un puntatore e tipo di dato associato ad esso, ma può portare a errori semantici e problematiche di vario genere.
        }
    }
    else
    {
        printf("Errore di memoria!\n");
    }
    q = copy_array(d, len_d); //la memoria occupata nell'heap, solitamente, viene liberata al termine del programma. Ma così facendo, rischiamo di avere eccessiva memoria occupata e causare errori di frammentazione del malloc.
    free(q); //con free possiamo liberare in anticipo la memoria occupata da un determinato oggetto.
    q = array_append(d, len_d, 100);



    int *v = k+1; //nota molto, molto bene. L'aritmetica dei puntatori pertiene ad un set molto specifico di regole. Per esempio, in questo caso, n non sarà associato al byte successivo a k, ma all'indirizzo di memoria successivo, secondo la taglia definita dal dato a cui punta k.
    //In generale, i puntatori sono calcolati e operati secondo la logica delle posizioni in memoria, non quella strettamente aritmetica.


}

int *array_append(int *x, int n, int e) //simile(non esattamente equivalente) a (int x[], int n).
{
    int i;
    int *a = malloc(sizeof(int) * (n+1)); //la funzione malloc prende in input un x intero, alloca una x quantità di memoria per una sequenza di dati, e ritorna l'indirizzo del primo elemento. Così facendo, di fatto, rendiamo a un array.

    if(a == NULL) //se la malloc fallisce, di solito perché non trova memoria contigua sufficiente, il puntatore restituito sarà un puntatore a NULL.
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            a[i] = x[i];
        }
        a[n] = e;
    }

    return a;
}
