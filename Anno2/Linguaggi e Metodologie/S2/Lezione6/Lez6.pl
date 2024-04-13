/*LEZIONE 6 - L'operatore Is */

/*Partiamo dal predicato 2+3+1=A+B. Osserviamo che al momento in cui poniamo A = 3 + 1, l'unificazione effettua due operazioni: assegna e calcola(?Rivedere).
Per forzare prolog ad effettuare una somma, dobbiamo instanziare alcune cose. In  particolare, lo facciamo tramite l'operatore is, che, prima dell'unificazione, 
effettua l'operazione richiesta. La parte destra(dell'is) deve essere istanziata completamente prima che la sinistra sia instanziabile.*/

/* Se proviamo ad instanziare la query A is 1, A is A+1, risulterà falsa. Come mai? A è già unificata con il valore. Data un valore aritmetico già noto, is risulterà true se il valore aritmetico corrisponde
con il risultato dell'espressione a destra. In questo caso, ovviamente, 1 è diverso da 2. */

/*l'operatore is viene utilizzato per l'assegnazione di valori a variabili aritmetiche. Viene utilizzato principalmente per valutare espressioni aritmetiche e unificare il risultato con una variabile.*/

/* Definiamo il predicato lung(L, Lung): è vero se Lung è uguale alla lunghezza della lista. */

%PB
lung([], 0).

%PI 
lung([_|T], N):-
    lung(T, M),
    N is M+1.

/*Fare N = M-1 è sbagliato perché predica solamente se partiamo con N già istanziato, altrimenti errore.
L'errore di non istanziazione significa che non gli abbiamo assegnato un valore.
Noi stiamo passando variabili il cui valore deve essere PREVENTIVAMENTE istanziato.*/

/*Definiamo il predicato numero di El(L, El, N): è vero se N è il numero di occorrenze di El nella lista L.*/

%PB
numerodiEl([], El, 0).

%PI
numerodiEl([El|T], El, N):-
    numerodiEl(T, El, M),
    N is M+1.

numerodiEl([_|T], El, M):-
    numerodiEl(T, El, M).

/*
numerodiEl([], _, 0).: Questa è la base del caso ricorsivo. 
Significa che se la lista è vuota, allora il numero di occorrenze di qualsiasi elemento El è 0.

numerodiEl([El|T], El, N):- numerodiEl(T, El, M), N is M+1. 
Questa è la clausola ricorsiva che gestisce il caso in cui l'elemento corrente della lista (la testa della lista, denotata da El) è uguale all'elemento che stiamo cercando. In questo caso, calcola il numero di occorrenze dell'elemento nella coda della lista (T), denotato da M, e poi incrementa M di 1 per contare l'occorrenza corrente dell'elemento. Il risultato è assegnato a N.

numerodiEl([_|T], El, M):- numerodiEl(T, El, M).: 
Questa è la clausola ricorsiva che gestisce il caso in cui l'elemento corrente della lista non è uguale all'elemento che stiamo cercando. 
In questo caso, semplicemente calcola il numero di occorrenze dell'elemento nella coda della lista e assegna il risultato a M.
*/
