#include <stdlib.h>
#include <stdio.h>
int multipli5(int);
void main()
{
    int a;
    int n;
    int i;
    multipli5(n);
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

}


int multipli5(int n)
{
    int i;
    printf("Inserisci quanti multipli di 5 vuoi\n:");
    scanf("%d\n", n);
    int *a = malloc(sizeof(int) * n);
    for(i = 1; i < n; i++)
    {
        a[i] = n*i;
    }
    
    return a;


}