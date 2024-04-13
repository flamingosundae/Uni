#Come implementare lo squared di un qualsiasi numero, senza usare lo squared?
#Un algoritmo è diviso in 3 blocchi principali: una sequenza di istruzioni elementari, un meccanismo di flusso per determinare quale sarà la prossima istruzione, e delle condizioni di arresto.
#Linguaggi COMPILATI ed INTERPRETATI: i primi vanno compilati una singola volta dal compiler, che li "traduce" e li rende eseguibili dalla macchina. Gli interpretabili vanno interpretati OGNI volta. (Pensa agli interpreti di cabina).

x = 20 #Variabile. Riferimento ad un dato caricato in memoria.
g = 5.0
print(g)
while abs(g*g - x) > 0.00001: #ciclo. Finché la condizione è rispettata, viene operato. Stiamo fondamentalmente sottraendo x a g^2, e se il risultato è inferiore a 0.00001, vuol dire che abbiamo trovato radice di x con una buona approssimazione.
    g = 0.5 * (g + x/g)
    print(g) #questo è un blocco di istruzioni, o semplicemente blocco. è riconoscibile dall'indentazione.


print("La radice quadrata di", x, "è", g)
#stringa: una sequenza di caratteri.

y = 20 #operazione di assegnazione. A sinistra una variabile, a destra un valore. Il valore viene valutato, e assegnato alla variabile.
#i tipi di dati ci servono perlopiù perché si prestano a specifici tipi di operazione non disponibili alle altre.
#la variabile acquisisce un type in assegnazione.
#l'assegnazione di valore, fondamentalmente, fa sì che abbiamo un riferimento accessibile all'oggetto caricato in memoria.
#se riassegnamo un valore ad una variabile, l'oggetto assegnato verrà sovrapposto dal nuovo.