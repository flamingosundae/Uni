def search_bin_y(l):
    lo, hi = 0, len(l)-1
    while lo <= hi:
        mid = lo + (hi-lo) // 2
        if l[mid] == 'Y':
            if l[mid+1] == 'E':
                return mid
            else:
                lo = mid + 1
        if l[mid] != 'Y':
            hi = mid - 1

def search_bin_e(l):
    lo, hi = 0, len(l)-1
    while lo <= hi:
        mid = lo + (hi-lo) // 2
        if l[mid] == 'E':
            if l[mid+1] == 'S':
                return mid
            else:
                lo = mid + 1
        if l[mid] != 'E':
            lo += 1

def yes(l):
    pos_y = search_bin_y(l)
    pos_e = search_bin_e(l)
    num_y = pos_y + 1
    num_e = pos_e - pos_y
    num_s = len(l) - num_e - num_y
    return num_y, num_e, num_s

sample_l = ['Y', 'Y', 'Y', 'Y', 'E', 'E', 'S']
sample_l2 = ['Y', 'Y', 'Y', 'Y', 'Y', 'E', 'S', 'S', 'S', 'S']
print(yes(sample_l))
print(yes(sample_l2))

#la versione della ricerca di e non funziona! Correggila.