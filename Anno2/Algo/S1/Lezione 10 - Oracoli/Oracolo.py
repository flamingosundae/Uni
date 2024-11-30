#vettore ausiliario Y che dato un vettore X contenga in posizione Y[i] il numero di elementi di x maggiori uguali di i.

def OraBuilder(x):
    y = []
    for i in range(1, len(x)):
        










'''
Idea: costruire in O(n+k) un array di Y di dimensione k
dove Y[i] è il numero di elementi in X che sono <= i. (Nella mia versione >=i, ma non cambia significativamente).

Implementazione di integer sort, dove in Y[i] c'è somma totale di tutti i numeri >=/<= del numero preso in considerazione(calcolato precednetemente)
più occorrenze del numero attuale.

Pseudo codice:
OraBuilder(X, k)
Y = [], lenght = k
for i=1 to k do Y[i]=0
for i=1 to n do incrementa Y[X[i]]
for i=2 to k do Y[i]=Y[i]+Y[i-1]
return Y

OraQuery(Y, k, a, b)
if b>k return Y[b]
if a<0 return Y[a]
else return(Y[b]-Y[a])

Es agg:
Dato un vettore A di n numeri, costruire in tempo O(nlogn) una struttura dati oracolo che risponda a query in tempo O(logn) del tipo
"Quanti elementi di x in [a,b]?"
'''