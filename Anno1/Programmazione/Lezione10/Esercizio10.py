def init_list(n, v = lambda v: 0):
    '''
    input: un intero n, e una funzione, v.
    output: una lista di lunghezza n che in posizione i contiene v(i). Se v non è specificata, la lista sarà composta di n zeri.
    '''
    l = []
    for i in range(n):
        l.append(v(i)) #rispetto alla concatenazione necessaria per init_tuple (costo n^2), l'append rende la funzione drasticamente più efficiente (1 per ogni append * n = costo n).
    
    return l


print(init_list(10))


def rem_none(l):
    '''
    input: una lista, l.
    output: la lista di input con tutti gli oggetti None rimossi.
    '''
    a = 0
    while a < len(l):
        if l[a] == None:
            del(l[a])
        else:
            a += 1
    
    return l


test_L = [None, 'Alessio', (22, 11), None, 3, 'Python', None]
print(rem_none(test_L))


