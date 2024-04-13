#include <string.h>
#include <stdio.h>

void filtra(char*, int*);

void main()
{
    char a[] = "Alessioeso";
    int b[] = {1,0,1,0,0,1,0,0,0,0};
    filtra(a, b);
    printf("%s\n", a);

}


void filtra(char *a, int *b)
{
    int i, j = 0;
    int n = strlen(a);
    for(i=0; i<n; i++)
    {
        if(b[i] == 1)
        {
            a[j] = a[i];
            j++;
        }
        
    }
    a[j] = '\0';
}