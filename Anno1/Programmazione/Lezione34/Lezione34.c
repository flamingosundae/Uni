#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linked_list in0(linked_list, float);
linked_list del0(linked_list);
void print_llist(linked_list);
linked_list init(void);
node *search(linked_list, int);
linked_list insert(linked_list, int, float);
linked_list delete(linked_list, int);

struct node
{
    float v;
    struct node *next;
};
typedef struct node node;

struct linked_list
{
    node *a; //Punta al primo elemento della lista collegata.
    int n; //Dimensione della lista collegata.
};
typedef struct linked_list linked_list;


linked_list in0(linked_list L, float v){
	node *p = malloc(sizeof(node));
	
	p->v = v;
	p->next = L.a;
	L.a = p;
	L.n++;
	
	return L;
}


linked_list del0(linked_list L)
{
    node *p;
    if(L.n > 0)
    {
        p = L.a;
        L.a = p->next;
        free(p);
        L.n--;
    }
    return L;
}

void print_llist(linked_list L){
	node *p = L.a;
	
	while( p != NULL ){
		printf("%f\n", (*p).v);
		p = p->next; 
	}
}

linked_list init(void) {
	linked_list L = {NULL, 0};
	return L;
}

node *search(linked_list L, int pos)
{
    int i;
    node *p = L.a;
    if(pos > L.n)
    {
        return NULL;
    }
    else
    for(i = 0; i < pos; i++)
    {
        p = p->next;
    }
    return p;
}
//la versione del rossi non accede a L.n, preferendo piuttosto l'uso del while(p != NULL && c < pos). Non molto diverso, in termini di semantica o costi computazionali.

linked_list insert(linked_list L, int pos, float v) //costo O(n^2) nel caso peggiore, ossia nel caso in cui il search arrivi fino all'ultima posizione della lista collegata.
{
    node *q, *p;
    if (pos > 0 && pos <= L.n)
    {
        q = search(L, pos-1);
        p = malloc(sizeof(node));
        p->v = v;
        p->next = q->next;
        q->next = p;
        L.n++;
    } 
    else if(pos == 0)
    {
        L = in0(L, v);
    }

    return L;

}

linked_list delete(linked_list L, int pos)
{
    node *p, *q;
    if(pos > 0 && pos < L.n)
    {
        q = search(L, pos-1);
        p = q->next;
        q->next = p->next;
        free(p);
    } 
    else if(pos == 0 && L.n > 0)
    {
        L = del0(L);
    }
    return L;
}


void main(){
	linked_list L = init();
	int e;
	
	for(e = 0; e < 10; e++){
		L = in0(L, (e+1)*11.1);
	}
		
	print_llist(L);
}