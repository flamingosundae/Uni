#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct queue
{
    int *a;  // Puntatore al primo elemento.
    int len; // Lunghezza della queue.
    int cap; // Capacità massima dello stack.
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
    queue q = {NULL, 0, 10};
    q.a = malloc(sizeof(int) * q.cap);
    if (q.a == NULL)
    {
        printf("Allocazione di memoria fallita!");
        exit(EXIT_FAILURE);
    }
    return q;
}

int isEmpty(queue q)
{
    if (q.len == 0)
    {
        return true;
    }
    return false;
}

queue *enqueue(queue *q, int v)
{
    q->len++;
    if (q->len == q->cap)
    {
        q->cap = 2 * q->cap;
        q->a = realloc(q->a, sizeof(int) * q->cap);
        if (q->a == NULL)
        {
            printf("Allocazione di memoria fallita!");
            exit(EXIT_FAILURE);
        }
    }
    q->a[q->len - 1] = v;
    return q;
}

queue *dequeue(queue *q)
{
    int del_value = NULL;
    if (q->len > 0)
    {
        del_value = q->a[0];
        printf("Hai rimosso %d dall'inizio della coda\n", q->a[0]);
        q->a = q->a + 1;
        q->len--;
        if (q->len < q->cap / 4)
        {
            q->cap = q->cap / 2;
            q->a = realloc(q->a, sizeof(int) * q->cap);
            if (q->a == NULL)
            {
                printf("Allocazione di memoria fallita!");
                exit(EXIT_FAILURE);
            }
        }
    }
    return q;
}

int first(queue q)
{
    printf("Il primo elemento della lista è %d\n", q.a[0]);
    return q.a[0];
}

void queue_print(queue q)
{
    int i;
    for (i = 0; i < q.len; i++)
    {
        printf("L'elemento in posizione %d della coda è %d\n", i, q.a[i]);
    }
}

void main()
{
    queue q = queue_init();
    int i;
    for (i = 0; i < 10; i++)
    {
        enqueue(&q, i * 10);
    }
    queue_print(q);
    dequeue(&q);
    dequeue(&q);
    first(q);
}