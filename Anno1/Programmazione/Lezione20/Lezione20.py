#In[] analizza_test, ma senza dizionari

#Quale sarebbe il costo computazionale di analizza_test(esercizio 19), se non usassimo dizionari, ma liste?

import os

def analizza_test_liste(c):
    punteggio = [0, 0, 0, 0, 0, 0.3, 0.4, 0.6, 1, 1.5]
    d = [] #la lista con i risultati degli studenti. Sarà formata da liste di coppie di elementi nel formato (studente, voto).
    for filename in os.listdir(c):
        path = os.path.join(c, filename)
        if os.path.isfile(path) and filename.split('.')[-1] == 'csv':
            f = open(path)
            for line in f:
                nome, v = line.split(';')
                voto = punteggio[int(v)]
                trovato, i = False, 0
                while not trovato and i < len(d):
                    if d[i][0] == nome:
                        d[i][1] += voto
                        trovato = True
                    i += 1
                if not trovato:
                    d.append([nome, voto])
    return d

#costo computazionale O(n^2)

#In[] ordinamento e bubble sorting

#gli algoritmi di ordinamento sono una parte fondamentale nell'incremento dell'efficienza di un dato codice.
#molto spesso, a parità di operazioni eseguite, operare su dei dati già ordinati rispetto ad un certo criterio sarà inerentemente più computazionalmente efficiente rispetto all'operare su dei dati non organizzati.
 
a = [10, 1, 24, 3, 90, 10, 11, 5]

for j in range(len(a)-1):
    i = 0
    while i < len(a)-1:
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i] #se ci fermassimo a len(a) l'ultimo elemento sarebbe fuori dalla lista, con l'IndexError che ne deriva.
    i += 1




#In[] bubble sort- revisione
#l'algoritmo, ora come ora, è funzionale, ma ha una criticità fondamentale in termini di efficienza: non è detto che servano n*j operazioni per riordinare la lista. Potrebbe essere ultimata già prima.
#ci serve quindi un parametro che ci assicuri che il ciclo non sia reiterato se la lista è già ordinata.


ordinata = False

while not ordinata:
    ordinata = True 
    i = 0
    while i < len(a) - 1 - i:
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]
            ordinata = False
        i += 1