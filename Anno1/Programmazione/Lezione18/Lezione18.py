#In[] funzione list

#non dissimilmente da tuple(), la funzione list() ci permette di typecastare il parametro in input come lista.
#esattamente come tuple, serve un dato iterabile in input.
t = (1, 5, 8, 23, 12)
a = list(t) #costo computazionale O(n), con n numero di elementi del dato in input.
print(a)
string = 'python'
b = list(string)
#anche range è un iterabile.
k = range(1, 10)
c = list(k)
print(c)

# In[] comprensione di lista(list comprehension)
#possiamo inizializzare le liste anche fornendo un valore in input e iterando su di esso per una determinata quantità di volte.

a = [i**2 for i in range(10)]

#In[] dizionari
#un dizionario è un insieme di strutture, definite in due parti: una chiave, ed il corrispondente valore.
#le chiavi sono univoche. Ciò significa che per ogni chiave esiste un valore, e viceversa.
#in termini di funzioni, possiamo affermare che chiavi e valori hanno un rapporto iniettivo.

d = {} #dizionario vuoto.
d1 = {'k0':6, 'k1': 'python', 6: 3.14}
#nota che l'unica restrizione sul tipo di dato nei dizionari è che le chiavi siano dati immutabili. Per il resto, tutto è concesso.
print(d1['k1'])#stampa il valore corrispondente alla chiave.
print(d1['k9'])#fornisce KeyError, in quanto la chiave non esiste.
if 'k9' in d1:
    print(d1['k9'])
else:
    d1['k9'] = 'cappanove'

print(d1)

d1[6] = 'sei'
print(d1[6]) #i dizionari supportano la sovrascrittura del valore associato ad una data chiave.

del(d1[6]) #elimina la coppia chiave-valore.
d1['L'] = 1
d1['L'].append(0) #entrambi i metodi di cui sopra hanno O(1) e permettono la creazione di una chiave e la conseguente assegnazione di un valore.
print(len(d1))

d1['k2'] = 6

print(d1.keys(), d1.values()) #i metodi keys() e values(), abbastanza intuitivamente, restituiscono rispettivamente tutte le chiavi o tutti i valori di un dato dizionario.