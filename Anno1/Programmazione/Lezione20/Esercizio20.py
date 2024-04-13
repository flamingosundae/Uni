#In[] esercizio1

def bubble_sort(a):
    '''
    input = una lista di numeri, a.
    output = la stessa lista, ordinata in senso crescente.
    '''
    j = 0
    ordinata = False
    while ordinata == False:
        i = 0
        ordinata = True
        while i < len(a)-1-j:
            if a[i] > a[i+1]:
                ordinata = False
                a[i], a[i+1] = a[i+1], a[i]
            i += 1
        j += 1
    return a


l = bubble_sort([9, 1, 3, 2, 10, 8, 4])
print(l)

#costo nel caso migliore (lista già ordinata) O(n). Costo nel caso peggiore (lista ordinata in senso decrescente) O(n^2).


#In[] esercizio2

def bubble_sort(a, inplace = True):
    '''
    input = una lista di stringhe, a, e un booleano, inplace.
    output = Se inplace è True, la stessa lista, ordinata in ordine di lunghezza delle stringhe crescente.
    Altrimenti, la modifica viene operata su una copia della lista originale.
    '''
    lis = a if inplace == True else a[:]
    ordinata = False
    j = 0
    while ordinata == False:
        i = 0
        ordinata = True
        while i < len(lis)-1-j:
            if len(lis[i]) > len(lis[i+1]):
                ordinata = False
                lis[i], lis[i+1] = lis[i+1], lis[i]
            i += 1
        j += 1
    return lis


l = bubble_sort(['shrimple', 'joever', 'jimp', 'b', 'jope', 'cc'], False)
print(l)
# %%
