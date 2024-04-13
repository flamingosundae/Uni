#In[]
'''
Scrivere un programma che chieda in input un intero n maggiore di 2 e stampi il più grande divisore di n oppure, nel caso questo non esista, la stringa 'n è un numero primo'.
'''

def cerca_divisore(n):
    primo = True
    div = 0
    for i in range(2, int(n**0.5)+1):
        if n / i == n // i:
            primo = False
            div = n/i
            break
    if primo == False:
        print('Il più grande divisore di', n, 'è', int(div))
    else:
        print(n, 'è primo')


cerca_divisore(20)
cerca_divisore(2)
cerca_divisore(13)
cerca_divisore(400)
# %%
'''
Scrivere un programma che chieda all'utente di inserire un intero e stampi due interi, root e pwr, 
tali che 1 < pwr < 6 e rootpwr sia uguale all'intero inserito dall'utente. Se non esiste una coppia con queste caratteristiche, deve stampare un messaggio che lo segnali.
'''

def root_find(n):
    power_exists = False
    for i in range(2, 6):
        root = n**(1/i)
        pwr = i
        if int(root) == root:
            power_exists = True
            break
    
    if power_exists == True:
        print(n, 'equivale a', int(root), 'alla', pwr)
    else:
        print('Non esiste una coppia che rispetti le condizioni cercate')

root_find(8)
root_find(9)
root_find(17)
root_find(400)

# %%

'''
Scrivere un programma che stampi la somma dei numeri primi maggiori di 2 e minori di 1000.
'''
prime_sum = 0
for i in range(3, 1000, 2):
    prime = True
    for k in range(2, int(i**0.5)+1):
        if i / k == i // k:
            prime = False
            break
    if prime == True:
        print(i, 'è numero primo')
        prime_sum += i

print('La somma dei primi da 3 a 999 è', prime_sum)

# %%

x = -27
epsilon = 0.01
num_guesses, low = 0, 0
high = max(1, x)
ans = (high + low)/2
while abs(ans**3 - abs(x)) >= epsilon:
    print('low =', low, 'high =', high, 'ans =', ans)
    num_guesses += 1
    if ans**3 < x:
        low = ans
    else:
        high = ans
    ans = (high + low)/2
print('numero di congetture =', num_guesses)
print(ans, 'è vicino alla radice cubica di', x)

# %%

'''
Scrivere un programma che chieda all'utente le coordinate x ed y di un punto
e verifichi se questo sia interno o esterno al cerchio di raggio 10 e centro nell'origine degli assi. Nel primo caso stampi Interno, altrimenti stampi la distanza del punto dalla circonferenza. 
Un punto sulla circonferenza è interno.
'''

def point_locator(x, y):
    if (x <= 10 and x >= -10) and (y <= 10 and y >= -10):
        print('Interno')
    else:
        dist = abs(x**2+y**2) ** 0.5
        print('Il punto dista', dist, 'dalla circonferenza')
    

point_locator(15, 7)
point_locator(8,3)
point_locator(10, 10)
# %%

'''
Scrivere un programma che chieda all'utente di inserire una sequenza di numeri e, per ogni numero inserito a partire dal terzo, stampi la media troncata ovvero la media dei valori 
inseriti scartando il valore minimo e massimo.
'''

def media_troncata():
    first_num = int(input('Inserisci un numero:'))
    min_num = first_num
    max_num = first_num
    num_count = 1
    tot = first_num
    while True:
        input_num = int(input('Inserisci un numero:'))
        if input_num > max_num:
            max_num = (input_num)
        if input_num < min_num:
            min_num = input_num
        num_count += 1
        tot += input_num
        if num_count >= 3:
            avg = (tot-max_num-min_num)/(num_count-2)
            print('La media troncata è', avg)

media_troncata()
# %%

'''
L'algoritmo di Gauss-Legendre per l'approssimazione di PI (Pi-greco) è così definito:

Valori iniziali, passo 0: a0 = 1, b0 = 1/20.5, p0 = 1, q0 = 1/4
Dati i valori an, bn, pn e qn calcolati al passo n+1:
an+1 = (an+bn)/2
bn+1 = (anbn)^0.5
pn+1 = 2pn
qn+1 = qn-pn(an-an+1)^2
'''

def gauss_legendre(n):
    a_prev, a = 1, 1
    b = 1 / (2**0.5)
    p = 1
    q = 0.25
    pi = 0
    for i in range(1, n+1):
        a_prev = a
        a = (a_prev+b)/2
        b = (a_prev * b)**0.5
        q = q - (p*((a_prev-a)**2))
        p = 2*p
        pi = (a+b)**2/(4 * q)
        print('Il valore di pi al passo', i, 'è', pi)

gauss_legendre(10)
        


# %%

'''
La successione di Fibonacci è composta dagli interi 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,... 
In particolare i primi due valori sono 0 e 1, ogni altro valore è dato dalla somma dei due precedenti.
Scrivere un programma che chieda in input un numero n e stampi il valore in posizione n della successione. Si tenga conto che il primo elemento della successione è in posizione 0.
'''

def fibo_calc(n):
    pos_value, f0, f1, f_res = 0, 0, 1, 1
    for i in range(0, n+1):
        pos_value = f0
        f0 = f1
        f1 = f_res
        f_res = f1 + f0
    print('Il valore della successione in posizione', n, 'è', pos_value)

fibo_calc(3)
# %%

'''
Scrivere un programma che chieda all'utente di inserire due interi positivi m e q e quindi rappresenti graficamente la retta mx+q nel quadrante positivo nell'intervallo 0-10
utilizzando il simbolo * per i punti della retta.
'''


def grafico_retta(m, q):
    print('------------------------------------------------------>y')
    for x in range(0, 10):
        print('|'+ ' ' * ((m*x) + q) + '*')
    print('v')
    print('x')
    
grafico_retta(3, 2)
# %%
