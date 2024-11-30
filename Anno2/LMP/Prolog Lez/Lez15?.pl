/*Lezione 15 - La passeggiata del cavallo*/

/*Cerchiamo di risolvere il problema della passeggiata del cavallo. Sia una scacchiera k*k, con un cavallo posizionato ai vertici. Costruisci un predicato
che, data una lista di mosse, verifichino se soddisfano la passeggiata del cavallo(il cavallo percorre tutti gli spazi, senza tornare due volte sulla stessa casella.)

/*Osserviamo, prima di tutto, che una mossa ((xi, yi), (xj, yj)) è valida solo se (|xi - xj|= 2 AND |yi - yj| = 1) OR (|xi - xj| = 1 AND |yi - yj| = 2). 