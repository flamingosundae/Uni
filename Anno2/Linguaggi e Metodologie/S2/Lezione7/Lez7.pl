/* Lezione 7 - L'arte del dire not*/

/*Oggi ci soffermiamo sul predicato di negazione, o not. Preso per esempio il predicato amici(mario, maria), e amici(mario, pino),come esprimo "NOT amici(maria, pino)" (scrittura non corretta)?
*La risposta è nell'algoritmo di risoluzione di Prolog. Ma dobbiamo imparare a manipolarlo.*/

/*Introduciamo prima di tutto il predicato fail, il cui unico scopo è sempre essere false(e quindi esplorare un altro ramo dell'algoritmo risolutivo, permettendoci di esplorare tutto lo spazio di ricerca 
*attraverso tutte le costanti unificabili). 
Un altro strumento fondamentale sarà "!", ossia il simbolo di cut. Taglia un ramo dell'albero risolutivo.
Prendiamo un esempio, nel predicato p:- a, !, b, c. Nel momento in cui il cut viene sorpassato, impedisce di riinstanziare QUALSIASI valore prima di esso. Questo include sia variabili, che predicati.*/

f(a).
f(b).
g(a).
g(b).
g(j).
k(a).

p(A):-
    f(A),
    write('10: '),write(A), nL,
    !,
    g(A),
    write('13: '),write(A), nL,
    k(A).


fallimento_di_g(A):-
    g(A), 
    !,
    fail.

fallimento_di_g(_).

mynot(Predicato):-
    Predicato, 
    !, 
    fail.

mynot(_)

/*Negazione come fallimento: ciò che è è ciò che è scritto. Il resto è falso. Per verificare che qualcosa è falso, dobbiamo verificare che non sia mai stato scritto.
Dobbiamo quindi esplorare lo spazio di ricerca, trovando se vi è un'occorrenza del predicato. */

/*Ritorniamo sul predicato per contare le occorrenze di un elemento in una lista, usando stavolta l'aggiunta del not.*/

num_elementi(_, [], 0).
num_elementi(X, [X|T], N):-
    !,
    num_elementi(X, T, N1),
    N is N1 + 1.
num_elementi(X, [Y|T], N):-
    num_elementi(X, T, N).
