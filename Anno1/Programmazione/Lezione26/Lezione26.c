#include <stdio.h> //Così facendo includo una libreria, che comprende un determinato numero di funzioni utili. Non dissimile dai moduli di Python.

void main() //Main è la funzione base da cui parte tutto. La quasi totalità dei programmi scritti in C comprende almeno il main().
{
    printf("Ciao Mondo!\n"); //funzione print-formatted. Stampa stringhe, abbastanza banalmente.

    int n = 10; //il tipo della variabile che vogliamo inizializzare va sempre dichiarato.
    int m; //quest'operazione è fondamentalmente concessa(diversamente da Python) perché non stiamo facendo altro che riservare della memoria (della dimensione di un int) alla variabile. Non è 0, nota, è indefinito.
    float x = 3.14;
    double y = x; //il tipo double è un tipo speciale per la rappresentazione numerica ad alta precisione, con 8 byte riservati invece di 4. Utile in caso ci serva un numero particolarmente preciso.
    float w = 0, z;

    char c = 'a'; //Il char è un dato di che indica un singolo carattere. Nota che usa singoli apici, diversamente dalla stringa.
    
}