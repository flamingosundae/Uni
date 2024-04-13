#Oggi si parla di: OPERATORI

x = 20 #ricorda brevemente: stiamo assegnando una variabile, un riferimento, all'oggetto caricato in memoria.
y = 10
pi = 3.14 


z = x+y 
print(z) #il risultato sarà abbastanza ovviamente intero.
w = pi + y 
print(w) #il risultato sarà un float. Deve ovviamente conservare la rappresentazione in virgola mobile per rappresentare la parte decimale.
d = x/y
print(d) #il risultato, indipendentemente da il type degli oggetti, sarà un float.
d1 = x//y 
print(d1) #divisione intera. Il risultato è un int. La parte decimale viene omessa.
m = x%y
print(m) #operatore modulo. Il risultato è il resto della divisione tra i due oggetti.
q = x**y
print(q)#operatore potenza. Può, sorprendentemente, usare anche float, quindi possiamo anche calcolare radici (x**0.5)


str, str1 = 'python', 'programmazione'

str2 = str + str1 #questa è un'operazione di CONCATENAZIONE. Possiamo ovviamente concatenare solo stringhe ad altre stringhe.
print(str2)
str3 = str2 * 2 #possiamo anche ripetere le stringhe.
print(str3)

a = 'tho'
print(a in str) #ritorna un booleano true/false se la stringa a è contenuta in x.
print(a in str1)
print('la lunghezza di str è', len(str)) #fornisce un int sulla lunghezza della stringa.

input = input('Digita qua') #la console si arresta per permettere all'utente di digitare una sequenza di, solitamente, caratteri.

#In[] esercizio

x = input('Digita la prima stringa: ' )
y = input('Digita la seconda stringa: ')

if x in y:
    print ('La prima stringa è contenuta nella seconda.')
elif y in x:
    print ('La seconda stringa è contenuta nella prima.')
else:
    print('Le due stringhe non si contengono.')


#In[] typecasting

x = input('Digita un numero: ')
y = float(x) #questa è un'operazione di typecasting. Converte, attraverso una funzione, l'oggetto al nuovo tipo assegnatogli.
print(y)
if y < 0:
    print('Il numero che hai digitato è negativo.')
else:
    print('Il numero che hai digitato è positivo.')


#In[] typecasting da int a str

x = int('1234')
print(x, type(x))

y = str(3.14)
print(type(y))

#In[] indicizzazione

x = 'programma'
print(x[2])

#In[] esercizio: conta le vocali in una stringa x.

x = input('Digita in una stringa: ')