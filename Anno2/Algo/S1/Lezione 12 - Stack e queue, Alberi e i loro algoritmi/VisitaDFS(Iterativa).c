#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// Definizione della struttura del nodo
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

// Funzione per creare un nuovo nodo
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        perror("Errore nell'allocazione di memoria per il nuovo nodo");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Funzione per inserire un nuovo nodo nell'albero binario
struct TreeNode *insertNode(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    // Inserisce casualmente a sinistra o a destra senza confrontare i valori
    if (rand() % 2 == 0)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Funzione per attraversare l'albero in-order
void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct stack_int
{
    int *a;  // puntatore al primo elemento dello stack.
    int len; // lunghezza attuale dello stack.
    int cap; // capacità massima dello stack.
};

typedef struct stack_int stack;
stack stack_init();
int isEmpty(stack s);
stack *stack_push(stack *s, int v);
int stack_pop(stack *s);
int stack_top(stack s);
void stack_print(stack s);

stack stack_init()
{
    stack s = {NULL, 0, 10};
    s.a = malloc(s.cap * sizeof(int));
    return s;
}

int isEmpty(stack s)
{
    if (s.len == 0)
    {
        return true;
    }
    return false;
}

stack *stack_push(stack *s, int v)
{
    s->len++;
    if (s->len == s->cap)
    {
        s->cap = s->cap * 2;
        s->a = realloc(s->a, sizeof(int) * s->cap);
        if (s->a == NULL)
        {
            printf("Allocazione di memoria fallita!");
        }
    }
    s->a[s->len - 1] = v;
    return s;
}

int stack_pop(stack *s)
{
    int del_value = NULL;
    if (s->len > 0)
    {
        del_value = s->a[s->len-1];
        print("Hai cancellato %d dal fondo della lista\n", del_value);
        s->len--;
        if (s->len < s->cap/4)
        {
            s->cap = s->cap / 2;
            s->a = realloc(s->a, s->cap * sizeof(int));
            if (s->a == NULL)
            {
                printf("Allocazione di memoria fallita!");
            }
        }
    }
    return del_value;
}

int stack_top(stack s)
{
    if (s.len > 0)
    {
        printf("Il primo elemento dello stack ha valore %d\n", s.a[0]);
        return s.a[0];
    }
}

void stack_print(stack s)
{
    int i;
    if (s.len > 0)
    {
        for (i = 0; i < s.len; i++)
        {
            printf("L'elemento in posizione %d dello stack è %d\n", i, s.a[i]);
        }
    }
}

void visitaDFSiter(TreeNode rt)
{
    
}

void main()
{
    stack s = stack_init();
    int i;
    for (i = 0; i <= 5; i++)
    {
        stack_push(&s, (i * 10));
    }
    stack_print(s);
    stack_top(s);
    stack_pop(&s);
    stack_pop(&s);
    stack_print(s);
}