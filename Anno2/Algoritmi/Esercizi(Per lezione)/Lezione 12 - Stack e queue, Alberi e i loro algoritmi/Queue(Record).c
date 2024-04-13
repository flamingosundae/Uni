#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

struct node
{
    int v; //contenuto informativo.
    struct node *next; //puntatore al prossimo record.
    struct node *prev; //puntatore al precedente record.
};
typedef struct node node;
struct queue
{
    int len; //numero di record nella queue.
    node *first; //puntatore al primo record della ueue.
    node *last; //puntatore all'ultimo record della queue.
};
typedef struct queue queue;

queue queue_init();
int isEmpty(queue q);
queue *enqueue(queue *q, int v);
queue *dequeue(queue *q);
int first(queue q);
void queue_print(queue q);


queue queue_init()
{
    queue q = {0, NULL, NULL};
    return q;
}

int isEmpty(queue q)
{
    if(q.len == 0)
    {
        return true;
    }
    return false;
}

queue *enqueue(queue *s, int v)
{
    node *nd = malloc(sizeof(node));
    nd->v = v;
    if(s->len == 0)
    {
        s->first = nd;
        s->last = nd;
        nd->next = NULL;
        nd->prev = NULL;
    }
    else
    {
        nd->prev = s->last;
        nd->next = s->first;
        s->last->next = nd;
        s->first->prev = nd;
        s->last = nd;
    }
    s->len++;
    return s;
}

queue *dequeue(queue *s)
{
    int del_value = NULL;
    if(s->len > 0)
    {
        node *nd = s->first;
        del_value = nd->v;
        s->first = nd->next;
        s->last->next = s->first;
        s->first->prev = s->last;
        free(nd);
        s->len--;
    }
    return del_value;
}

int first(queue s)
{
    printf("Il primo nodo ha valore %d\n", s.first->v);
    return s.first->v;
}

void queue_print(queue s)
{
    node *nd = s.first;
    int i = 0;
    
    while(i<s.len)
    {
        printf("%d\n", nd->v);
        nd = nd->next; 
        i++;
    }
}


void main()
{
    queue s = queue_init();
    int i;
    for(i=0; i < 5; i++)
    {
        enqueue(&s, i*10);
    }
    queue_print(s);
    dequeue(&s);
    dequeue(&s);
    first(s);
}