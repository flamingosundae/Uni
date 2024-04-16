#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct pos_tree
{
    char *a; //puntatore al primo elemento dell'albero.
    int d;//grado dell'albero.
    int len;//numero totale di nodi dell'albero.
};
typedef struct pos_tree pos_tree;

pos_tree pos_tree_init(int d, int len);
pos_tree *add_node(pos_tree *t,char c);
char find_father(pos_tree t, int child_pos);
char find_children(pos_tree t, int parent_pos);

pos_tree pos_tree_init(int d, int len)
{
    pos_tree t = {NULL, 0, 0};
    t.len = len;
    t.d = d;
    t.a = malloc(sizeof(char)*len);

    return t;
}

pos_tree *add_node(pos_tree *t, char c)
{
    t->len++;
    t->a = realloc(t->a, sizeof(char) * t->len);
    t->a[t->len-1] = c;
    return t;
}

char find_father(pos_tree t, int child_pos)
{
    int parent_pos = floor((child_pos-1)/t.d);
    return t.a[parent_pos];
}

char find_children(pos_tree t, int parent_pos)
{
    int j;
    for(j=1; j<t.d; j++)
    {
        if(parent_pos+j<t.len)
        {
            print("Figlio del nodo %c in posizione %d con valore %c\n", t.a[parent_pos], parent_pos+j, t.a[parent_pos+j]);
        }
    }
}