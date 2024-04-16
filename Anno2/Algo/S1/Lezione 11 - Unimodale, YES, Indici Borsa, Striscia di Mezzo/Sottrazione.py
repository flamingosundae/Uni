def sottrattore_massimizzato(a):
    '''
    input: una lista di numeri.
    output: due indici i* e j*, con i*<j*, che massimizzano A[j*]-A[i*] t.c A[j*]-A[i*] > A[j]-A[i] per ogni tempo 
    '''
    i, j = 0, len(a)
    min_buy, max_sell = 0, 0
    while i < j:
        if a[i] < a[i+1]:
            min_buy = i
        if a[j] > a[j-1]:
            max_sell = j
        i += 1
        j -= 1
    return (i,j)


l = [20, 11, 2, 12, 4, 10, 9, 2]
print(sottrattore_massimizzato(l))




'''
Idea: dato i, il miglior j(che massimizza A[j]-A[i] è l'indice del massimo in A[i+1:n])
Se trovassi, dato i, detto j in tempo O(1), avrei algo a tempo O(n).
Posso precalcolare questi indici j?
Vettore Max[1:n]
Max[k]: indice del massimo in A[k,n]
Calcolo vettore Max
Sia Max[1:n] vettore di dimensione n
Max[n] = n
for k = n-1 down to 2 do
if (A[k]>A[Max[k+1]]):
Max[k] = k
else:
Max[k] = Max[k+1]


Algo corrispondente:
Vettore Max[1:n]
Max[k]: indice del massimo in A[k,n]
Calcolo vettore Max
Sia Max[1:n] vettore di dimensione n
Max[n] = n
for k = n-1 down to 2 do
if (A[k]>A[Max[k+1]]):
Max[k] = k
else:
Max[k] = Max[k+1]
i*1 = j* = Max[2]; M = A[j]-A[i]
for i = 2 to n-1:
if(A[Max[i+1]]- A[i])>M then i* = i
j* = Max[i+1]
M = A[j*]-A[i*]
return(i*, j*)
'''