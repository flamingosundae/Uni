#include <stdio.h>
int len_calc(int a);
void change_array(int d[]);


void change_array(int d[])
{
    int i;
    for(i = 0; i < len_calc(d); i++)
    {
        d[i] = i * 10;
    }
}

//I compilatori per C lavorano dalla prima all'ultima riga. Questo significa che se non definisci la funzione prima di usarla nel main, il compilatore restuituirà un warning. Non è strettamente un errore(funzionerà lo stesso), ma ovviamente meglio evitare.
//Come abbiamo già fatto nota precedentemente, occhio alle conversioni implicite. Una conversione sfavorevole può causare perdita di informazioni.

/*
Scalari in C:
int, float, double, long, char.
*/

//Per i sequenziali, invece, possiamo creare sequenze di dati tutti dello stesso tipo: gli array.

void main()
{
    int i;
    int a[10]; //inizializzazione di un array. Gli elementi all'interno sono indeterminati.
    int b[] = {1, 3, 5, 4}; //secondo modo per inizializzare un array. Abbiamo tutto: il tipo degli elementi dell'array, quali sono, quanti sono.
    int c[5] = {1, 2, 3, 4, 5}; //potremmo specificare anche la dimensione, ma è ridondante.
    int d[15] = {1}; //terzo modo per inizializzare un array. Nel momento stesso in cui definiamo anche solo un singolo elemento di un array, tutti gli indeterminati vengono automaticamente inizializzati a 0. Ricordatelo, che l'ultima volta hai toppato.
    int e[100] = {0};
    printf("%d, %d, %d, %d, %d\n", a[3], b[0], c[2], d[10], e[97]);
    d[11] = 21; //Possiamo riassegnare un elemento di un array ad un nuovo valore.

    for(i = 0; i < len_calc(d); i++)
    {
        printf("%d\n", d[i]); //Gli array supportano l'indicizzazione.
        //Il costo di accesso in lettura ad un array è costante.
    }

    change_array(d);
    printf("%d\n");//nota bene: la funzione non opera su una copia dell'array, ma sull'array stesso. Il d che passiamo in input non è altro che l'indirizzo del primo elemento della sequenza(dopo il quale si troveranno tutti gli altri).

}


int len_calc(int a)
{
    return sizeof(a)/sizeof(int);//La funzione sizeof non ritorna la lunghezza dell'array, ma la quantità di spazio che l'array occupa.
}
//Nota che se per esercizio stilistico mettessimo 2*len_calc dell'array, il compilatore non darebbe problemi. è uno strumento puramente sintattico, che quindi non coglie l'ovvio problema semantico che rappresenta. Fai attenzione. 