import random as rn
#In[]
def merge( a, lx, cx, rx ):
    '''
    Parameters
    ----------
    a : lista di valori confrontabili con < 
        con a[lx:cx] e a[cx:rx] ordinati
        lx<cx<rx
    
    Output: muta a in modo tale che a[lx:rx] sia ordinata 
    '''
    
    c = []
    i, j = lx, cx
    
    # sia n = len(a)
    # sia m = rx-lx
    
    confronti = 0
    
    while i < cx and j < rx: # eseguito <= m volte
        if a[i] < a[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(a[j])
            j += 1
        confronti += 1
        
    if i == cx:
        k, last_index = j, rx
    else:
        k, last_index = i, cx
    
    while k < last_index: # costo O(m)
        c.append(a[k])
        k += 1
        
    #a = a[:lx] + c + a[rx:] # costo O(n), non va bene!!!!
    
    for t in range(rx-lx): # costo O(m)
        a[lx+t] = c[t]
        
    return confronti


def merge_sort(a, lx=0, rx=None):
    '''
    Parameters
    ----------
    a : lista di elementi per cui vale la relazione <
    lx < rx : int, indici in a
    Returns
    -------
    Muta a in modo tale che a[lx:rx] sia ordinata con <
    '''
    
    if rx == None:
        rx = len(a)
    
    if rx  == lx  or rx == lx+1:
        return 0
    
    cx = (rx+lx)//2
    c0 = merge_sort(a, lx, cx)
    c1 = merge_sort(a, cx, rx)
    c2 = merge(a, lx, cx, rx)
    return c2+c0+c1
    
# In[] Bubble Sort

def bubble_sort(b):
    '''
    Input:  a, una lista di str; inplace un bool
    Output: ordina le stringhe in a dalla più corta alla più lunga, ritorna la lista ordinata.
    	Se inplace è True la funzione muta a, altrimenti viene restituita una nuova lista
    	con le stringhe di a ordinate come richiesto
    '''
    
    ordinata = False
    j = 0
    n = len(b)
    
    confronti = 0

    while not ordinata:
        ordinata = True
        i = 0
        while i < n-1-j:
            confronti += 1
            if b[i] > b[i+1]:
                # se la lista è ordinata non entro
                b[i], b[i+1] = b[i+1], b[i]
                ordinata = False
            i += 1
        j += 1  
        
    return confronti


# In[]

def test_0(da = 100, a = 500, step = 100):
    f = open('tests.csv', 'w')
    for n in range(da, a, step):
        print(n)
        for i in range(100):
            L0 = [rn.random() for x in range(n)]
            L1 = L0[:]
            n_bubble_sort = bubble_sort(L0)
            n_merge_sort = merge_sort(L1)
            f.write( f'{n}; {n_bubble_sort}; {n_merge_sort}\n')
    f.close()


# In[]

def test_1(da = 100, a = 500, step = 100):
    C = {}
    for n in range(da, a, step):
        print(n)
        for i in range(100):
            L0 = [rn.random() for x in range(n)]
            L1 = L0[:]
            n_bubble_sort = bubble_sort(L0)
            n_merge_sort = merge_sort(L1)
            if n in C:
                C[n] = ( C[n][0] + n_bubble_sort/100, C[n][1]+ n_merge_sort/100 )
            else:
                C[n] = (n_bubble_sort/100, n_merge_sort/100)
    return C
print(test_1(da = 10, a = 200, step = 10))
#In[] funzioni di matplotlib
import matplotlib
import matplotlib.pyplot as plt

c = test_1(da = 10, a = 200, step = 10)
x = c.keys()
y0 = []
y1 = []
for v in c.values():
    y0.append(v[0])
    y1.append(v[1])

plt.plot(x, y0, c= 'r', label = 'bubble sort') #la funzione plot prende in input due sequenze di dati e restituisce un grafico di coordinate (x,y). Affinché funzioni, il numero di dati della prima e della seconda sequenza devono corrispondere.
plt.plot(x, y1, c= 'cyan', label = 'merge sort') #la funzione plot ha molteplici parametri che migliorano la leggibilità del grafico, come colore della curva e nome di riferimento nella legenda.
plt.legend()
plt.xlabel('dimensione lista') #con xlabel e ylabel, assegnamo un nome ai rispettivi assi.
plt.ylabel('numero confronti')

#In[] try...except

try:
    c[250] = c[250] + 1
except(KeyError):
    c[250] = 0  #il blocco try... except permette di gestire più efficientemente le eccezioni, assegnando un caso base(try) e un caso di errore, nel quale viene effettuata un'istruzione diversa (except).



#In[] funzione zip
a = [1, 3, 5, 9]
b = [2, 4, 6, 8]
c = [11, 12, 14, 18]
d = zip(a,b,c)#la funzione zip prende in input degli iterabili e ritorna un iterabile composto da tuple della forma [(a[0], b[0], c[0]), (a[1], b[1], c[1]) e così via.
#il risultato può essere usato da un istruzione di iterazione, come un ciclo for o while.
for v in d:
    print(v)

list(d)
