#In[] esercizio1
def somma_consecutiva(a):
    '''
    input: una lista di interi, a.
    output: il numero di volte in cui la somma di due elementi consecutivi è uguale al numero che li segue.
    esempio: con a = [5,3,8,6,14] la funzione dovrebbe restituire 2.
    '''
    corr = 0
    for v in range(len(a)-2):
        if a[v] + a[v+1] == a[v+2]:
            corr += 1

    return corr


a = somma_consecutiva([5, 3, 8, 6, 14])
print(a)

t1 = (1, 5)
t2 = (9, 4)
t3 = (6, 8)
t4 = (88, 12)
print(list(zip(t1, t2, t3, t4)))

#In[] soluzione del Rossi
'''
c = 0
for x in zip(a[:-2], a[1:-1], a[2:]):
    if x[2] == x[1]+x[0]:
        c += 1
'''
#versione alt (con unpacking)
def conta_somme_consecutive(a):
    c = 0
    for x, y, z in zip(a[:-2], a[1:-1], a[2:]):
        if x[2] == x[1]+x[0]:
            c += 1
    return c

a = [5, 3, 8, 6, 14]
print(conta_somme_consecutive(a))
#la versione con zip è un esperimento interessante, ma è strettamente svantaggiosa rispetto alla versione Alessio. C'è, infatti, una netta perdita in consumo di memoria(per lo slicing di 3 istanze separate).


