//Trova la somma di tutti i multipli di 3 e 5 sotto mille.
#include <stdio.h>
#include <stdlib.h>

int multiple_sum(int n);

void main()
{
    printf("La somma di tutti i multipli sotto 1000 e' %d \n", multiple_sum(0));

}

int multiple_sum(int n)
{
    n = 0;
    int i;

    for(i = 0; i < 1000; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            n += i;
        }
    }

    return n;
}