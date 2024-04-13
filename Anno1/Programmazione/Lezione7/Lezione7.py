#In[] none

def none_study(x):
    if x == True:
        return 1
    else:
        return None #il None è un tipo di dato letteralmente nullo, che è diverso dal dire che non è un dato. Utile per esempio per comunicare se la funzione non ha trovato valori utili al suo compito.
    
#In[] stringhe di formato

a = 'ciao'
b = 'espressione'

print(f'La stringa a è {a} e la stringa b è {b}')
#stringa formattata. Con questa specifica sintassi, tutti i valori in graffe saranno considerati espressioni e non singoli caratteri.
print(f'La stringa a è \'{a}\' e la stringa b è \'{b}\'') 
#\ permette di stampare caratteri speciali senza che vengano considerati funzionali al codice. In questo caso, per esempio, è utile per mettere 'ciao' e 'espressione' in apici senza che il codice le legga come inizio/fine stringa.
print('prima riga \n seconda riga \t terza riga') 
#\n e \t sono caratteri speciali. \n va a capo nella stampo, \t inserisce una tabulazione.
# %%
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

#ripeschiamo questa funzione per definire il concetto di visibilità di variabile, ossia il bloicco entro il quale una variabile è riconosciuta.
#in questo esempio, n_c è visibile solo nel ciclo for. n_max, invece, in tutto l'ambiente della funzione. 

#In[] osservazioni sulla visibilità di una funzione.

def f(x):
    x += 1
    for y in range(10):
        z = y
        x += y
    return x


x = 100
y = 25
print(f(x)) 
#ritornerà 146. Nota che non stiamo incrementando x, stiamo incrementando il valore legato alla funzione locale f(x). print(x) darà comunque 100, essendo la variabile nel frame globale intatta.

#In[] radice quadrata- REVIVAL!

#riprendiamo il primo programma che abbiamo scritto e modifichiamolo per renderlo una funzione.

def squared_root(x, eps = 0.01): #abbiamo assegnato un valore di default ad eps. A meno che non sia specificato diversamente in invocazione, eps sarà assegnata a quel valore. Ciò la rende anche opzionale in input(possiamo solo specificare x). 
    g = x/2 
    print(g)
    while abs(g*g - x) > eps: #sostituendo il valore fisso 0.00...1 possiamo configurare il grado di precisione con il quale la radice quadrata viene ricercata(o in altre parole, quanto è appossimata.)
        g = 0.5 * (g + x/g)
    return g

print(squared_root(20, 0.0000000001))
print(squared_root(20))
print(squared_root(eps = 0.00000001, x = 90)) #i due esempi di sopra usano un'invocazione posizionale, dove al primo valore viene assegnata la prima variabile, al secondo valore la seconda variabile ecc. Così facendo, possiamo decidere noi l'ordine di assegnazione. Detta anche assegnazione per nome. 

#In[] parametri per la funzione print

print('prima', 'ariprima', sep = '*', end = '')