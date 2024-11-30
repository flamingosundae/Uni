def selectionSort(a):
    n = len(a)
    for k in range(0, n-1):
        m = k
        for j in range (k+1, n):
            if a[j] < a[m]:
                m = j
        stored_int = a[k]
        a[k] = a[m]
        a[m] = stored_int
    return a



test_list = [4, 34, 12, 8, 9, 0, 12]
test_list1 = [2, 2, 2, 10, 3, 5, 6]
test_list2 = ['a', 3, 4, 5]

selectionSort(test_list)
selectionSort(test_list1)
selectionSort(test_list2)