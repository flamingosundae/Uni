def hist(h0, h1, *numbers):
    '''
    input: due interi, h0 ed h1, e un numero variabile di float, numbers.
    output: il numero di float in input nell'intervallo s0 (-∞, h0), nell'intervallo s1[h0, h1), e 
    nell'intervallo s2, [h1, +∞).
    esempio:  se l'input della funzione fosse -7, 5, 3, 10, -4, 5, -12, 6, 0, i segmenti saranno: i numeri minori di -7; i numeri compresi tra -7 e 5 (escluso); i numeri maggiori-uguali a 5. I valori -12 e -4 fanno parte del primo segmento; 3 e 0 fanno parte del secondo segmento; 10, 5 e 6 fanno parte del terzo segmento. Quindi la funzione dovrebbe restituire la terna: 1, 3, 3
    '''
    s0 = 0
    s1 = 0
    s2 = 0

    for n in numbers:
        if n < h0:
            s0 += 1
        elif n >= h0 and n < h1:
            s1 += 1
        else:
            s2 += 1
        
    return s0, s1, s2

a = -7
b = 5
p, q, r = hist(a, b, 3.33, 1, 9, 8, -10, -11.44, -12)
print(f'Ci sono {p} numeri prima di {a}, {q} numeri tra {a} e {b}, e {r} numeri dopo {b}')
t = hist(0, 5, 3, 10, -4, 5, -12, 6, 0) 
#questo non dà un errore di assegnazione, ma è bensì una tupla.

#In[] versione del rossi

#esattamente uguale, se non che usa la seconda condizione n < h1. E chiama i segmenti seg0, seg1, seg2. Non estremamente significativo.