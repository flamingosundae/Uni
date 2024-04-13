#include <stdio.h>
#include <stdlib.h>

//Come implementare un array di C che abbia al suo interno elementi disomogenei in quanto a type?
//La soluzione è abbastanza semplice. Invece di creare un array di elementi, creeremo un array di puntatori a elementi che in questo modo, potranno avere type diverso.

struct object
{
    char type; //i per int, c per char, s per stringa.
    void *pointer;
};

typedef struct object object;
void set(object*, int, object);

void main()
{
    int i;
    char a[] = "programmazione";
    object L[10];
    
    L[0].pointer = malloc(sizeof(int));
    *((int*)L[0].pointer) = 3;
    L[0].type = 'i';

    L[1].pointer = malloc(sizeof(char));
    *((char*)L[1].pointer) = 'x';
    L[1].type = 'c';

    L[2].pointer = (void*)a;
    L[2].type = 's';

    for(i = 0; i < 3; i++)
    {
        if(L[i].type == 'i')
        {
            printf("%d\n", *((char*)L[i].pointer));
        }
        else if(L[i].type == 'c')
        {
            printf("%c\n", *((char*)L[i].pointer));
        }
        else 
        {
            printf("%s\n",(char*)L[i].type);
        }
    }
}


void set(object *L, int p, object e){
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