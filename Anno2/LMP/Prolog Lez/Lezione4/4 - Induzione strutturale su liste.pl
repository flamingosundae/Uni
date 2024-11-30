/* Un concetto fondamentale che dovremmo introdurre sarà l'induzione strutturale. Ma per comprenderla, vanno prima introdotte
* alcune strutture dati.
* [a, b, c, d, e] è una struttura dati chiamata LISTA.
* Assegnando delle variabili in testa alla lista, e.g. [H|T] = [a, b, c, d, e], H sarà unificata con il primo valore
* della lista, mentre T verrà unificata su induzione con gli altri elementi. Quindi H=a, T= [b, c, d, e].
* [H|T] = [a], H = a, T = [](lista vuota).
* E [H|T] = []? Risulterà H = False, T = False, in quanto questa configurazione NON è unificabile. è, in altre parole,
* semplicemente impossibile.
* 
* Introduciamo ora un nuovo predicato: l'appartenenza. Data un'ipotetica lista L che useremo come insieme di appartenenza,
* dobbiamo costruire il predicato appartiene(x, L).
* Come implementarlo? Attraverso induzione strutturale. Unifichiamo la lista come una struttura [H|T], testa/coda.
* Due casi. O x unifica con H(x è l'elemento in testa. Caso base), o x appartiene a T(l'elemento appartiene alla coda.
* Caso induttivo). */

/*
*%PB
*appartiene(X, L):-
*    L = [H|T],
*    X = H.
*
*Definire una regola contentente sia il PB che il PI è erroneo, se impostiamo nel formato 'regola, regola'. , è 'E'. C'è un 'O', ma per ora teniamoci nella struttura PB-PI. 
*
*%PI
*appartiene(X,L):-
*    L = [H|T],
*    appartiene(X,T).
*   
*Sembra tecnicamente corretto. Ma è semplificabile. (Questo è il modo procedurale. Non sfruttiamo i punti di forza della
*programmazione dichiarativa, e crea incoerenze sintattiche).*/


%PB
appartiene(X, [X|_]).

appartiene(X, [_|T]):-
    appartiene(X,T).

/*
 * Come risolve il predicato?
 * Risolviamo per la prima regola. 3 non è testa della coda, quindi risulta un fail.
 * Procede a risolvere per la seconda regola(alto, verso il basso).
 * Risolve quindi appartiene(3, [3,2]), che risulterà true per la prima regola.
 * Possiamo anche unificare per più elementi.
 * E.g. [H1, H2 | T] = [a, b, c]
 * H1 = a
 * H2 = b
 * T = [c] */

%Proviamo ora a descrivere il predicato concatena(A,B,C), che risulta vero se C è prodotto della concatenazione di A e B.
%PB
concatenazione([],A,A).

%PI
concatenazione([H|T], B, [H|L]):-
    concatenazione(T, B, L).
  