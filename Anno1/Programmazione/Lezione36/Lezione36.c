#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* chiave: stringa; valore: float */
struct dict_item {
	char *k;
	float v;
};
typedef struct dict_item dict_item;

struct node {
	dict_item info;
	struct node *next;
};
typedef struct node node;

struct linked_list {
	node *a; /* punta al primo elemento della sequenza*/
	int n;
};
typedef struct linked_list linked_list;

struct dict {
	node **a;
	int n;
	int M;
};
typedef struct dict dict;

dict dict_init(int);
int h(dict, char*);
void dict_set(dict, dict_item);
node *dict_search(dict, char*);
void print_dict(dict);
void print_llist(node*);
node *in0(node*, dict_item);


void main(int dim, char *args[]){
	dict d = dict_init(15);
	int i;
	dict_item e;
	
	for(i = 1; i < dim; i++){
		e.k = args[i];
		e.v = i;
		dict_set(d, e);
	}

	print_dict(d);
}


/* ritorna un indice del dizionario*/
int h(dict d, char *k){
	return 0;
}

/* imposta un volore per una chiave del dizioario usando e */
void dict_set(dict d, dict_item e){
	int p = h(d, e.k);
	node *nd;
	
	nd = dict_search(d, e.k);
	if( nd != NULL ) {
		nd->info.v = e.v;
	} else {
		d.a[p] = in0(d.a[p], e);
		d.n ++;
	}
}

/* ritorna il puntate al node contenente l'item del dizionario con
 * chiave k. NULL se tale chiave non è presente nel dizionario */
node *dict_search(dict d, char *k){
	int p = h(d, k);
	node *q = d.a[p];
	
	while( q != NULL && strcmp(k, q->info.k) != 0){
		q = q->next;
	}
	
	return q;
}

/* Inizializza un dizionario vuoto con M liste*/
dict dict_init(int M){
	dict d;
	int i;
	d.a = malloc(sizeof(node*)*M);
	d.n = 0;
	d.M = M;
	for(i = 0; i < d.M; i++){
		d.a[i] = NULL;
	}
	return d;
}

/* Mostra il dizionario */
void print_dict(dict d){
	int i;
	for (i = 0; i < d.M; i++){
		print_llist(d.a[i]);
		printf("\n");
	}
}



node *in0(node *nd, dict_item e){
	node *p = malloc(sizeof(node));
	
	p->info = e;
	p->next = nd;
	nd = p;
		
	return nd;
}



void print_llist(node *nd){
	node *p = nd;
	
	while( p != NULL ){
		printf("(\"%s\", %f) ", p->info.k, p->info.v);
		p = p->next; /*equivalente a p = (*p).next */
	}
}
