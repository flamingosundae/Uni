def list_merge(a, b):
    '''
    input: due liste ordinate di numeri, a e b.
    output: l'unione delle due liste, ordinata in senso crescente.
    '''
    l = []
    l.extend(a)
    l.extend(b)
    l.sort()
    return l

c = list_merge([1, 3, 5, 9, 88], [4, 21, 23, 105])
print(c)

#In[] una versione che per qualche motivo non usa il sort

def list_merge_remix(a, b):
    '''
    input: due liste ordinate di numeri, a e b.
    output: l'unione delle due liste, ordinata in senso crescente.
    '''
    l = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            l.append(a[i])
            i += 1
        else:
            l.append(b[j])
            j += 1
    if i == len(a):
        l.extend(b[j:])
    elif j == len(b):
        l.extend(a[i:])
    
    return l 
 

c = list_merge_remix([1, 3, 5, 7, 9], [2, 5, 14, 20])
print(c)

#In[] versione del rossi


def list_merge_remix(a, b):
    '''
    input: due liste ordinate di numeri, a e b.
    output: l'unione delle due liste, ordinata in senso crescente.
    '''
    l = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            l.append(a[i])
            i += 1
        else:
            l.append(b[j])
            j += 1
    if i == len(a):
        t, k = b, j
    else:
        t, k = a, i
    
    while k < len(t):
        c.append(t[k])
        k += 1
    
    return l 
 
#la versione con extend è efficiente e funzionale, ma ha un problema fondamentale: lo slicing richiesto rischia di occupare inutilmente una grande quantità di memoria, rendendola spazialmente poco pratica.