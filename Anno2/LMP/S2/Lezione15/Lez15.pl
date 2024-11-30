/*Lezione 15 - La passeggiata del cavallo*/

/*Cerchiamo di risolvere il problema della passeggiata del cavallo. Sia una scacchiera k*k, con un cavallo posizionato ai vertici. Costruisci un predicato
che, data una lista di mosse, verifichino se soddisfano la passeggiata del cavallo(il cavallo percorre tutti gli spazi, senza tornare due volte sulla stessa casella.)*/

/*Osserviamo, prima di tutto, che una mossa ((xi, yi), (xj, yj)) è valida solo se (|xi - xj|= 2 AND |yi - yj| = 1) OR (|xi - xj| = 1 AND |yi - yj| = 2). */

/* Mia soluzione*/

controllomossa([XI, YI], [XJ, YJ]):-
    A is abs(XI-XJ),
    B is abs(YI-YJ),
    A is 2,
    B is 1.


controllomossa([XI, YI], [XJ, YJ]):-
    A is abs(XI-XJ),
    B is abs(YI-YJ),
    A is 1,
    B is 2.

controllosoluzione([_|[]]).

controllosoluzione(H1, H2|T):-
    controllomossa(H1, H2),
    controllosoluzione([H2|T]).

/*NB: nel controllo della correttezza delle mosse, funziona. Ma non controlla le mosse ripetute.*/

/*Soluzione tutor*/

controllo_unicita(_, []).

/*L'operatore '/' segnala che sto prendendo una tupla di due valori.*/

controllo_unicita(A/B, [A/C|T]):-
    B =\= C,
    controllo_unicita(A/B, T).

controllo_unicita(A/B, [C/B|T]):-   
    A=\= C
    controllo_unicita(A/B, T).

controllo_unicita(A/B, [C/D|T]):-
    A =\= C,
    B =\= D,
    
controllo_unicita_tot([]).

controllo_unicita_tot([M|T]):-
    controllo_unicita(M, T),
    controllo_unicita_tot(T).

mossa_valida(A/B, C/D):-
    abs(A-C, 1),
    abs(B-D, 2).

mossa_valida(A/B, C/D):-
    abs(A-C, 2),
    abs(B-D, 1).


controllo_mosse([]).

controllo_mosse([M1, M2|T]):-
    mossa_valida(M1, M2),
    controllo_mosse([M2|T]).


controllo_soluzione([M1|T]):-
    controllo_unicita(M1, T),
    controllo_mosse([M1|T]).






