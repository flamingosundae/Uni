def ricerca_unimodale(l):
#dato un array unimodale, trova l'indice del massimo.











#per le invarianti dell'array posso dire in tempo costante se A[i] è il massimo, o devo cercare a destra e sinistra di esso.
'''
Algo MaxRic(A, i, j)
if i > j:
return - 1
m = i+j//2
if A[m] > A[m-1] and A[m] > A[m+1]:
return m
if A[m] < A[m+1]:
return MaxRic(A, m+1, j)
else
return MaxRic(A, i, m-1)
Problema di overflow! Possibile che confrontiamo l'ultima/prima posizione con un elemento che non esiste.

Alt senza questo problema:
Algo Max(A):
n = len(a)
if A[1] > A[2]
return 1
if A[n] > A[n-1]
return n
return MaxRic(A, 2, n-1)
'''

'''
E per l'ordinamento?
Semplicemente un processo di merge dove usiamo la metà crescente o la metà decrescente.
In alternatica, usiamo un
Algo OrdinaUnimodale(A):
n = len(A)
m = Max(A)
if m =/ -1 and m!= n:
inverti(A, m, n)
if m != 1:
Merge(A, 1, m-1, n)

'''