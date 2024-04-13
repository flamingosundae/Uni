/*Sia un grafo di n nodi. Costruiamo una regola path(x,y) vera se esiste un cammino tra i nodi.
 *Cominciamo a definire il grafo, partendo dal definire gli archi con dei fatti.*/

/* edge(S,E) Prototipo di regola */
/*Costruiamo il concetto di path tramite induzione.*/
/*
Passo base
path(X,Y):-
    edge(X,Y).

Passo induttivo
path(X,Y):-
    path(X,Z),
    path(Z,Y).
Questa versione funziona su nodi adiacenti, ma va in ricorsione infinita su nodi distanti, in
quanto non ha un caso base per la definizione di path.*/

/*Versione corretta*/
/*PB*/
path(X,Y):-
    edge(X,Y).

/*PI*/
path(X,Y):-
    edge(X,Z),
    path(Z,Y).


edge(a,b).
edge(b,c).
edge(c,d).
edge(a,e).
edge(e,f).
edge(f,c).
edge(f,k).



/*Come funziona l'algoritmo risolutivo di Prolog?
 * Al momento di query fornisco un goal da soddisfare, e.g ?-edge(A,B) (Esiste un arco tra A e B variabili?).
 * Il goal viene risolto dall'alto verso il basso, da sinistra verso destra.
 * Con variabili, il programma unifica progressivamente, costruendo un albero delle soluzioni(Sempre alto verso basso, sinistra verso destra).
 * Se scambiamo i goal del PI la query genererà induzione infinita.
 * è fondamentale L'ORDINE in cui impostiamo i goal per una risoluzione di un dato predicato.
 * Esistono due letture della regola di prolog: la parte sx è vera se la parte dx lo è(Lettura puramente logica).
 * Altrimenti: goal a sx soddisfatto se lo sono i goal a dx(lettura semiprocedurale).
 * Come lo dimostriamo? Consideriamo le nostre regole base di inferenza in questo nuovo contesto.
 * 'Per ogni' usato al momento di unificazione(quantificatore logico).
 * L'altra riguarda il goal che vogliamo dimostrare, e per dimostrarlo possiamo considerare il processo risolutivo
 * come 'modus ponens al contrario' . L'algoritmpo di risoluzione del prolog è quindi basato su un albero delle dimostrazioni
 * stanziato sui fatti a nostra disposizione. */ 