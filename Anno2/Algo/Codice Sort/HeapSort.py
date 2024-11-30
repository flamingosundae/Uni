def fixHeap(i, A):
    s = 2 * i
    d = (2 * i) + 1
    max = i
    if s <= A[0] and A[s] > A[max]:
        max = s 
    if d <= A[0] and A[d] > A[max]:
        max = d
    stored_int = A[i]
    A[i] = A[max]
    A[max] = stored_int #A[i]
    if max != i:
        fixHeap(max, A)
    return A



def heapify(i, A):
    s = 2 * i
    d = (2 * i)+1
    if s <= A[0]:
        heapify(s, A)
    if d <= A[0]:
        heapify(d, A)
    fixHeap(i, A)
    return A


def heapSort(A):
    heapify(1, A)
    for i in range(A[0], 1, -1):
        stored_int = A[i]
        A[i] = A[1]
        A[1] = stored_int
        A[0] -= 1
        fixHeap(1, A)
    return A



l = [8, 5, 4, 10, 98, 12, 3, 4, 5]
heapSort(l)