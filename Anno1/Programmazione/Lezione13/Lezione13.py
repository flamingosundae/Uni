#In[] funzioni con output dipendente da altre funzioni.

def g(x, y):
    return 0 if x < y else 1

def f(k):
    n = k**2
    return g(n,k) #sebbene sia molto semplice, questa funzione ci permette di analizzare l'ordine e la priorità di apertura e chiusura dei framework.
#1) Il framework principale viene aperto. 2)Viene invocata f. Viene aperto un framework locale e sospeso quello principale. 3)f invoca g. Il framework f viene sospeso e viene aperto il framework g. 4) Il framework g compie il suo lavoro e viene chiuso. 5)Stesso per f. 6)Viene riaperto il framework principale.



print(f(9))

#In[] #funzioni ricorsive.

def f(n):
    if n <= 0:
        return 0
    else:
        return 1 + f(n-1)

print(f(2))

#questa è una prima di funzione ricorsiva, ossia una funzione definita ed instanziata da sé stessa. 
#una prima condizione fondamentale è che non possiamo richiamare una funzione ricorsiva usando lo stesso valore di input dell'invocazione iniziale. Creare funzioni infinite, altrimenti, è estremamente facile. 
#l'altra condizione fondamentale è che ad un certo punto la funzione converga ad un risultato. Per esempio, sopra, f(n) non converge se n<0.
#alcune analisi sulla funzione: aprirà k framework e occuperà k spazio in memoria (la funzione ha costo computazionale 1, costante, che viene ripetuto k volte. Quindi 1*k= k). 

#In[]

def max_ric(a):
    '''
    input: una lista di numeri.
    output: il max() della lista.
    consegna: deve essere ricorsiva. E non usare max(), ovviamente.
    '''
    n = len(a)
    if n == 1:
        return a[0]
    else:
        m = max_ric(a[1:])
        if a[0] > m:
            return a[0]
        else:
            return m
     
#le funzioni ricorsive seguono tutte, all'incirca, lo stesso pattern: o abbiamo il caso base, con return immediato, o abbiamo il caso ricorsivo, dove invochiamo la funzione su un sample più piccolo di uno stesso input. 
#il costo computazionale della funzione è n^2. (Più precisamente, è costituito da invocazioni a costo 1, 2....n). 