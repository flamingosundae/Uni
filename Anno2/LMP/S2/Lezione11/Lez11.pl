/* Lezione 11 - Smooth Operator */

/*Una questione fondamentale nella programmazione dichiarativa è stata la manipolazione dell'albero di interpretazione. Ma come viene costruito uno in primis?
Come facciamo che dia precedenza a date operazioni? Osserviamo.

Presa la relazione: * > \ > + > -, possiamo associare una priorità implicita associando a ciascun operatore un intero, tale che * = 100, \ = 200, + = 300, - = 400.
Al momento della stesura dell'albero, dovremmo controllare che non ci sia nessun intero più basso in uno dei rami, per ogni intero nell'albero.
Un operatore si comporrà quindi di 3 parti: la sua funzione, la sua priorità interpretativa, e la sua apparenza.*/


/*Prendiamo quindi una notazione che ci permetta di incanalare tutti questi aspetti: la Polish Notation, e.g. +(2, *(3,5)).
Possiamo usare un predicato op(priorità, , nome)
                                          ^
                                          |
                                          |
                                          !
                                          !
                                uno tra(fx, xfx, xfy, yfx). Definisce il modo in cui gli operati interagiscono tra di loro.
                
*/


:-op(300, xfx, ha).
:-op(200, xfx, di).

mario ha macchina di dario.
giovanni ha panino.
elena ha panino di giovanni.
gennaro ha (borsa di pelle) di nonna.

/*Introduciamo il predicato predefinito var(X): è vero se X è variabile. Fallirà, ovviamente, se X ha un valore associato(e quindi è una costante).
Il suo negato è nonvar(X).*/

/*Definiamo il predicato ordina(X, LX), con X lista e LX lista X ordinata.*/

ordina(X, LX):-
    nonvar(X).



/*Per casa: scrivi il problema delle 8 regine in prolog. Ti servirà rappresentare la scacchiera, la posizione delle regine, e come disporle sulla scacchiera.*/
