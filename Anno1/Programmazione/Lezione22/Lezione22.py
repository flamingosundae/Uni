def merge(a, lx, cx, rx):
    '''
    input: una lista di elementi confrontabili con <=., con
    a[lx:cx] e a[cx:rx] ordinati.
    output: la lista a, modificata di modo che a[lx:rx] sia ordinata.
    '''
    l = []
    i, j = lx, cx
    while i < cx and j < rx:
        if a[i] < a[j]:
            l.append(a[i])
            i += 1
        else:
            l.append(a[j])
            j += 1
    
    
    if i == cx:
        k, last_index = j, rx
    else:
        k, last_index= i, cx
    
    while k < last_index:
        l.append(a[k])
        k += 1

    for t in range(rx-lx):
        a[lx+t] = l[t]
    



def merge_sort(a, lx, rx):
    if rx == lx or rx == lx+1:
        return a
    
    cx = (rx+lx)//2
    merge_sort(a, lx, cx)
    merge_sort(a, cx, rx)
    merge(a, lx, cx, rx)