#include <stdlib.h>
#include <stdio.h>

struct tree_node
{
    int info;   // contenuto informativo della cella.
    int parent; // posizione(indice) del padre.
};

typedef struct tree_node tree_node;

struct tree
{
    tree_node *a; // puntatore alla prima cella.
    int len;      // lunghezza dell'array.
};
typedef struct tree tree;

tree_node tree_node_create(int v, int p);
tree tree_create(int len);
tree *add_cell(tree *l, int v, int p);
tree_node find_parent(tree l, int c);
tree_node find_children(tree l, int p);

tree_node tree_node_create(int v, int p)
{
    tree_node c = {0, 0};
    c.info = v;
    c.parent = p;
    return c;
}

tree tree_create(int len)
{
    tree l = {NULL, 0};
    l.a = malloc(sizeof(tree_node) * len);
    l.len = len;
    return l;
}

tree *add_cell(tree *l, int v, int p)
{
    l->len++;
    l->a = realloc(l->a, sizeof(tree_node) * l->len);
    l->a[l->len - 1] = tree_node_create(v, p);
    return l;
}

tree_node find_parent(tree l, int c)
{
    tree_node parent = l.a[l.a[c].parent];
    return parent;
}

tree_node find_children(tree l, int p)
{
    int i;
    for (i = 0; i < l.len; i++)
    {
        tree_node nd = l.a[i];
        if (nd.parent == p)
        {
            printf("Figlio del nodo %d in posizione %d, con valore %d\n", p, i, nd.info);
        }
    }
}