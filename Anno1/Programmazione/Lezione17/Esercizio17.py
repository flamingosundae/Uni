def bin_search(k, bins):
    '''
    Sia n la lunghezza di bins.
    Output: 0 se k < bins[0], n se k >= bins[n-1], i se bins[i-1] <= k < bins[i].
    '''

    n = len(bins) + 1

    if k < bins[0]:
        return 0
    if k >= bins[n-2]:
        return n-1        
    lx, rx = 0, n-1
    trovato = False
    while not trovato:
        cx = ((lx+rx)//2)  #lo scenario specifico in cui il codice si blocca in un ciclo infinito è quando cx = 0, che, per l'impostazione del codice, è un valore per cui abbiamo già calcolato (riga 9). Una soluzione può essere impostare cx come max(1, lx+rx//2), che evita che venga impostato a 0 ed incorra nel conseguente ciclo infinito.
        #la soluzione è corretta, ma non la più elegante.
        if k >= bins[cx-1]  and k < bins[cx]:
            trovato = True
        elif k >= bins[cx]:
            lx = cx + 1
        else:
            rx = cx - 1
    
    return cx

print(bin_search(23 , [6, 8, 12, 23]))



def hist(a, bins): #ora che abbiamo un modo più efficiente di suddividere gli elementi della lista nei loro segmenti di appartenenza, possiamo ritornare ad esaminare la funzione hist.
    n = len(bins)+1
    h = [0] * n

    for v in a:
       i = bin_search(v, bins) #O(log2n)
       h[i] += 1

    return h

print(hist([1, 3, -8, 10, 12, 9, 50, 21], [0, 10, 20, 30])) #il costo finale di questa versione è O(m x logn)
#Nel caso migliore (istanze specifiche in cui bin_search acquisisce costo costante), O(m).
