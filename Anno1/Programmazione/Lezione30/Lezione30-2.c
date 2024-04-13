#include <stdio.h>
#include <stdlib.h>

struct array_int //con le struct possiamo creare nuovi tipi di dato a partire da quelli che abbiamo già, definendo strutture specifiche con un set preimpostato di informazioni.
{
    int *a; //Un elemento all'interno di una struct è definito campo. Questo è il puntatore al primo elemento dell'array.
    int len; //Indica la lunghezza dell'array.
};
typedef struct array_int array_int; //con typedef possiamo rinominare un determinato dato.
array_int array_init();
array_int array_append(array_int, int);
void array_print(array_int);



void main()
{
    int i;
    array_int v;
    array_int k = array_init();

    v.a = malloc(sizeof(int) * v.len);//possiamo accedere ai campi di una struct usando la sintassi struct.campo .
    v.len = 10;

    k = array_append(k, 10);
    

}


array_int array_init() //costo costante.
{
    array_int v = {NULL, 0};
    return v;
}


array_int array_append(array_int v, int e) //lineare in v.len.
{
    int i;
    int *a = malloc((v.len+1) * sizeof(int));

    if (a != NULL)
    {
    for (i = 0; i < v.len; i++)
       {
            a[i] = v.a[i];
       }
    
    a[i] = e;
    v.len++;
    free(v.a);
    v.a = a;
    }

    return v;
}

void array_print(array_int v) //lineare in v.len.
{
    int i;
    printf("[\n");
    for(i=0; i < v.len; i++)
    {
        printf("%d", v.a[i]);
    }
    printf("]\n");

}