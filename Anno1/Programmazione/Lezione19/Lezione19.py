
import os
#In[] metodo get

d = {1 : 'a', 2 : 'b'}

d.get(1) #il metodo get restituisce il valore della chiave in input. 
#Notabilmente, a differenza dell'indicizzazione, per una chiave inesistente/non inizializzata, l'output di get() sarà None. (E non KeyError).

d.get(3, 'c') #il modo in cui get può esserci particolarmente utile è nel caso in cui specifichiamo un secondo parametro in input. Se la chiave specificata non appartiene al dizionario, il risultato di output sarà il secondo parametro.
#se la chiave ha già un valore, restituirà il valore originalmente associato.
print(d)

#In[] applicazione di get() a esercizio

def analizza_test_rossi(cartella):
    d = {}
    for filename in os.listdir(cartella):
        if filename.split('.')[-1] == 'csv': 
            filepath = os.path.join(cartella, filename)
            f = open(filepath)
            for line in f: 
                k, v = line.split(';')
                v = int(v)
                a = d.get(k, [v])
                

            f.close() 
    return d