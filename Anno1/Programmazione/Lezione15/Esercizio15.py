def hist(a, bins): #versione originale a costo n^2. è corretto, in teoria, ma è anche estremamente dispensioso in termini di risorse.
    '''
    Input: a una lista di m float e bins una lista di n-1 floats ordinati in modo crescente
    Output: una lista h di n floats tale che:
    - h[0] = numero di elementi in a < bins[0]
    - h[n-1] = numero di elementi in a >= bins[n-2]
    - per i = 1,..., n-2, h[i] = numero di elementi in a >= bins[i-1] e < bin[i]
    '''
    h = []

    for i in range(len(bins)):
        primociclo = False
        if i == 0:
            primociclo = True
        s = 0
        for m in a:
            if (m >= bins [i-1] or primociclo == True) and m < bins[i]:
                s += 1
        h.append(s)
    
    return h
#[2, 4]

#In[] versione ottimizzata, con costo lineare invece che quadratico.

def hist(a, bins):
    h = [0] * len(bins)  # Inizializza la lista h con zeri

    for m in a:
        i = 0  # Indice per scorrere gli elementi di bins
        while i < len(bins) and m >= bins[i]:  # Trova l'indice appropriato per m in bins
            i += 1
        if i > 0:  # Incrementa il conteggio corrispondente all'intervallo bin
            h[i - 1] += 1

    return h

b = hist([2.11, 1.33, 0.99, 6.55, 7.66, 3.444], [1.05, 2.5, 3.76, 4.98])
print(b)

#In[] soluzione del rossi

def hist(a, bins):
    n = len(bins)+1
    h = [0] * len(bins)

    for v in a:
        i = 0
        while v >= bins[i] and i < len(bins):
            i += 1
        if v < bins[i]:
            h[i] += 1
        else:
            h[i] += 1

    return h

print(hist([10, 20, 11], [0, 1, 2]))
