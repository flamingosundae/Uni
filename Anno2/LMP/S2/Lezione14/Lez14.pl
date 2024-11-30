/*Lezione 14 - Esercitazione */

/*Affrontiamo il problema della 8 regine, che consente nel trovare una formula affinché si possano posizionare 8 regine senza che si mangino
su una scacchiera k*k t.c k>= 4. (Per k < 4 non c'è soluzione).
Partiamo dal come rappresentare il problema 
OSS. Nell'affrontare un problema, ancora prima di una soluzione, è importante capire come SCHEMATIZZARE il problema.
Rappresentiamo quindi la scacchiera come un grafo, con ogni regina un punto sul grafo di forma(xi, yi).
Date due regine di coordinate(xi, yi) e (xj, yj), per rispettare le condizioni del problema deve valere:
xi /= xj
yi /= yj
Non esiste m appartenente a [-k, k] t.c.(xi = xj + m AND yi = yj + m) OR (xi = xj - m or yi = yj + m).*/

% 8 Queens Problem
% The main predicate to solve the problem
eight_queens(Board) :-
    % Generate a list of numbers from 1 to 8
    numlist(1, 8, Rows),
    % Permute the rows to get all possible combinations
    permutation(Rows, Board),
    % Check if the queens are safe
    safe(Board).

% Check if the queens are safe
safe([]).
safe([Row|Rest]) :-
    % Check if the current queen is safe
    safe(Rest, Row, 1),
    % Check if the rest of the queens are safe
    safe(Rest).

% Check if the current queen is safe
safe([], _, _).
safe([Row|Rest], Col, Offset) :-
    % Check if the current queen is safe from attack
    Row - Col #\= Offset,
    Col - Row #\= Offset,
    % Check the next queen
    NextOffset is Offset + 1,
    safe(Rest, Col, NextOffset).

% Example usage:
% ?- eight_queens(Board).
% Board = [4, 2, 7, 3, 6, 8, 5, 1] ;
% Board = [5, 2, 4, 7, 3, 8, 6, 1] ;
% ...





diffx(A,B) :-
    r(A, X,_),
    r(B,Y, _),
    X =\= Y.

diffy(A, B) :-
 r(A, _ X),
 r(B, _, Y),
 X =\= Y.

 comp(A, B):- diffx(A,B), diffy(A,B),

 controlloriga([A, B], [A,C]).
 controllocolonna([A,B], [C,A]).
 controllodiagonale([A,B], [C,D]):-
  X is A-C,
  Y is B-D,
  X =\= Y,
  X =\= -Y.


controllocoppia([A]).

controllocoppia([A, B|T]):-
    controlloriga(A, B),
    controllocolonna(A, B),
    controllodiagonale(A, B),
    controllocoppia([A|T]).


controllosoluzione([A]).

controllosoluzione([H|T]):-
    \+controllocoppia([H|T]),
    controllosoluzione([T]).





/*Per casa: risolvi il rompicapo del cavallo(muovi un cavallo su tutte le caselle della scacchiera senza che ritorni su una casella già visitata.) Realizza un predicato che verifichi se una serie di 
movimenti soddisfano il rompicapo del cavallo per una scacchiera k*k, t.c. k>= 4.Deve partire da un vertice.*/