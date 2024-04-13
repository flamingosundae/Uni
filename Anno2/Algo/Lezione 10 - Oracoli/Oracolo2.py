#Implementa un oracolo che dato un vettore di interi n, costruisca in tempo O(nlogn) il database e dati due a,b, risponda in tempo O(logn) alla domanda "Quanti numeri ci sono in[a,b]?"
#come fare in modo che bin_search trovi sempre la prima/ultima istanza di un numero?
def bin_search_first_occurrence(l, lo, hi, n):
    while lo <= hi:
        m = (lo + hi) // 2 
        if l[m] == n:
            prevIstance = bin_search_first_occurrence(l, 0, m-1, n)
            if prevIstance == -1:
                return m
            else:
                return prevIstance
        if l[m] > n:
            return bin_search_last_occurrence(l, 0, m-1, n)
        else:
            return bin_search_last_occurrence(l, m+1, len(l)-1, n)
    return -1
        

def bin_search_last_occurrence(l, lo, hi, n):
    while lo <= hi:
        m = (lo + hi) // 2 
        if l[m] == n:
            nextIstance = bin_search_last_occurrence(l, m+1, len(l)-1, n)
            if nextIstance == -1:
                return m
            else:
                return nextIstance
        if l[m] > n:
            return bin_search_last_occurrence(l, 0, m-1, n)
        else:
            return bin_search_last_occurrence(l, m+1, len(l)-1, n)
    return -1

def oracolo2(a, b, l):
    l.sort()
    a_pos = bin_search_first_occurrence(l, 0, len(l)-1, a)
    b_pos = bin_search_last_occurrence(l, 0, len(l)-1, b)
    return len(l) - b_pos + a_pos

l = [1, 3, 3, 5, 10, 7, 12, 14]
print(oracolo2(3, 10, l))