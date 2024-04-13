#In[]

def unclear(x):
    if x%2 == 1:
        return 0
    
print(unclear(2)+unclear(1))
# %%
a = 'alessio'
b = a[1:-2]
print(b)
# %%
d = {'a':1, 'b':2, 'c':3}

for x in d:
    print(x)

# %%
def f(n):
    a = list(range(n))
    a.append(list(range(n, 2*n)))
    a += list(range(2*n, 3*n))
    return a[n] * a[n+1]

print(f(3))
# %%

def enigma(x):
    if x == '':
        return 1
    else:
        return 1 + enigma(x[1:])

print(enigma('ale'))

# %%
def f(x):
    if type(x) == type(0):
        return x
    else:
        return -1

a = ['no', 1, 0, 'b', True]
print(sorted(a, key=f))
# %%
