#include <stdlib.h>
#include <stdio.h>

struct int_array
{
    int *a;
    int size;
};

typedef struct int_array int_array;

void int_array_cat(int_array *v0, int_array v1);

void int_array_cat(int_array *v0, int_array v1)
{
    int i;
    v0->size = v0->size + v1.size;
    v0->a = realloc(v0->a, sizeof(int) * v0->size);

    for (i = 0; i < v1.size; i++)
    {
        v0->a[v0->size - v1.size + i] = v1.a[i];
    }
}

int main()
{
    int i;
    int_array a;
    a.size = 4;
    a.a = malloc(sizeof(int) * a.size);
    a.a[0] = 0;
    a.a[1] = 1;
    a.a[2] = 2;
    a.a[3] = 3;

    int_array b;
    b.size = 4;
    b.a = malloc(sizeof(int) * b.size);
    b.a[0] = 4;
    b.a[1] = 5;
    b.a[2] = 6;
    b.a[3] = 7;

    int_array_cat(&a, b);

    for (i = 0; i < a.size; i++)
    {
        printf("%d\n", a.a[i]);
    }

    free(a.a);
    free(b.a); // Aggiunto per liberare la memoria allocata per b.a
    return 0;
}