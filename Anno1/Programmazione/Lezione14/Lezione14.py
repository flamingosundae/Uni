#In[] esercizio guidato

a = [1, [3, 7], 5, [8, 9]]
b = a[:]
#un'osservazione importante sulla clonazione di liste è che in caso di annidamento, la clonazione si applica solo al primo livello. Le liste interne, invece, subiscono un processo di aliasing rispetto alle originali.
#in base a questo, creiamo una funzione che svolga clonazione profonda su una data lista.

def deep_clone(a):
    b = []
    for x in a:
        if type(x) == list:
            b.append(deep_clone(x))
        else:
            b.append(x)
    return b

c = deep_clone(a)
print(c)


#In[] modulo os

import os #una libreria di funzioni e metodi per interagire con il sistema operativo.

cartella = os.listdir()#fornisce una lista di stringhe contenenti i nomi dei file della cartella in input.
#in mancanza di parametri di input, il valore di default è la cartella corrente.

for x in cartella:
    if os.path.isdir(x): #isdir prende in input una stringa(specificamente il path del file) e ritorna true se il path è associato ad una cartella. False altrimenti.
        print(f'DIR: {x}')
    elif os.path.isfile(x): #isfile funziona esattamente come isdir ma ritorna true se la stringa del path è associata al percorso di un file. False altrimenti.
        print(f'FILE: {x}')

#e se volessi leggere tutti i file nelle sottocartelle?

def browse_dir(d):
    cartella = os.listdir(d)

    for x in cartella:
        fullpath = os.path.join(d, x) #la funzione join prende in input un numero variabile di stringhe path e le unisce tra di loro per creare un unico percorso.
        if os.path.isfile(fullpath):
            print(f'FILE: {fullpath}')
        elif os.path.isdir(fullpath):
            browse_dir(fullpath)
        

browse_dir(os.getcwd())
#piccola nota su join, e in generale per la libreria os, è che il risultato non è universale. Anche solo l'aspetto e le convenzioni usate per il path variano a seconda dell'os. Tienilo a mente, potrebbe essere rilevante più avanti.
