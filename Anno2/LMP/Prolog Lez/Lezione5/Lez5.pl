/* - INDUZIONE STRUTTURALE, LA VENDETTA */


/*Ritorniamo sulle liste, soffermandoci di nuovo sull'induzione strutturale. Abbiamo svolto appartenenza e concatenazione.
Passiamo ora al reverse/rivoltato.

prototipo: rivoltata(L, RL) -> vero se RL è la lista L rivoltata.*/

/*
%PB 
rivoltata([H|_], [_|H]).

%PI
rivoltata([_|T], [L|_]):-
    rivoltata(T, L).

Questa soluzione manca della parte fondamentale che ci permetta di verificare se rivoltata è vero: la capacità di prendere l'ultimo elemento.
*/

/*Introduciamo quindi la regola append, vera se una lista L è formata da tutti i suoi n-1 elementi più un ultimo elemento in coda.*/

%PB
rivoltata([], []).

%PI 
rivoltata([H|T], RL):-
    append(RT, [H], RL),
    rivoltata(T, RT).


/*Passiamo, successivamente, alla regola di permutazione.
Permutazione(A,B) è vera se B contiene tutti gli elementi di A in qualsiasi ordine .*/

%PB
appartiene(X, [X|_]).

%PI
appartiene(X, [_|T]):-
    appartiene(X,T).

%PB
permutazione([], []).

%PI
permutazione([H|T], B):-
    permutazione(T, PT1_2),
    appartiene(H, B),
    subtract(H, B, PT1_2).

/*Subtract sarà vera se sussiste la seguente relazione fra PT1_2 e B.*/

subtract(_, [], []). 
/*Per far sì che la regola sia vera anche in caso l'elemento non appartenga, inseriamo un predicato per liste vuote.*/

%PB
subtract(H, [H|R], R).

%PI
subtract(H, [A|R1], [A|R2]):-
    subtract(H, R1, R2).
