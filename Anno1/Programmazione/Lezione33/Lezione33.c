#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct object
{
    char type; //i per int, c per char, s per stringa.
    void *pointer;
};

struct list
{
    object *a;
    int n; //dimensione della lista.
};


typedef struct object object;
typedef struct list list;


void set(object*, int, object);
object int_create(int);
object char_create(char);
object str_alias(char*);
object str_clone(char*);
void print_list(list);

void set(object *L, int p, object e)
{
	L[p].type = e.type;
	if (L[p].type == 'i'){
		L[p].pointer = malloc(sizeof(int));
		*((int*)(L[p].pointer)) = *((int*)e.pointer);
	} else if (L[p].type == 'c'){
		L[p].pointer = malloc(sizeof(char));
		*((char*)(L[p].pointer)) = *((char*)e.pointer);
	} else {// è una stringa
		L[p].pointer = malloc( sizeof(char)*(strlen((char*)e.pointer)+1) );
		strcpy( e.pointer, L[p].pointer);
	}
}



object int_create(int v)
{
    object ob = {'i', NULL};
    ob.pointer = malloc(sizeof(int));
    *((int*)(ob.pointer)) = v;
    return ob;

}

object char_create(char v)
{
    object ob = {'c', NULL};
    ob.pointer = malloc(sizeof(char));
    *((char*)(ob.pointer)) = v;
    return ob;
}

object str_alias(char *v)
{
    object ob = {'s', NULL};
    ob.pointer = v; //1 di 2 possibili soluzioni. Così facendo, rendiamo ob.pointer un alias invece che un clone della stringa.O(1), spaziale e temporale.
    return ob;
}

object str_clone(char *v)
{
    object ob = {'s', NULL};
    ob.pointer = malloc(sizeof(char) * (strlen(v)+1)); //soluzione 2 di 2. Così facendo, cloniamo direttamente la stringa. O(n) in n strlen(v), spaziale e temporale.
    //l'assunto, qui, è che str(len(v)) sia irrisoria rispetto alle dimensioni della lista.
    ob.pointer = strcpy(ob.pointer, v);
    return ob; 

}


void print_list(list L)
{
    int i;
    printf("[");
    for(i = 0; i < L.n; i++)
    {
        if(L.a[i].type == 'i')
        {
            printf("%d\n", *((char*)L.a[i].pointer));
        }
        else if(L.a[i].type == 'c')
        {
            printf("%c\n", *((char*)L.a[i].pointer));
        }
        else 
        {
            printf("%s\n",(char*)L.a[i].type);
        }
    }
    printf("]\n");
    
}



void main()
{

    list L = {NULL, 10};
    object L[10];
    char a[] = "programmazione";
    L.a[0] = int_create(4);
    L.a[1] = char_create('x');
    L.a[2] = str_alias("Questa non è una lista Python");
    L.a[3] = str_clone(a);

    print_list(L);
}