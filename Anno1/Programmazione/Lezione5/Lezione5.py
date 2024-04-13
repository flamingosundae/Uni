#In[] break

x = True

while x == True:
    break #esce istantaneamente dal ciclo più interno(se ce ne sono di innestati). è un'istruzione di salto incondizionato, che modifica incondizionalmente il flusso. Super controversa, ma puoi usarla, sparingly. Meglio trovare una condizione, in ogni caso.

#In[] slicing

#possiamo definire lo slicing come una generalizzazione dell'indicizzazione. Estrae una stringa usando due valori forniti(tecnicamente 3 con lo step, vabbé).

x = 'programmazione'
y = x[1:4] #ricorda che lo slicing ha intervallo [,)! In questo printerà quindi 'rog' (1, 2, 3).
#lo slicing crea una nuova stringa.
z = x[:9]#se il valore di sinistra viene omesso, lo slicing partirà da 0. Se viene omesso quello di destra, arriverà a len(x).
p = x[:] #se non specificati i valori, restituirà una copia originale.
q = x[::2]#specificando lo step, puoi far sì che lo slicing consideri intervalli di selezione.
k = x[9:1:-1]#lo step può essere negativo, ma devi far sì che il valore iniziale sia maggiore di quello finale. Così facendo, prendi la stringa al contrario.
print(x)
print(y)
print(z)
#notabilmente, anche se prendi un index maggiore di len(str), lo slicing fornisce una str fino all'ultimo valore disponibile.
