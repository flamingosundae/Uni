#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void remove_non_alpha(char*);


void main()
{
    char a[10] = "a111ssio";
    remove_non_alpha(a);
    printf("%s\n", a);
}


void remove_non_alpha(char *a)
{
    int i, k = 0;
    for(i=0; i< a[i] != '\0'; i++)
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            a[k] = a[i];
            k++;
        } 
    }
    a[k] = '\0';
}