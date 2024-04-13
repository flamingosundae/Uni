#include <stdio.h>
#include <math.h> //La libreria math.h include una serie di funzioni molto importanti  per il calcolo aritmetico e trigonometrico, come sin, cos, e modulo.

void main()
{
    int x;
    float y, eps = 0.0001;
    for(x = 2; x = 12; x++)
    {
        y = radice_quadrata(x, eps);
        printf("La radice quadrata di %.d e' %.5f\n", x, y);
        
    }
    /*
    if (i < max_iter)
    {
        printf("La macchina si è fermata dopo %.d iterazioni\n", i); // Nel caso degli int, lo shorthand per la stampa è %.d.
    }
    else // se il blocco ha un'unica istruzione non necessita di graffe.
    {
        printf("Jackpot!");
    }
    */
}


void test_char()
{
    char c; //Il tipo char è usato per rappresentare un singolo carattere. Nota, importantemente, che ha una doppia valenza: il suo valore alfanumerico, e l'int a cui è associato nella mappazione ASCII. Può quindi essere anche usato per ambiti di confronto numerico.
    for(c = 'a'; c <= 'z'; c++)
    {
        printf("Il valore di c e' %.c\n", c); // Lo shorthand per l'invocazione dei char in stampa è %.c.
        printf("Il valore ASCII di c e' %.d\n", c);
    }
}





float radice_quadrata(int x, float eps) //Essendo una funzione una variabile, esattamente per come tutti gli altri casi, il tipo di ritorno va specificato in fase di definizione. Così come va specificato il tipo dei parametri formali in input.
//Che x sia int o float, non ci sono grosse differenze. Una conversione diventa problematica solo se perde inerentemente informazioni sull'oggetto(come convertire un float in un int).
{
    float g = x/2;
    int i = 0;
    int max_iter = 1000;

    g = x / 2;
    i = 0;
    while (fabs(g * g - x) > eps && i < 1000) // Questo programma darà un ciclo infinito, ma non per errori sintattici. All'atto della compressione in float, eps non avrà abbastanza memoria per essere rappresentato con precisione.  Verrà quindi compresso in 0, da cui il ciclo infinito.
    {
        g = 0.5 * (g + x / g);
        i++; // esiste anche i--.
    }
    return g;
}

/*
Cheat sheet degli operatori logici in C:
&& : and
|| : or
! : not
*/

/*
Cheat sheet degli operatori relazionali in C:
==, !=,
>, <, >=, <= 
*/


/*
Guida all'uso del for:
for(istr0; cond; istr1)
{
    blocco;
}

equivale a

istr0;
while(cond){
    blocco;
    istr1;
}
*/