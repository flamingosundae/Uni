def init_tuple(n, v = None): #puoi anche usare, invece di ramificare per casi, v = lambda x:0 come default.
    '''
    input: un intero n e una funzione v.
    output: una tupla di lunghezza n che contiene v[i] in posizione i. Se non specificata v, la funzione restituisce una tupla di n zeri.
    '''
    t = ()
    if v == None:
        for i in range(n):
            t += (0, )
    else:
        for i in range(n):
            t += (v(i), )
    
    return t


print(init_tuple(10)) #tupla di test per il default.
print(init_tuple(10, lambda v: v)) #tupla con i stesso come elemento.
print(init_tuple(10, lambda v: 2 * v + 1)) #tupla per i primi 10 numeri dispari.
print(init_tuple(10, lambda v: '*' * (v+1)))#tupla per 10 stringhe non vuote di lunghezza crescente.
print(init_tuple(10, lambda v: (v, ) * 10))#tupla di tuple lunghe 10 con v in ogni posizione.

#In[] soluzione del rossi

def rossi_tuple(n, v = lambda x:0):
    t = ()
    for i in range(n):
        t += (v(i), ) #richiede i+2 operazioni. Il costo totale è sommatoria da k=1 ad n di k, ossia (n+1)n/2.
    return t

            