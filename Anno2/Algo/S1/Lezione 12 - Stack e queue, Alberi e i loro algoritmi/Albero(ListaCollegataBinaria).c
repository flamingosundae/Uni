#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

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

// Funzione principale
int main()
{
    struct TreeNode *root = NULL;

    // Inserimento di alcuni valori nell'albero
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Attraversamento in-order
    printf("Attraversamento in-order dell'albero: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
