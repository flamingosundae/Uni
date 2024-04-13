#In[] migliorare il codice
#ritorniamo su massima intersezione implementando alcuni dati aggiuntivi, come, per esempio, quante volte appare il carattere di x in y, oltre che il carattere stesso.
def massima_intersezione(x, y):
    '''
    input = x,y, due stringhe.
    output: restituisce il carattere di x che compare più volte in y, e quante volte compare.
    '''
    #questo è un docstring. Non serve solo al programmatore come riferimento: se implementato, la funzione help(nomefunzione) restituisce il docstring come guida. Fondamentale per spiegare la funzione anche ad utenti esterni.
    n_max, c_max = 0, None
    for c in x:
        n_c = 0
        for c_y in y:
            if c_y == c:
                n_c += 1
        if n_c > n_max:
            n_max = n_c
            c_max = c 
    
    return c_max, n_max #possiamo ritornare valori diversi in output semplicemente ponendoli di seguito, separati da virgola.

x, y = 'ciao', 'ramarro marrone'
r, q = massima_intersezione(x, y) #possiamo esplicitare i differenti valori in output semplicemente assegnando gli oggetti a variabili diverse. Questa operazione è definita di unpacking. 
#Nota bene che per questo processo n.variabili = n.oggetti.
if r!= None:
    print(f'Il carattere di \'{x}\'che compare più spesso in \'{y}\' è {r}, che compare {q} volte.')
else:
    print(f' \'{x}\' e \'{y}\' non hanno caratteri in comune')


#In[]

def f(*args): #il parametro formale args indica che la funzione prende in input un numero indefinito di parametri. Un esempio di funzione(*args), per esempio, è print().
    for a in args:
        print(a)


f('ciao', 9, 3.14, True)

#In[] esercizio

def print_v(*strings):
    '''
    input: un numero variabile di stringhe.
    Stampa le stringhe in verticale, una di fianco all'altra.
    output: None.
    esempio: print_v('ciao', 'python')

    cp
    iy
    at
    oh
     o
     n
    '''
    terminato = False
    r = 0 #numero di riga.
    while not terminato:
        # definiamo la riga r.
        terminato = True
        riga_r = ''
        for a in strings:
            if len(a) > r:
                riga_r += a[r]
                terminato = False #mettendo terminato = True al gate della funzione, faremo in modo che il ciclo venga ricominciato solo se c'è almeno un carattere da stampare (e terminato venga sovrascritto). è una tecnica abbastanza comune e piuttosto utile, fanne buon uso.
            else:
                riga_r += ' '
        print(riga_r)
        r += 1
    #con il codice strutturato in while True, è abbastanza semplice capire che creeremo un ciclo infinito e un muro di spazi vuoti. Dobbiamo quindi trovare il modo di far terminare il ciclo una volta esaurite tutte le stringhe.
    #soluzione 1: calcoliamo in anticipo la lunghezza massima delle stringhe. Poco efficiente, abbastanza scartabile.
    #soluzione 2: usiamo una variabile booleana per determinare se il ciclo va terminato o meno.

    #nota importante: è normale, e invero frequentissimo, che ottimizzerai una funzione. Nota però, che è assolutamente necessario, per questioni di compatibilità, non modificare l'interfaccia utente.
    #questo significa, in altre parole, che le interazioni con l'esterno devono avere sempre lo stesso nome, gli stessi parametri, e lo stesso output. Sempre.