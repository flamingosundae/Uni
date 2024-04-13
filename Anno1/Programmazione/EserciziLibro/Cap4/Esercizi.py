#In[]
'''
Si faccia diventare funzione la soluzione dell'Esercizio 8 del Capitolo 2 (String Matching).
La funzione, denominata is_in, accetti due stringhe in input e restituisca un indice della prima stringa o -1.
'''
def is_in(a, b):
    substring_pos = -1
    for i in range(0, len(a)-len(b)+1):
        if a[i:len(b)+i] == b:
            substring_pos = i
            break
    
    print(b, 'si trova in', a, 'a partire dalla posizione', substring_pos)
    return substring_pos

#In[]
'''
Si scriva una funzione denominata mult che accetti uno o due int. 
Se chiamata con due argomenti, la funzione stampa il prodotto. Se chiamata con un argomento, stampa quello.
'''

def mult(x, y = None):
    if y == None:
        return x
    else:
        return x*y

#In[]

'''
Si scriva una funzione per testare is_in.
'''
def is_in(a, b):
    substring_pos = -1
    for i in range(0, len(a)-len(b)+1):
        if a[i:len(b)+i] == b:
            substring_pos = i
            break
    
    print(b, 'si trova in', a, 'a partire dalla posizione', substring_pos)
    return substring_pos

def isin_tester(*args):
    for x in range(1, len(args)):
        is_in(args[0], args[x])


isin_tester('rinoceronte', 'noce', '', 'rix')
# %%

'''
Scrivere un'espressione lambda che abbia due parametri numerici. 
Se il secondo argomento è uguale a zero, deve restituire None; altrimenti deve restituire il valore della divisione del primo argomento per il secondo.
'''

g = lambda x, y = 0 : None if y == 0 else x/y


#In[]

'''
Si scriva una espressione il cui valore sia la media di una tupla di numeri. Si usi la funzione sum.
'''

t = (1, 2, 3, 4, 5)
avg = sum(t) / len(t)
print(avg)

# %%

'''
Scrivere una comprensione di lista che generi tutti i numeri non primi fra 2 e 100.
'''
i = 0
l = [i for i in range(2, 100) if any (i%y == 0 for y in range(2, int(i**0.5)+1))]
print(l)
# %%

def f(L1, L2):
    """
    L1, L2 sono liste di numeri della stessa lunghezza
    Restituisce la somma degli elementi di L1 elevati
    alla potenza dell'elemento allo stesso indice
    in L2. Per esempio, f([1,2], [2,3]) restituisce 9
    """
    sum = 0
    for x in zip(L1, L2):
        sum += x[0]**x[1]
    
    return sum

L_a = [1, 2, 3, 4]
L_b = [2, 2, 3, 2] #Restituisce 48.

print(f(L_a, L_b))
# %%

def get_min(d):
    """
    d è un dict che mappa lettere su int
    restituisce il valore in d associato alla prima chiave
    in ordine alfabetico. Per esempio, se
    d = {'x': 11, 'b':12}, get_min(d) ritorna 12.
    """
    min_key = None
    for x in d.keys():
        if min_key == None:
            min_key = x
        if x < min_key:
            min_key = x
    return d[min_key]


d_test = {'x':11, 'b':12}
print(get_min(d_test))
# %%
def move_max( a ):
    '''
    Precondizione: a è una lista di numeri
    Sposta il massimo di a in fondo alla lista,
    gli altri elementi occuperanno le posizioni precedenti
    '''
    max_num = max(a)
    a.remove(max_num)
    a.append(max_num)
    return a



tl = [1, 8, 2, 4, 5, 6, 7]
print(move_max(tl))
# %%
'''
Cosa succede se si applicano alle tuple gli operatori di confronto? Sperimentare l'esito di confronti tra tuple. 
Utilizzando quanto appreso dai test si scriva una espressione che date due stringhe x ed y, abbia valore True se la prima è più corta della seconda, False se la seconda è più corta della 
della prima. In caso di stringhe della stessa lunghezza, l'espressione deve valere True se la prima precede la seconda nell'ordinamento lessicografico, False altrimenti.
'''

def compare_strings(a, b, key):
    key == len if len(a) != len(b) else key == str
    return key(a) < key(b)



# %%

'''
Si scriva una funzione, denominata longest, 
che riceva in input una lista di stringhe e restituisca la stringa più lunga. Nel caso di più stringhe di lunghezza massima, la funzione ritorni quella che segue le altre nell'ordinamento alfabetico.
'''

def longest(l):
    max_str = ''
    for x in l:
        if(len(x), x) > (len(max_str), max_str):
            max_str = x
    return max_str



# %%

'''
Si scriva una funzione Python, denominata sort_by_len, 
che riceva in input una lista di numeri (int o float) e la muti in modo che gli elementi siano ordinati per numero di cifre crescenti.
'''
l = [3.14, 3133, 8, 123456, 1.2345]
l.sort(key = lambda x: len(str(x)) if type(x) == int else len(str(x))-1)
print(l)
# %%

'''
Scrivere una funzione denominata inverti_dizionario che prenda in input un dizionario d e 
restituisca un dizionario d_inv che abbia per chiavi i valori in d e d_inv[v] sia la lista di chiavi che d mappa in v.
'''
def inverti_dizionario(d):
    d_inv = {}
    for x in d.keys():
        d_inv[d[x]] = x
    return d_inv

#In[]

#binary search che cerchi l'ultima occorrenza di k in una lista ordinata.
def last_occurrence_search(a, k):
    low = 0
    high = len(a) - 1
    while low <= high:
        mid = (high + low) // 2
        if a[mid] > k:
            high = mid - 1
        elif a[mid] < k:
            low = mid + 1
        else:
            return mid + 1
    return -1

l = [1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 7, 8, 9]
print(last_occurrence_search(l, 7))

# %%
