def BubbleSort(a):
    n = len(a)
    for i in range(n, -1, -1):
        for k in range(0, i):
            if a[k] > a[k+1]:
                stored_int = a[k+1]
                a[k+1] = a[k]
                a[k] = stored_int
        
    return a

l = [7, 2, 5, 4, 3, 1]
BubbleSort(l)