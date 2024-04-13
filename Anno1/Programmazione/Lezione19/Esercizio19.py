import os

#In[] esercizio18-1 reloaded

def initial_d(a):
    '''
    Input: a, una lista di stringhe.
    Output: un dizionario che abbia per chiavi le iniziali delle diverse stringhe.
    Ogni chiave è associata alle stringhe di a con quell'iniziale.
    '''
    d = {}

    for i in a:
        if i == '':
            continue
        k = i[0]
        d[k] = d.get(k, [])
        d[k].append(i)
        
    

    return d

a = initial_d(['python', 'pitone', 'alessio', 'balessio', 'cane'])
print(a)


#In[] esercizio18-2 reloaded

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
            ris[nome] = ris.get(nome, [])
            ris[nome].append(voto)
        
        f.close()
                
    
    return ris

a = analizza_test('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione18\\FileTest')
print(a)
#In[] esercizio18-2 remix reloaded
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
            ris[nome] = ris.get(nome, 0)
            if voto in punteggio.keys():
                ris[nome] += punteggio[voto]
        
        f.close()
                
    return ris

a = analizza_test_adv('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione18\\FileTest')
print(a)
#il costo di questa versione, come la precedente, è O(n), con n linearmente dipendente dalle dimensioni dei file analizzati(num di lines).


