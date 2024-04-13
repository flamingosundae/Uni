import random as ran

#In[] algoritmo merge-sort

def merge(a, lx, cx, rx):
    '''
    input: una lista di elementi confrontabili con <=., con
    a[lx:cx] e a[cx:rx] ordinati.
    output: la lista a, modificata di modo che a[lx:rx] sia ordinata.
    '''
    merge_confronti = 0
    l = []
    i, j = lx, cx
    while i < cx and j < rx:
        merge_confronti += 1
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
    
    return merge_confronti
    



def merge_sort(a, lx = None, rx = None):
    if lx == None and rx == None:
        lx, rx = 0, len(a)
    if rx == lx or rx == lx+1:
        return 0
    
    cx = (rx+lx)//2
    c0 = merge_sort(a, lx, cx)
    c1 = merge_sort(a, cx, rx)
    c2 = merge(a, lx, cx, rx)

    return c0+c1+c2



def bubble_sort_remix(a, key, inplace = True):
    '''
    input: una lista, a, una funzione, key, e un booleano, true.
    output: la stessa lista, ordinata in base al criterio specificato da key.
    Se inplace è False, il riordinamento viene applicato ad un clone di a.
    '''

    lis = a if inplace == True else a[:]
    ordinata = False
    bubble_confronti = 0
    j = 0
    while ordinata == False:
        i = 0
        ordinata = True
        while i < len(lis)-1-j:
            bubble_confronti += 1
            if key(lis[i]) > key(lis[i+1]):
                ordinata = False
                lis[i], lis[i+1] = lis[i+1], lis[i]
            i += 1
        j += 1
    return bubble_confronti
#In[] esercizio 1

def test_confronti():
    f = open('test.csv', 'w')
    for a in range(0, 10):
        l = []
        for b in range(0, ran.randint(0, 20)):
            l.append(ran.randint(0, 30))
        ris1 = bubble_sort_remix(l, key = int, inplace= False)
        ris2 = merge_sort(l)
        f.write(f'{len(l)}; {ris1};  {ris2}\n')
    f.close()


#In[] esercizio2

def dict_confronti():
    d = {}
    for a in range(0, 10):
        l = []
        for v in range(0, ran.randint(0, 20)):
            l.append(ran.randint(0, 30))
        b = bubble_sort_remix(l, key = int, inplace= False)
        m = merge_sort(l)
        n = len(l)
        d[n] = d.get(n, (b, m))
    return d

test = dict_confronti()
print(test)
