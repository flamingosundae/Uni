def insertionSort(a):
    n = len(a)
    for k in range(0, n-1):
        i = k
        for j in range(k, -1, -1):
            if a[k+1] < a[j]:
                i = j
        stored_int = a[i]
        a[i] = a[k+1]
        for m in range(i+1, k+2):
            next_int = a[m]
            a[m] = stored_int
            stored_int = next_int
    
    return a
    
l = [7, 2, 5, 4, 3, 1]

insertionSort(l)