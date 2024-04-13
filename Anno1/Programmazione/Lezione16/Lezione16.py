 #In[] costo computazionale

#ritorniamo sull'esercizio 15.


def hist(a, bins):
    n = len(bins)+1 #costo costante(rispetto ad n e m), con 3 op elementari: lettura di len, somma, e assegnazione a variabile.
    h = [0] * len(bins)#costo lineare, con una definizione di n elementi della lista e circa n operazioni.

    for v in a: #Costo lineare. tutte le operazioni nel blocco verranno ripetute m volte. (Nota: non circa, sicuramente m volte.)
        i = 0 #costo costante(rispetto ad n e m). 2 operazioni.
        while v >= bins[i] and i < len(bins): #costo lineare. Nel caso peggiore, viene eseguita l'istruzione n volte. (n-1, ma deve entrare nel while per fare check che sia verificato per n-1.)
            i += 1 #costo costante. Esattamente come sotto, due operazioni.
        h[i] += 1 #costo costante(rispetto ad n e m). 2 operazioni, espressione e assegnazione. 

    return h #costo costante. 

print(hist([10, 20, 11], [0, 1, 2]))

#quale sarà il suo costo operativo totale? Studiamo istruzione per istruzione.
#il costo finale, elidendo tutto tranne il termine di grado massimo, è n per m, nel caso peggiore. (Calcolo per n, m  tendenti ad infinito. Ecco perché le costanti sono irrilevanti.)

#In[] operazioni a costo 1:

#tutte le operazioni aritmetiche, booleane, di confronto e di lettura/scrittura hanno costo unitario, se operate su dati scalari.
#il calcolo del costo dell'algoritmo non è altro che studiare l'ordine di grandezza della somma di tutte le operazioni unitarie, il tutto nel caso peggiore.
#tutto questo discorso, tuttavia, è ovviamente diverso per dati strutturati, come liste, tuple, stringhe, ecc.
#per esempio, per concatenare due liste, il costo sarebbe dato dal complessivo costo di operazioni di copia/scrittura della lista n e della successiva lista m. Nel caso peggiore, O(n+m).
#nota che un unico dato non ha un costo automaticamente associato. Se calcolassimo, per esempio, len(bins) con un ciclo, il costo sarebbe  O(n). Ma come dato di fatto, con una buona impostazione, O(1).

# In[] considerazioni sul costo

#Il costo del nostro hist, correntemente, è quadratico (per a == bins). Possiamo abbatterlo?
#Riuscire a renderlo costante è abbastanza irrealistico. Ma possiamo portarlo a O(log2n x n).

#possiamo fare ciò usando il metodo della bisezione, ossia prendendo due valori per cui f(n) < 0 e f(n) > 0, per poi guardare nel mezzo.
#se è positiva, la ricerca continua verso il valore <0, e se è negativa per >0.
