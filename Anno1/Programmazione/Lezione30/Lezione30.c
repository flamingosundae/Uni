#include <stdio.h>
#include <stdlib.h>

char *str_cat_proto(char*, char*);
int len_calc(char*);
char *str_cat(char* , char*);

void main()
{
    int i;
    char a[] = "Questa è una stringa"; //Le stringhe in C non sono altro che array di char consecutivi. Grazie a stdio, possiamo all'incirca effettuare tutte le operazioni che già praticavamo sulle stringhe in Python.
    char b[] = "Anche questa è una stringa";
    char *c;
    
    //Alla fine di un array di char, in C, verrà sempre aggiunto un carattere speciale che segna la fine della stringa, ossia '\0'
    //Tutte le operazioni che abbiamo visto per gli array sono applicabili anche in questo caso.

    printf("La mia prima stringa sarà  \" %s \" \n", a); //Il carattere di formattazione per stampare una stringa è %s.

    for (i = 0; i != '\0'; i++)
    {
        printf("%c",'A' + a[i] - 'a'); ///(per convertire tutto in maiuscole).
    }
    printf("\n");
    
    c = str_cat(a, b);
    printf("%s\n", c);
}

char *str_cat_proto(char *a, char *b)
{
    int i;
    /*
    input: due stringhe, a e b.
    output: la concatenazione delle due stringhe.
    */
   char *c = malloc((len_calc(a) + len_calc(b) + 1) * sizeof(char));

   for(i = 0; i < len_calc(a); i++)
   {
    c[i] = a[i];
   }
   for(; i < len_calc(a) + len_calc(b); i++ )
   {
    c[i] = b[i - len_calc(a)];
   }
   c[i] = '\0';
   return c;
   //Questa versione, sebbene sia praticamente rifinita, ha un problema fondamentale nel costo quadratico dato dal calcolo ripetuto di len_calc(a) e len_calc(b). è tuttavia relativamente semplice da sistemare.
}

char *str_cat(char *a, char *b)
{
    int n = len_calc(a);
    int m = len_calc(b);
    int i;
    /*
    input: due stringhe, a e b.
    output: la concatenazione delle due stringhe.
    */
   char *c = malloc((n + m + 1) * sizeof(char));

   for(i = 0; i < n; i++)
   {
    c[i] = a[i];
   }
   for(; i < n + m; i++ )
   {
    c[i] = b[i - n];
   }
   c[i] = '\0';
   return c;
}


int len_calc(char *a)
{
    /*
    input: un puntatore a stringa, a.
    output: la lunghezza della stringa.
    */
    int n = 0;
    while(a[n] != '\0')
    {
        n++;
    }
    return n;

}