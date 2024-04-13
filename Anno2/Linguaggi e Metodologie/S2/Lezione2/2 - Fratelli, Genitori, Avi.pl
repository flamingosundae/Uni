fratello(X,Y):-
    genitore(Z,X),
    genitore(Z,Y).
/*Significa "X è fratello di y" se "Z è genitore di X", "Z è genitore di Y".*/

nonno(X,Y):-
    genitore(X,Z),
    genitore(Z,Y).
/*"X è nonno di Y" se "X è genitore di Z" e "Z è genitore di Y".*/

avo(X,Y):-
    genitore(X,Z),
    avo(Z,Y).
/*"X è avo di Y" se "X è genitore di Z" e "Z è avo di Y".*/

/*Queste sono le regole.*/

genitore(mario, dario).
genitore(mario, gino).
genitore(pino, rino).

/*Sto assegnando mario come genitore di dario e gino, nonché pino come genitore di rino.*/
/*Questi sono i fatti.*/
/*NIENTE TERMINI PROCEDURALI!*/