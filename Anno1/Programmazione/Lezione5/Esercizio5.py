#risolvi l'esercizio4 usando, stavolta, lo slicing.

x = 'programmazione'
y = 'gra'
p = 0
z = ''

while p <= len(x) - len(y) and z!= y:
    z = x[p: len(y) + p]
    if z == y:
        print(y, 'si trova in ', x, 'a partire da', p)
    else:
        p += 1
    

if p > len(x) - len(y):
    print('Le stringhe non si contengono.')

#In[] soluzione del rossi

x = 'programmazione'
y = 'gra'
p, trovato = 0, False
while p <= len(x) - len(y) and not trovato:
    if y == x[p: len(y) + p]:
        trovato = True
    p += 1

if not trovato:
    print('Non esiste corrispondenza.')
else:
    print(y, 'compare in posizione', p, 'di', x)