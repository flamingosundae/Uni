
/*Definiamo un predicato numeri(L), che unifichi la lista L con ciascuno dei numeri identificati da un fatto n(num).
Usa cut, fail, assert, retract.*/

n(11, a, la).
n(2, b, gh).
n(4,c, lp).
n(5,d, ke).
n(8,e, np).


appoggio([]).

numeri(L):-
    n(Num),
    appoggio(L),
    append(L, [Num], LN),
    retract(appoggio(L)),
    assert(appoggio(LN)),
    write(Num), nl,
    fail.


numeri(L):-
    appoggio(L),
    retract(appoggio(L)),
    assert(appoggio([])),
    write(fine), nl.


/*Tutto questo altro non è che il predicato bagof(N, n(N), L),
con la seguente sintassi:
-N: la struttura unificata finale che dovrà essere contenuta nella lista riempita L.
-n(N): l'elenco dei fatti specifici di cui vogliamo l'analisi.
-L: la lista da riepire.

setof(N, n(N), L) fa la stessa cosa, ma restituisce una lista ordinata e senza doppioni.*/

len_lista([], 0).

len_lista([_|T], N):-
    len_lista(T, M),
    N is M+1.

numero_lettere_diverse(N):-
    setof(L, (N, B)^n(N, L, B), Lista),
    len_lista(Lista, N).