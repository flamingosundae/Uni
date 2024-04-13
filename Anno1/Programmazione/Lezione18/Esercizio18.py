
import os 
#In[] esercizio1

def initial_d(a):
    '''
    Input: a, una lista di stringhe.
    Output: un dizionario che abbia per chiavi le iniziali delle diverse stringhe.
    Ogni chiave è associata alle stringhe di a con quell'iniziale.
    '''
    d = {}

    for i in a:
        if i[0] in d.keys():
            d[i[0]].append(i)
        else:
            d[i[0]] = [i, ]
    

    return d

a = initial_d(['python', 'pitone', 'alessio', 'balessio', 'cane'])
print(a)

#In[] esercizio2

def analizza_test(c):
    '''
    input: una cartella contenente i file con gli esiti dei test.
    output: un dizionario che contenga i risultati conseguiti da ciascun studente, nel formato studente: voto.
    '''
    ris = {}
    dir = os.listdir(c)

    for file in dir:
        path = os.path.join(c, file)
        f = open(path)
        for line in f:
            split = line.split(';')
            nome = split[0]
            voto = int(split[1])
            if nome in ris.keys():
                ris[nome].append(voto)
            else:
                ris[nome] = [voto, ]
                
    
    return ris

a = analizza_test('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione18\\FileTest')
print(a)
    
#In[] esercizio2-remix!

def analizza_test_adv(c):
    '''
    input: una cartella contenente i file con gli esiti dei test.
    output: un dizionario che contenga i risultati conseguiti da ciascun studente, nel formato studente: voto finale(come somma di tutti i contributi).
    '''
    ris = {}
    dir = os.listdir(c)
    punteggio = {6 : 0.3, 7:0.4, 8:0.6, 9:1, 10:1.5}

    for file in dir:
        path = os.path.join(c, file)
        f = open(path)
        for line in f:
            split = line.split(';')
            nome = split[0]
            voto = int(split[1])
            if nome not in ris.keys():
                ris[nome] = 0
            if voto in punteggio.keys():
                ris[nome] += punteggio[voto]
                
    return ris

a = analizza_test_adv('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione18\\FileTest')
print(a)



#In[] esercizio1- soluzione del rossi

def dizionario_iniziali(a):
    d = {} #come per liste e tuple, O(1). 
    for x in a: #O(n), con n num.stringhe in a.
        if x == '': #O(1)
            continue #l'istruzione continue viene usata in un'istruzione di ciclo per saltare istantaneamente alla prossima iterazione del ciclo. Ci è utile, in questo caso, per evitare l'IndexError derivato dall'indicizzare una stringa vuota.
        k = x[0] #O(1)
        if k in d: #O(1)
            d[k].append(x) #O(1) per la lettura del dizionario + O(1) per l'append.
        else:
            d[k] = [x] #dipende da cosa inseriamo come valore x, ma in questo caso O(1) per la creazione della lista + O(1) per la scrittura nel dizionario.
    
    return d #O(1).

#Il costo complessivo sarà O(n), lineare in len(a) (per il ciclo for).


#In[] esercizio2- soluzione del rossi

def analizza_test_rossi(cartella):
    d = {}
    for filename in os.listdir(cartella):
        if filename.split('.')[-1] == 'csv': #step aggiuntivo per evitare che il codice controlli anche file non del test.
            filepath = os.path.join(cartella, filename)
            f = open(filepath)
            for line in f: #O(n) con n numero di righe per tutti i file
                k, v = line.split(';') #ripasso: questa è un'operazione di unpacking.
                v = int(v)
                if k in d:
                    d[k].append(v)
                else:
                    d[k] = v
            f.close() #RIRCORDATI DI CHIUDEREEEEEEEEEEEEEEEEEEEEEEEEEE
    return d

#il costo computazionale dipende, principalmente, dal numero di line. è dunque una buona misurazione far dipendere il costo dalle dimensioni complessive dei file (e non il numero).
#Costo complessivo O(n*1) = O(n). Ogni operazione per ciclo ha costo O(1).

