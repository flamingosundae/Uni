#In[] tuple
#La tupla è una sequenza di elementi. Tutto qui. Possono essere di tipo diverso tra loro, ma non è necessario.

t = (1, 0, 'python', 3.45, True, (0,1,3))
print(t)

x = t[2] #la tupla, esattamente come le stringhe, supporta l'indicizzazione dei suoi elementi.
print(x)
y = t[1:4] #stesso discorso vale per lo slicing di oggetti.
z = t[::-1]#anche a step negativo.
t[2] = 4 #proprio come le stringhe, la tupla NON supporta riassegnazione di valori. In altre parole, è immutabile.
a0, a1, a2, a3, a4, a5 = t #infine, le tuple supportano l'unpacking.

#In[] esercizio guidato

def str_cmp(x, y):
    '''
    input: x, y, due stringhe.
    output: ritorna -1 se x precede y, 0 se x è uguale a y, +1 se y se precede x.
    '''
    if x < y:
        return -1 #non diversamente da int e float, le stringhe supportano gli operatori relazionali. Il loro confronto verrà effettuato sulla base della loro posizione nell'ordinamento lessicografico.
    if x == y:
        return 0
    return 1 #stiamo sfruttando il fatto che il return termini la funzione per evitare di porre un altro controllo. 

print(str_cmp('Addio', 'addio')) #ritornerà -1. Nel codice ASCII, le maiuscole hanno posizione precedente alle minuscole, sempre e comunque.

#In[] esercizio guidato-2
#come sopra, ma comparando la lunghezza.
def len_cmp(x, y):
    if len(x) < len(y):
        return -1
    elif len(x) == len(y):
        return 0
    return 1

#In[] funzioni come parametri
#se volessimo creare una funzione che alterni fra le due "modalità" di confronto?

def id(x):
    return x


def str_cmp_adv(x, y, key= None): #possiamo usare, esattamente come gli altri tipi di dato, una funzione come parametro formale/attuale.
    if key == None:
        x0, y0 = x, y
    else:
        x0, y0 = key(x), key(y)

    if x0 < y0:
        return -1
    if x0 == y0:
        return 0
    return 1

print(str_cmp_adv('Ciao', 'Python', len))
print(str_cmp_adv('Ciao', 'Python', str)) #se volessimo comparare direttamente le stringhe in ordine lessicografico.
print(str_cmp_adv('Ciao', 'Python', id))#creando una funzione apposita che restituisca lo stesso identico dato.
print(str_cmp_adv('Ciao', 'Python')) #impostando la funzione su un parametro di default possiamo risolvere il problema di cui sopra.
#Possiamo, alternativamente, impostare Key come None e fare distinzioni nel codice in base al valore di key in invocazione.

#In[] espressioni condizionali
#un altro modo di switchare fra le varie modalità d'uso è implementare le cosiddette espressioni condizionali.

def str_cmp_adv(x, y, key= None):

    x0, y0 = (x, y) if key == None else (key(x), key(y)) #espressione condizionale. Se la condizione è rispettata, assume valore x, altrimenti valore key(x).
    if x0 < y0:
        return -1
    if x0 == y0:
        return 0
    return 1

#In[] esercizio guidato-3
'''
input: due stringhe x, ed y. 
output: -1 se x[0] < y[0], 0 se x[0] == y[0], +1 altrimenti.
requirement: usare str_cmp.
'''
def str_cmp_adv(x, y, key= None):

    x0, y0 = (x, y) if key == None else (key(x), key(y)) #espressione condizionale. Se la condizione è rispettata, assume valore x, altrimenti valore key(x).
    if x0 < y0:
        return -1
    if x0 == y0:
        return 0
    return 1

def primo_elemento(x):
    return x[0]

print(str_cmp('ciao', 'python', primo_elemento)) #questo è il modo più ovvio.

#In[] funzioni lambda
#ma possiamo anche usare le funzioni lambda, funzioni ad uso rapido con un compito solitamente abbastanza semplice-
print((lambda x: x+1)(1))#la struttura è (def parametro formale: corpo)(parametro attuale).
f = lambda x: x**2 + 2*x + 6 #possiamo comunque assegnare una variabile ad una funzione lambda.

def str_cmp_adv(x, y, key= lambda x: x): #così facendo possiamo anche assegnare un nuovo modo di restituire l'identità x.
    if key(x) < key(y):
        return -1
    if key(x) == key(y):
        return 0
    return 1



print(str_cmp('ciao', 'python', lambda x: x[0]))

#In[] funzioni per le stringhe

a = 'python'

print(a.islower()) #metodo per le stringhe. Ritorna un booleano True se la stringa è solo di caratteri minuscoli.

t = (0,1,0)

print(t.count(0)) #restituisce il numero di volte in cui il dato compare nella tupla.