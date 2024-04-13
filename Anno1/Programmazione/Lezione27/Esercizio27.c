#include <stdio.h> //Questa è una lista di prototipi in sé. Vi è, per esempio, printf. Indipercui, la mancanza di errori in invocazione.

char switch_case(char c);
//Istituendo una libreria di prototipi all'inizio del programma, possiamo evitare errori e imprecisioni dovute a conversioni impliciite di tipo.


void main()
{
    char x = switch_case('C');
    char y = switch_case('a');
    char z = switch_case('!');
    printf("Il minuscolo di C e' %.c\n", x);
    printf("Il maiuscolo di a e' %.c\n", y);

}

char switch_case(char c)
/*
input: un char, c.
output: se C è maiuscolo, il suo minuscolo. Se c è minuscolo, il suo maiuscolo. 1 in tutti gli altri casi.
*/
{
    if (c >= 65 && c <= 90)
    {
        return c + 32;
    }
    else if(c >=97 && c <= 122)
    {
        return c - 32;
    }
    else
    return '1';
}


// Versione del Rossi

char rossi_case(char c)
{
    if (c >= 'A' && c <= 'Z') //Non serve confrontare con gli interi ASCII, in quanto sono già inerentemente codificati nei char. Rende tutto più leggibile, d'altro canto.
    {
        return 'a' + c - 'A'; //Il primo frammento ci porta nella scala dei minuscoli. Il secondo frammento sposta 'a' del delta necessario ad arrivare alla lettera interessata.
    }
    else if(c >= 'a' && c <= 'z')
    {
        return 'A' + c - 'a';
    }
    else
    return -1; //Essendo questo int associato ad un carattere nella mappatura ASCII (che non esiste), i risultati in print non saranno sintatticamente corretti.
    //Idealmente dovremmero implementare un if in funzione per controllare qual è l'output e muoverci di conseguenza. Ma a chi va?
     
}