
def char_finder(x, y):
    '''
    input: due stringhe x, y.
    output: il carattere di x che compare più volte in y.
    esempio: con x = 'ciao' e y = 'ramarro marrone', la funzione restituirà a.
    '''
    max_count = 0
    max_lett = 0
    curr_count = 0
    for i in range(0, len(x)):
        curr_count = 0
        for v in range(0, len(y)):
            if x[i] == y[v]:
                curr_count += 1
                if curr_count > max_count:
                    max_count = curr_count
                    max_lett = x[i]

    return max_lett        


#In[] soluzione del rossi

def massima_intersezione(x, y):
    n_max, c_max = 0, None
    for c in x:
        n_c = 0
        for c_y in y:
            if c_y == c:
                n_c += 1
        if n_c > n_max:
            n_max = n_c
            c_max = c 
    
    return c_max

a, y = 'ciao', 'ramarro marrone'
r = massima_intersezione(a, y)
if r!= None:
    print(f'Il carattere di \'{a}\'che compare più spesso in \'{y}\' è {r}')
else:
    print(f' \'{a}\' e \'{y}\' non hanno caratteri in comune')

print(massima_intersezione('ciao', 'ramarro marrone'))
#di base in realtà hai fatto la stessa identica cosa, con delle sottili differenze semantiche (l'uso del range, l'assegnazione di stringa vuota a c_max/max_lett).
#sembra irrilevante, ma assegnare per stringa vuota ti permette di filtrare i casi in cui non c'è intersezione. Senza assegnazione, il codice restituirà un errore di mancata assegnazione di valore e il return non avrà effettivi valori di output.
#inizializzare una variabile in funzione dell'input è una mossa abbastanza rischiosa, perlopiù da evitare se possibile.