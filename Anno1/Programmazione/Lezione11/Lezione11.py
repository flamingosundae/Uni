# In[] operatore in

print(5 in (4, 2, 9, 'ciao')) #l'operatore in restituisce un booleano true o false a seconda che l'elemento a sinistra sia contenuto nel dato a destra o meno.
print(2 in [3, 5, 2, 'python']) #qualsiasi tipo di dato strutturato accetta in.
print([2, 9] in [4, 2, 9, 'ciao']) #ritornerà false. La tupla (2, 9) dovrebbe essere specificamente contenuta nella lista.

# In[] #min, max, sum.
#eseguono operazioni su determinate sequenze di dati. (Liste, tuple, ma anche banalmente insiemi di numeri).

a = [1, 4, 5, 3, 0]

print(max(a)) #ritorna il massimo della lista. Ovviamente, perché funzioni, i tipi di dato nella lista devono essere confrontabili.
print(min(a)) #ritorna il minimo della lista.
print(sum(a)) #ritorna la somma di tutti gli elementi della lista.

#In[] esercizio guidato.

def sommatoria(a, k):
    somma = 0
    for i in range(k):
        somma += a[i]
    return somma



def media_incrementale(a):
    '''
    input: una lista di numeri(int, float), a.
    output: una lista che in posizione i contenga la media dei primi i+1 numeri.  
    '''

    l = []

    for i in range(len(a)):
        l.append(sommatoria(a, i+1/(i+1))) #questa funzione è tecnicamente corretta, ma ha un costo computazione suboptimale per l'ovvio problema di dover creare una sottolista (lo slicing) e risommarla ogni volta, che è ovviamente piuttosto dispendioso.
        #usare una funzione per il calcolo della somma preventivo risparmia il dover creare un len(a) numero di copie della lista a. Tuttavia, ha comunque costo computazionale n^2 per le n operazioni di somma() + le n operazioni del ciclo. Alla fine, non così diverso.


    return l



def media_incrementale_adv(a):
    '''
    input: una lista di numeri(int, float), a.
    output: una lista che in posizione i contenga la media dei primi i+1 numeri.  
    '''

    l, somma = [], 0

    for i in range(len(a)):
        l.append((somma+a[i])/(i+1)) #non è ancora una forma perfetta, ma c'è già un ottimo miglioramento, con un numero di operazioni fisso ad ogni iter del ciclo(2, somma e divisione). Il costo totale passa da n^2 a n, che è ovviamente drasticamente più rapido. 
        somma += a[i]


    return l


#In[]

a = [10, 10, 10, 5, 5, 0]
b = a #il motivo per cui, subito sotto, abbiamo un errore, è che in questa operazione NON stiamo creando una nuova lista, ma assegnando una nuova variabile alla preesistente, come una sorta di alias. Questo processo, appunto, è detto aliasing.
b[1] = 'casa'
print(sum(a))
c = a[:] #sfruttando le proprietà delle liste, possiamo clonare una lista preesistente.


def make_none(a):
    for i in range(len(a)):
        a[i] = None
    
x = [1, 2, 3, 4, 5, 6]
make_none(x)