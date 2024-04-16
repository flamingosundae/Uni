def bin_search_first_occurrence(l, n):
    lo, hi = 0, len(l) - 1
    first_instance = -1  # Inizializziamo con -1 per indicare che non abbiamo ancora trovato una corrispondenza

    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if l[mid] == n:
            first_instance = mid
            hi = mid - 1  # Continua a cercare nella parte sinistra della lista
        elif l[mid] < n:
            lo = mid + 1
        else:
            hi = mid - 1

    return first_instance

def bin_search_last_occurrence(l, n):
    lo, hi = 0, len(l) - 1
    last_instance = -1  # Inizializziamo con -1 per indicare che non abbiamo ancora trovato una corrispondenza

    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if l[mid] == n:
            last_instance = mid
            lo = mid + 1  # Continua a cercare nella parte destra della lista
        elif l[mid] < n:
            lo = mid + 1
        else:
            hi = mid - 1



    return last_instance

def oracolo2(a, b, l):
    l.sort()
    a_pos = bin_search_first_occurrence(l, a)
    b_pos = bin_search_last_occurrence(l, b)

    if a_pos == -1 or b_pos == -1:
        return 0  # Elementi non trovati
    else:
        return b_pos - a_pos + 1

l = [1, 3, 3, 5, 10, 7, 12, 14]
print(oracolo2(3, 10, l))


