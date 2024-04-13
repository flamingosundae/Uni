#In[] operatori logici

#and: è true solo se tutte le x condizioni sono true.
#or: è true se almeno una delle x condizioni è true.
#not: negazione booleana della condizione.

c0, c1 = True, False
print(c0 or c1) #True.
print(c0 and c1) #False.
print(not c0) #False.

#In[] operatori relazionali

print(4 <= 5) #minore/uguale.
print(4 >= 5) #maggiore/uguale.
print(4 != 5) #diverso da.

#In[] esercizio sulle vocali

#prendi in input una stringa e per ogni vocale, aggiungi un asterisco al di sotto.


x = input('Scrivi qualcosa:')
ast_str = ''

for i in range(len(x)):
    if x[i] in 'aeiouAEIOU':
        ast_str += '*'
    else:
        ast_str += ' '
    

print(x)
print(ast_str)

#In[] esercizio sulle vocali pt.2

#prendi in input una stringa e sostituisci tutte le vocali con asterischi.

x = input('Scrivi qualcosa: ')
new_str = ''

for i in range(len(x)):
    if x[i] in 'aeiouAEIOU':
        new_str += '*'
    else:
        new_str += i

print(new_str)
#le stringhe sono IMMUTABILI. SEGNATELO. Non stiamo modificando una stringa corrente, stiamo semplicemente riassegnando la variabile ad un nuovo oggetto frutto della concatenazione del valore new_str e del valore '*'.

