/* 1)Trova l'ultimo elemento di una lista. 
E.g
?- my_last(X,[a,b,c,d]).
X = d
*/

%PB
my_last(X,[X]).

%PI
my_last(X, [_|T]):-
    my_last(X, T).

/*2)Trova il penultimo elemento della lista.*/

%PB
my_notlast(X, [X, _]).

%PI
my_notlast(X, [_|T]):-
    my_notlast(X, T).

/*3)Trova il k-esimo elemento di una lista. 
 * ?- element_at(X,[a,b,c,d,e],3).
X = c */

%PB 
element_at(X, [X|_], 1).

%PI
element_at(X, [_|T], N):-
    element_at(X, T, M),
    N is M+1.

/*4)Trova il numero di elementi di una lista.*/
%PB
conta_elem([], 0).

%PI
conta_elem([_|T], N):-
    conta_elem(T, M),
    N is M+1.

/*5)Rovescia una lista.*/







/*6)Calcola se una lista è palindroma.*/


%PB
palindrome([_]).

%PI
palindrome([H|T]):-
    my_last(X, T),
    X is H,
    palindrome(T).

