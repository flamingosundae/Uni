#include <stdio.h>
#include <stdlib.h>

struct array_int //con le struct possiamo creare nuovi tipi di dato a partire da quelli che abbiamo già, definendo strutture specifiche con un set preimpostato di informazioni.
{
    int *a; //Un elemento all'interno di una struct è definito campo. Questo è il puntatore al primo elemento dell'array.
    int len; //Indica la lunghezza dell'array.
    int cap;
};
typedef struct array_int array_int; //con typedef possiamo rinominare un determinato dato.
array_int array_init();
array_int array_append(array_int, int);
void array_print(array_int);
array_int array_pop(array_int );
array_int array_insert(array_int, int, int);


array_int array_init() 
{
    array_int v = {NULL, 0, 0};
    return v;
}


array_int array_append_adv(array_int v, int e) 
{
    int i;
    int *a;
    
    if(v.len == v.cap)
    {
    a = malloc(2 * (v.cap+1) * sizeof(int));
    
    if(a == NULL)
    return v;

    for(i = 0; i < v.len; i++)
    {
        a[i] = v.a[i];
    }
    a[v.len] = e;
    v.len++;
    v.cap = 2*(v.cap+1);
    free(v.a);
    v.a = a;
    }
    v.a[v.len] = e;
    v.len++;
 

}

void array_print(array_int v) 
{
    int i;
    printf("[\n");
    for(i=0; i < v.len; i++)
    {
        printf("%d", v.a[i]);
    }
    printf("]\n");

}

array_int array_insert(array_int v, int pos, int e)
{
    int old_c = v.cap, old_n = v.len;
    int i;

    if (pos > v.len)
        return v;

    v = array_append_adv(v, 0);

    if (old_c == old_n && old_c == v.cap)
    { // malloc dentro append ritorna NULL
        return v;
    }

    for (i = v.len - 1; i >= pos; i--)
    {
        v.a[i + 1] = v.a[i];
    }

    v.a[pos] = e;

    return v;
}

array_int array_pop(array_int v)
{
    if (v.len > 0)
        v.len--;
    return v;
}

void main()
{
    array_int v = array_init();
    int i;
    int n = 14;

    for(i = 0; i < n; i++ )
    {
        // v = array_append(v, 10*i); nel caso peggiore, costo O(n^2) in termini temporali e O(n) in termini spaziali.
    }
    array_print(v);
}