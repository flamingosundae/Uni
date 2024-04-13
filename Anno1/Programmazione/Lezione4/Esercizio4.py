#In[] esercizio

#prese due stringhe, verifica se una è contenuta nell'altra, e verifica a partire da quale posizione. Altrimenti, ritorna -1.

x = 'programgrazione'
y = 'gra'
p = 0
q = 0
while p < len(x) and q < len(y):
    if p+q < len(x) and x[p+q] == y[q]:
        q += 1
    else:
        p += 1
        q = 0
#nota una modifica (operata da ChatGPT): se il codice trova una corrispondenza tra x ed y nell'ultim posizione, incorrerai in un indexError. Hence, la prima condizione, (if p+q < lenx).


if q == len(y):
    print(y, 'si trova in', x, 'a partire da', p)
elif p == len(x):
    print('-1')



#In[] versione del rossi

x = 'programmazione'
y = 'gramma'

p = 0
while p <= len(x)- len(y) and not trovato:
    q = 0
    while q < len(y) and x[p+q] == y[q]:
        q += 1
    if not(q < len(y)):
        print(y, 'compare in posizione', p, 'di', x)
        trovato = True #impostare un valore booleano è una soluzione più elegante e semplice.
        #come fare in caso ci siano due istanze di y in x? Sapendo che vogliamo solo la prima istanza di y.
        #potremmo forzare l'uscita dal ciclo impostando un valore di p follemente alto, come p = 100*len(x). Corretta, ma esteticamente e semanticamente non troppo elegante.

    
    p += 1

if not trovato:  #se trovato è false attraverso tutti i check, vuol dire che non abbiamo mai accesso al secondo branch. O, in altre parole, y non è contenuta.
    print('-1')