l = [0,7, 55, 33, 44, 16, 19, 22, 30, 28]

def fixHeap(i, l):
    max = i
    s = 2 * i
    d = (2 * i) + 1
    if s < l[0] and l[s] > l[i]:
        max = s
    else:
        max = i
    if d < l[0] and l[d]> l[max]:
        max = d
    if max != i:
        l[i], l[max] = l[max], l[i]
        fixHeap(max, l)

def heapify(l, root = 1):
    sin = 2 * root
    des = (2* root) + 1
    if sin < l[0]:
        heapify(l, sin)
    if des < l[0]:
        heapify(l, des)
    fixHeap(root, l)


def heapSort(l):
    heapify(l)
    l[0] = len(l)-1
    for i in range(l[0], 3, -1):
        l[1], l[i] = l[i], l[1]
        l[0] -= 1
        fixHeap(1, l)
    
    return l
    

l = [0, 1, 99, 2, 15, 6, 73, 8, 44, 124, 32, 36]
print(heapSort(l))