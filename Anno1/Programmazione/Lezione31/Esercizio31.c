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
array_int array_int_pop(array_int);
array_int trova_spazi(char*);
array_int trova_spazi_rossi(char*);



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

array_int array_int_pop(array_int v ){
	if (v.n > 0)
		v.n--;
	return v;
}


array_int trova_spazi(char *a)
{
    /*
    input: una stringa, a.
    output: un array contenente la posizione degli spazi vuoti in a.
    */
   int i;
   array_int v = array_int_init();

   for(i = 0; i != '\0'; i++)
   {
    if(a[i] ==  ' ')
    {
        v = array_int_append(v, i);
    }
   }

   return v;

}


//soluzione del rossi
array_int trova_spazi_rossi(char *c)
{
    array_int v = array_int_init();
    int i = 0;

    while(v.a[i] != '\0')
    {
        if (v.a[i] == ' ')
        {
            v = array_int_append(v, i);
        }
        i++;
    }
    return v;
}