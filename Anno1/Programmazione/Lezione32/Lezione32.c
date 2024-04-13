#include <stdio.h>
#include <stdlib.h>

struct array_int {
	int *a;
	int n;
	int c;
};
typedef struct array_int array_int;


array_int array_int_init(void);
array_int array_int_append( array_int, int );
void array_int_print(array_int);
array_int array_int_insert( array_int, int, int );
//array_int array_int_pop(array_int);
array_int trova_spazi(char*);
array_int trova_spazi_rossi(char*);
array_int array_int_pop_adv(array_int);


void main()
{
    char a[] = "Il vuoto, lo spazio, l'universo";
    array_int b = trova_spazi(a);
    array_int_print(b);



}

array_int array_int_init(void){ // O(1)
	array_int v = {NULL, 0, 0};
	return v;
}

array_int array_int_append( array_int v, int e ){
	int i;
	int *a;
	
	if (  v.n == v.c ){
		a = malloc((2*v.c+1)*sizeof(int));
		if (a == NULL)
			return v;
		
		for(i = 0; i < v.n; i++){
			a[i] = v.a[i]; 
		}
		v.c = 2*v.c+1;
		free(v.a);
		v.a = a;
	}
	v.a[v.n] = e;
	v.n++;
	
	return v;
}

void array_int_print(array_int v){ // O(v.n)
	int i;
	
	printf("[");
	for( i = 0 ; i < v.n; i++){
		printf("%d,", v.a[i]);
	}
	printf("]\n");
}

array_int array_int_insert( array_int v, int pos, int e) {
	int old_c = v.c, old_n = v.n;
	int i;
	
	if (pos > v.n)
		return v;
	
	v = array_int_append(v, 0);
	
	if (old_c == old_n && old_c == v.c){ // malloc dentro append ritorna NULL
		return v;
	}
	
	for( i = v.n-1; i >= pos; i--){
		v.a[i+1] = v.a[i];
	}
	
	v.a[pos] = e;
	
	return v;
}

/*
array_int array_int_pop(array_int v ){
	if (v.n > 0)
		v.n--;
	return v;
}
Questa versione ha un fondamentale difetto in termini di complessità spaziale: sebbene rimuova l'ultimo elemento dell'array, rischia di creare una capacità illimitata rispetto all'effettivo numero di elementi.
La soluzione è relativamente semplice: ci basta ridurre v.c in caso ecceda, per esempio, 4 volte v.n (garantendoci così un rapporto lineare in termini di complessità spaziale).
*/

array_int array_int_pop_adv(array_int v)
{
    if (v.n > 0)
    {
        v.n--;
    }
    if(v.c > v.n * 4)
    {
        v.a = realloc(v.a, ((v.c+1)/2) * sizeof(int)); //La funzione realloc estende o riassegna la memoria assegnata ad un array, restituendo un puntatore allo stesso o nuovo indirizzo (a seconda della disponibilità di spazio).
        //Si comporta abbastanza similmente alla malloc, restituendo NULL se non è presente abbastanza memoria contigua per la riassegnazione.
        v.c = (v.c+1)/2;
    }

return v;
}



//Esercizio facoltativo: modifica l'append usando la realloc invece che la malloc.
