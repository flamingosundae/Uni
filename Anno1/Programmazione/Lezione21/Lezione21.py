#In[] bubble sort Megafunk Remix
#ora che abbiamo steso una prima struttura dell'algoritmo bubble sort, può essere bene implementarne ulteriori funzionalità.

def bubble_sort_remix(a, key, inplace = True):
    '''
    input: una lista, a, una funzione, key, e un booleano, true.
    output: la stessa lista, ordinata in base al criterio specificato da key.
    Se inplace è False, il riordinamento viene applicato ad un clone di a.
    '''

    lis = a if inplace == True else a[:]
    ordinata = False
    j = 0
    while ordinata == False:
        i = 0
        ordinata = True
        while i < len(lis)-1-j:
            if key(lis[i]) > key(lis[i+1]):
                ordinata = False
                lis[i], lis[i+1] = lis[i+1], lis[i]
            i += 1
        j += 1
    return lis


l = ['shrimple', 'joever', 'jimp', 'b', 'jope', 'cc']
M0 = bubble_sort_remix(l, key=len, inplace= False)
print(M0)
M1 = bubble_sort_remix(l, key = str, inplace= False)
print(M1)
l1 = [1, 5, 10, 3, 9, 40, 34.5, 4.13]
M2 = bubble_sort_remix(l1, key=lambda x:x, inplace=False)
print(M2)



#In[] funzioni avanzate di key.
l2 = [3, 'a', 5, 0, 'b', 'c', 'd', 9, 2, 10]

#dobbiamo usare bubble sort affinché la lista sia ordinata in ordine int-str. Gli int in ordine crescente, le str in ordine lessicografico.)

def type_sort(x):
    if type(x) in (int, float):
        return(0, x)
    else:
        return(1, x)
    

print(bubble_sort_remix(l2, key=type_sort, inplace= False))

#In[] metodi delle liste

L = [8, 1, 10, 3]
L.sort() #metodo predefinito delle liste. Opera sulla lista stessa, modificandola in ordine crescente(di default).
print(L)
L1 = sorted(L) #la funzione prende in input un iterabile(str, list, tuple, ecc.) e restituisce l'iterabile ordinato in senso crescente. Un diverso metodo di organizzazione può essere specificato con key.