#In[] ottimizzazione di esercizio15

#ritorniamo ancora una volta sull'esercizio della lezione 15, implementando il metodo di bisezione che avevamo menzionato nella lezione 16. 

def bin_search(k, bins):
    '''
    Sia n la lunghezza di bins.
    Output: 0 se k < bins[0], n se k >= bins[n-1], i se bins[i-1] <= k < bins[i].
    '''

    n = len(bins) + 1

    if k < bins[0]:
        return 0
    if k > bins[n-2]:
        return n-1        
    lx, rx = 0, n
    trovato = False
    while not trovato:
        cx = (lx+rx)//2  #con questa assegnazione, cx è il segmento mediano tra lx e rx
        if k >= bins[cx-1]  and k < bins[cx]:
            trovato = True
        elif k < bins[cx-1]:
            rx = cx-1
        else:
            lx = cx + 1
    
    return cx

print(bin_search(6, [6, 8, 12, 23]))