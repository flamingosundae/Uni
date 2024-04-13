#include <stdio.h>

void f(int *x, int p)
{
    *(x + p) = 2 * p;
}

int main()
{
    int n = 5; // Dimensione dell'array
    int a[5];

    // Inizializza l'array in modo che a[i] = i per ogni i
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    int k = 2; // Scegliamo un valore arbitrario per k

    printf("Prima dell'invocazione di f(a, k):\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // Invoca la funzione f
    f(a, k);

    printf("Dopo l'invocazione di f(a, k):\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
