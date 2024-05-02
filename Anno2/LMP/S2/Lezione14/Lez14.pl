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

riga(1).
riga(2).
riga(3).
riga(4).
riga(5).
riga(6).
riga(7).
riga(8).

colonna(1).
colonna(2).
colonna(3).
colonna(4).
colonna(5).
colonna(6).
colonna(7).
colonna(8).


regina(X, Y):-
    riga(X),
    colonna(Y).


problema(Regina1(X, Y), Regina(Z, W)):-
    