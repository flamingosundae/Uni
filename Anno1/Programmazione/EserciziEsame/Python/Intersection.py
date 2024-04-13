def intersection(a, b):
    '''
    input: due dizionari, a e b.
    output: una lista delle chiavi presenti sia in a che in b.
    '''
    d = {}
    l = {}
    for x in a.keys():
        d[x] = d.get(x, 0)
        d[x] += 1
    for x in b.keys():
        d[x] = d.get(x,0)
        d[x] += 1
    
    for x in d.keys():
        if d[x] == 2:
            l.append(x)
        
    return l