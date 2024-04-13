#Scrivere un programma che chieda in input una stringa e calcoli il numero di vocali che essa contiene.

x = input ('Scrivi qualcosa: ')
num_vocali = 0

for i in range(len(x)):
    if x[i] in 'aeiouAEIOU':
        num_vocali += 1


print ('Il numero di vocali in ', x, 'è', num_vocali)
#oppure print('Il numero di vocali' + x + 'è' + str(num_vocali)). Questa è un'operazione di CONCATENAZIONE di stringhe.


y = input('Scrivi qualcosa: ')
vocali_pari = 0

for i in range(0, len(y), 2):
    if y[i] in 'aeiouAEIOU':
        vocali_pari += 1
    
print ('Le vocali in posizioni pari in', y, 'sono', vocali_pari)