#dato un array ordinato [1:n] e un int x, progetta un algo che restituisca, se esistono, due indici i<j, t.c a[i]+a[j] = x
def bin_search(l, x):
    lo = 0 
    hi = len(l) - 1 
    while lo <= hi:
        m = (lo + hi) // 2 
        if l[m] == x:
            while l[m] == l[m-1]:
                m -= 1
            return m
        if l[m] <= x:
            lo = m + 1
        else:
            hi = m - 1
    return -1


def index_calc(l, x): #costo O(nlogn)
    i, j = 0, 0
    for j in range(len(l), 1, -1):
        if l[j] > x:
            continue
        else:
            other_num = x - l[j]
            i = bin_search(l, other_num)
            if i != -1:
                return (i, j)
    return(-1, -1)
                


def index_calc(l, x): #costo O(n)
    i = 0
    j = len(l) - 1
    while i < j:
        if l[j] < x:
                if l[i] + l[j] == x:
                    return (i, j)
                else:
                    i += 1
        j -= 1
    return (-1, -1)
'''
L'algo lineare è corretto? 
Siano i* e j* tale che A[i*] + A[j*] = x.
Per come l'algo è costruito, DEVE risultare uno dei due scenari:
1)i = i*, j>j*
2)i < i*, j = j*
'''


l_test = [2, 5, 9, 14, 20, 21, 25, 40]
print(index_calc(l_test, x = 26))
print(index_calc(l_test, x = 23))
print(index_calc(l_test, x = 20))
