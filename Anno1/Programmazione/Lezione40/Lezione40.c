#include <stdio.h>
#include <stdlib.h>

//Esame: correzioni

/*1) Si consideri un dizionario in C mediante liste di trabocca, n elementi in dizionario, m liste. Quale affermazione deve essere vera? 

A)Dimensione di ogni lista n/m. CORRETTA!
B)Hash casuale. Ovviamente no, deve essere deterministico per un accesso efficiente. Data una chiave, devo accedere sempre alla stessa lista.
C)N/m costante. Vera, ma non sufficiente.
D)Metà lista meno di 4 elementi. Ovviamente falsa. Magari nell'altra metà c'è un numero enorme.

2)Sia a una variabile intera a cui assegnazione n. Valore c a termine codice? 
Hai risposto bene. Era 2*n. Incrementiamo a nel pezzo di codice, ma abbiamo salvato c prima.

3) Sia L una lista implementata in C. Ogni nodo contiene un intero. Sai il massimo.Complessità? 
Lineare. Gli elementi sono ordinati, ma devi comunque scorrere tutti gli altri elementi.

4)Sia n un intero positivo. Qual è la complessità temporale? 
Lineare in tutti i casi. Hai risposto bene. Diocane.
E se la Malloc non andasse a buon fine? Complessità costante! Ritornerebbe semplicemente NULL.

5)Si consideri la struttura dati lista(o array dinamico) di n elementi come definita a lezione. Qual è complessità temporale dell'operazione di inserimento di un nuovo elemento in posizione p?
A)Costante nel caso medio.
B)Lineare in p nel caso peggiore.
C)Lineare in n-p. CORRETTA! Devi traslare tutti gli elementi a destra fino alla posizione p.
D)Costante nel caso peggiore. 

6) Sia h la funzione hash utilizzata nell'implementazione di un dizionario in C mediante liste di trabocco. Sia m il numero di liste nel dizionario e n il numero di elementi. Quale di queste proprietà NON è vera?
A)Il codominio di h sono gli interi tra 0 e m-1.
B)Il dominio di h è l'insieme delle chiavi del dizionario.
C)H deve essere deterministica.
D)Il dominio di h sono gli interi tra 0 e m-1. FALSA! Il dominio di h sono le chiavi del dizionario. Idiota. 

7)Sia n un intero positivo e a la stringa definita dal seguente frammento di codice. Quanto vale strlen(a)?
Al più n/2. La stringa può essere indefinita in tratti. Hai risposto bene, bravo! Idiota. 

8)Sia L una lista concatenata implementata in C. Ogni nodo contiene un intero ed il puntatore al nodo successivo oppure NULL se è l'ultimo nodo.
L è una struct che contiene il puntatore al primo nodo della lista, il numero di elementi della lista ed il puntatore al nodo contenente il minimo elemento della lista.
Quale sarebbe la complessità temporale di una funzione efficiente che elimina il nodo contenente il minimo?
A)Logaritmica.
B)Lineare. CORRETTA! Devo comunque scannerizzare l'interezza della lista, per modificarla in modo da conservarne le proprietà. 
C)Costante.
D)Quadratica. 

9)La somma delle cifre in a. Avevi risposto bene, nonostante il Rossi sia un coglione stupido.

10)Si consideri il seguente codice C.

Int a[123] = {0};
int *b = a;
Quale tra le seguenti affermazioni è vera?
A)sizeof(a) == sizeof(b).
B)sizeof(a) < sizeof(b).
C)sizeof(a) > sizeof(b). CORRETTA! Ovviamente l'array avrà dimensioni maggiori del singolo puntatore a int. Per promemoria, sizeof(a) = sizeof(int(4)) * 123 e sizeof(b) = sizeof(*int(8)) .
D)A[2] è indefinito. NO, CRETINO! A[2] è 0. Hai inizializzato un elemento dell'array, quindi tutti quelli non specificati saranno 0. Sarebbe undefined se NON avessimo inizializzato qualcosa. */





//Ora basta esami. Si parla di union. Non quelle lavorative.
//Non diversamente dalle struct, usiamo union per definire tipi di dato. Ma, nel loro caso, contengono un elemento di cui il tipo può cambiare a seconda delle necessità.
//Nota che la union, data una combinazione di tipi di dato, avrà una sizeof corrispondente a quella del tipo che occupa più spazio. E.g. con una union di char e float, occuperà 4 byte.

void main()
{
  union
  {
    char c_val;
    int i_val;
    float f_val;
  } u; //Questa è la variabile associata alla union. 
  

  u.i_val= 8;

  printf("%d\n", u.i_val);
  //Potrei leggere il campo c_val, ma avrei un risultato undefined. Leggerei un dato a 4 byte come un char, prendendone quindi solo il primo. In questo caso mi printa 8, ma solo perché può essere rappresentato da un solo byte.

  u.c_val = 'a'; //Ora che l'ho definito, printerà invece effettivamente a.
  printf("%c\n", u.c_val); 

  u.f_val = 3.14;
  printf("%f\n", u.f_val);
}
