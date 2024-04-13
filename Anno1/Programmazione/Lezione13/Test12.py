#In[] domande primo test.

'''
1)Per quali valori di condizione0 e condizione1 la funzione restituisce True?

def f(condizione0, condizione1):
    if condizione0 and not condizione1:
        return condizione1
    elif condizione1:
        return False
    return True

A)True, True
B)True, False
C)False, True 
D)False, False
E)Nessuno

La risposta è D). è l'unico caso in cui accediamo ad un ramo a ritorno true. Il primo ramo ritornerà sempre False, così come il secondo. Di conseguenza, l'unico caso in cui
avremo True sarà con questa specifica combinazione di valori.

'''

'''
2)Sia n un intero positivo, qual è il valore di i+j al termine
del seguente codice?

i, j = 0, 2*n
while i < j:
i += 1
j -= 1

A)2n-1
B)0
C)n-1
D)2n
E)N


'''