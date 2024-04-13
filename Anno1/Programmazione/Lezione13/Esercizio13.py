def count_int(l):
    '''
    input: una lista di interi che contenga delle sottoliste annidate. Anche le sottoliste contengono interi.
    output: il numero di interi totali nella lista, comprendendo quelli nelle liste annidate.
    '''


    n_int = 0
    for i in range(len(l)):
        if type(l[i]) == type([]):
            n_int += count_int(l[i])
        else:
            n_int += 1
    return n_int

k = [1, 3, 55, [1, 1], 2, [3, [4, 9], 2], 672, 11, 19, [1,[1, [1, [1]]]]]
print(count_int(k))

#In[] soluzione del rossi


def deep_count(a):
    c = 0
    for x in a:
        if type(x) == int:
            c += 1
        elif type(x) == list:
            c += deep_count(x)
        return c
    

a = [2, [8, [1,2], 6], 94, [12, [1], 5, [4, 5]]]
print(deep_count(a))

#la soluzione è basilarmente uguale alla tua, tranne per alcune differenze sintattiche.

#In[] soluzione del rossi alt

def deep_count(a):
    '''
    input: una lista/tupla, a, potenzialmente con liste annidate.
    output: il numero totale di float, str, bool, int e None in a e in tutte le liste/tuple annidate.
    '''
    c = 0
    for x in a:
        if type(x) == (list, tuple):
            c += deep_count(x)
        elif type(x) in (int, float, bool, str, type(None)): #la soluzione in else può funzionare, ma rischia di incappare in tipi di dato non presenti nella consegna. Specificando tutto in una tupla possiamo essere più strutturati ed evitare imprevisti.
            c += 1
        return c
    

a = [None, ['python', [9.59 ,2], 6], True, ['10', [None], 5, [4, 5]]]
print(deep_count(a))