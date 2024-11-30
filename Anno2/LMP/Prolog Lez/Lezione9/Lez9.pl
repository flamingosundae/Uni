/* Lezione 9 - Assert e retract per la programmazione dinamica.
Usiamo gli assert e retract per implementare la programmazione dinamica, in modo da guadagnare tempo in fase di esecuzione.

Definiamo il predicato fib(N, M), vero se f(N) = f(N-1) + f(N-2) 
è M. */
:-dynamic fib/2.
fib(2,1).
fib(1,1).
fib(N, M):-
    write(in(N, M)), nl,
    X is N-1,
    Y is N-2,
    X > 0,
    Y > 0, /*Aggiunto affinché fib non predichi all'infinito sottraendo fino agli interi negativi.*/
    fib(X, A),
    fib(Y, B),
    M is A+B,
    asserta(fib(N, M)).
/*assert è un predicato che viene utilizzato per aggiungere un fatto o una regola al database di Prolog durante l'esecuzione del programma. 
Questo è noto come programmazione logica dinamica. 
asserta è simile, ma aggiunge i fatti/regole all'inizio del database, non la fine.*/

/*listing(x) legge tutti i fatti e le regole relative al determinato predicato x, e le stampa. Nota che listing estrae le proprie informazioni dal DATABASE di Prolog, a 
cui abbiamo aggiunto i fatti e regole di fib con assert(fib(N, M)). C'è un problema, tuttavia. Al momento della query, il predicato viene asserito anche se già presente, che 
porta a ripetizioni nel database.
Come risolvere? Dobbiamo far sì che il predicato sia vero, sia vero una SOLA volta(e non venga quindi reinserito).
La potenza di questo codice non è nel meccanismo dichiarativo di prolog, ma nel CONTROLLO del meccanismo dell'albero di risoluzione per velocizzare le query.*/