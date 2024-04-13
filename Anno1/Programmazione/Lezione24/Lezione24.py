#In[] operatore *

t = (2, 3, 4, 6)
print(*t) #l'operatore * è un operatore di spacchettamento, che, applicato ad un dato sequenziale, lo spacchetta, restituendone i singoli elementi. 
#è perlopiù inutilizzabile da solo, e quindi la maggior parte delle volte usato in combinazione con altri operatori e funzioni.

def my_min(a, b):
    if a < b:
        return a
    else:
        return b
    
t = (8,0)
print(my_min(*t)) #l'operatore * è molto potente, ed usarlo con intelligenza può dare ottimi risultati. Ha un costo nascosto non indifferente, però, fai attenzione.

#In[] raffinamento del grafico liste-confronti
import matplotlib.pyplot as plt

d = {10: (41.80000000000005, 22.810000000000006),
     20: (180.68999999999994, 63.559999999999995),
     30: (417.97999999999985, 111.48999999999995),
     40: (752.6999999999998, 165.04999999999993),
     50: (1193.5300000000002, 221.39999999999995),
     60: (1733.15, 281.57000000000005),
     70: (2369.5199999999995, 343.19),
     80: (3110.1000000000017, 407.6699999999999),
     90: (3938.46, 474.57999999999987),
     100: (4882.32, 542.3899999999999),
     110: (5911.489999999999, 610.56),
     120: (7057.6399999999985, 680.0999999999998),
     130: (8266.799999999996, 749.78),
     140: (9616.040000000006, 825.6700000000001),
     50: (11074.270000000002, 899.2500000000005),
     160: (12599.160000000003, 975.5399999999998),
     170: (14240.28000000001, 1051.2800000000002),
     180: (15948.449999999999, 1127.01),
     190: (17789.77000000001, 1204.39)}

x = d.keys()
y0, y1 = list(zip(*d.values()))
print(y0)
print(y1)
plt.plot(x, y0, c= 'r', label = 'bubble sort') 
plt.plot(x, y1, c= 'cyan', label = 'merge sort')
plt.legend()
plt.xlabel('dimensione lista') 
plt.ylabel('numero confronti')

#In[] memoria occupata 