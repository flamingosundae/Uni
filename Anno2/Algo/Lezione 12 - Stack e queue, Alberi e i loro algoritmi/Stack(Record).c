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
struct stack
{
    int len; //numero di record nello stack.
    node *first; //puntatore al primo record dello stack.
    node *last; //puntatore all'ultimo record dello stack.
};
typedef struct stack stack;

stack stack_init();
int isEmpty(stack s);
stack *stack_push(stack *s, int v);
stack *stack_pop(stack *s);
int stack_top(stack s);
void stack_print(stack s);


stack stack_init()
{
    stack s = {0, NULL, NULL};
    return s;
}

int isEmpty(stack s)
{
    if(s.len == 0)
    {
        return true;
    }
    return false;
}

stack *stack_push(stack *s, int v)
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

stack *stack_pop(stack *s)
{
    
    if(s->len > 0)
    {
        node *nd = s->last;
        printf("Hai rimosso il valore %d\n", s->last->v);
        s->last = nd->prev;
        s->last->next = s->first;
        s->first->prev = s->last;
        free(nd);
        s->len--;
    }
    return s;
}

int stack_top(stack s)
{
    printf("Il primo nodo ha valore %d\n", s.first->v);
    return s.first->v;
}

void stack_print(stack s)
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
    stack s = stack_init();
    int i;
    for(i=0; i < 5; i++)
    {
        stack_push(&s, i*10);
    }
    stack_print(s);
    stack_pop(&s);
    stack_pop(&s);
    stack_top(s);
}