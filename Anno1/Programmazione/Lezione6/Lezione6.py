#In[] funzioni
#Funzioni: strutture che prendono un x numero (anche 0) di argomenti/valori in input e svolgono uno specifico compito. Di base in realtà ne hai già viste alcune: print, len, ecc.ecc.
#alcune funzioni sono contenute in librerie, pacchetti predefiniti da importare di funzioni che coprono uno specifico argomento/tema. E.g. Math, che contiene una serie di funzioni e strutture matematiche, come log(x), pi, ecc.ecc.
#It really is a beautiful world.

import random 
from math import cos, sin #non è detto che ci serva l'intera libreria. Così facendo, possiamo prendera una specifica funzione della libreria.
import time as t #in fase di importazione possiamo rinominare le librerie usando as. Utile se vuoi uno shorthand per le invocazioni.
print(random.random())#fornisce un numero casuale, float compresi, in [0,1).
print(random.randint(10, 20))#restituisce un intero PSEUDOcasuale nel range [a, b].
print(cos(1))
print(sin(1))
print(t.time()) #riporta il tempo passato dall'Epoch. L'Epoch è convenzionalmente la mezzanotte del primo gennaio 1970 UTC. Che bel nome Epoch.

#possiamo, ovviamente, definire anche funzioni da noi per successivo richiamo ed uso.


def str_compare(x, y):  # x ed y sono detti parametri formali della funzione.
    p = 0
    z = ''
    while p <= len(x) - len(y) and z != y:
        z = x[p: len(y) + p]
        if z == y:
            print(y, 'si trova in ', x, 'a partire da', p)
            return p
        else:
            p += 1


    if p > len(x) - len(y):
        print('Le stringhe non si contengono')
        return -1 #il return è un costrutto con il quale creiamo un output utilizzabile e decifrabile non solo dall'utente, ma anche dalla macchina.
        

#In[] invocazione della funzione

str_compare('programmazione', 'gra') #stiamo invocando la funzione, sostituendo i parametri formali con dei parametri attuali e applicando la funzione base su questa specifica istanza di oggetti.
a = 'programmazione'
b = 'zione'
str_compare(a, b) #possiamo anche usare variabili come parametri attuali.
str_compare(a, 'python')
#global framework e local framework: nel global carichiamo l'oggetto funzione e gli assegnamo un nome. Nel local invochiamo un'istanza attualizzata della funzione espressa nell'ambiente globale.
#Una volta che la funzione, per qualsiasi motivo, conclude, il framework locale viene chiuso.
t = str_compare('programmazione', 'grda') #ora che abbiamo assegnato un return, possiamo assegnare l'output ad una variabile.
if t < 0:
    print('OK')
else: 
    print('KO')


#In[] esercizio


def fattoriale_generalizzato(a, b):
    '''
    input: due interi a, b, con b>a.
    output: il prodotto di a, a+1, a+2...b-1, b.
    '''
    s = a
    for i in range(a, b+1):
        if i == b:
            print('Il fattoriale di', a, 'e', b, 'è', s)
            return s    
        else:
            s *= s+1


t = fattoriale_generalizzato(1, 2)


# %%
