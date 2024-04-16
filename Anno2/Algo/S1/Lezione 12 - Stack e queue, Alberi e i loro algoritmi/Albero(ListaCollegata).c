#include <stdlib.h>
#include <stdio.h>

struct tree_node
{
    char info; //contenuto informativo del nodo.
    struct tree_node *son; //puntatore al primo figlio;
    struct tree_node *brother; //puntatore al fratello successivo.
};

typedef struct tree_node tree_node;

struct tree
{
    tree_node *root; //puntatore alla radice.
    int len; //numero di nodi totale.
};

typedef struct tree tree;

tree tree_init(char root_v);
tree add_brother(char v, tree_node nd);
tree add_son(char v, tree_node nd);


tree tree_init(char root_v)
{
    tree t = {NULL, 0};
    tree_node *nd = malloc(sizeof(tree_node));
    nd->info = root_v;
    nd->brother = NULL;
    nd->son = NULL;
    t.root = nd;
    t.len++;
    return t;
}