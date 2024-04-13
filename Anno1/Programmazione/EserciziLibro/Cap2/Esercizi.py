#In[]

'''
Scrivere un codice che chieda all'utente di inserire la propria data di nascita nella forma gg/mm/aaaa, poi stampi una stringa della forma Sei nato nell'anno aaaa.
'''

def year_finder():
    date = str(input('Inserisci la tua data di nascita nel formato GG/MM/AAAA: '))
    year = int(str.split(date, '/')[2])
    print('Sei nato nel', year)



year_finder()

#In[]

'''
Nel codice seguente, sostituire al commento un ciclo while.
'''
def X_linker():
    num_x = int(input('Quante volte devo stampare la X? '))
    to_print = ''
    while len(to_print) < num_x:
        to_print += 'X'
    print(to_print)


X_linker()
# %%
'''
Scrivere un programma che chieda all'utente di inserire 10 interi e poi stampi il numero dispari più grande fra quelli inseriti. Se non è stato inserito alcun numero dispari, deve stampare un messaggio che lo dica esplicitamente
'''

def max_dispari():
    num_max = 0
    for i in range(0, 3):
        num = int(input('Inserisci un numero: '))
        if num > num_max and num % 2 != 0:
            num_max = num
    if num_max != 0:
        print('Il più grande fra i dispari inseriti è', num_max)
    else:
        print('Non hai inserito dispari. Riprova!')


max_dispari()
# %%

def asterisk_matrix(r, c):
    i = 0
    k = 0
    while i < c:
        while k < r:
            print('*', end = '')
            k += 1 
        k = 0
        print('')
        i += 1
    

asterisk_matrix(9, 4)
# %%

'''
Modificare la soluzione dell'esercizio precedente in modo tale che venga mostrato soltanto il perimetro del rettangolo.
'''

def asterisk_perimeter(r, c):
    i = 0
    k = 0
    while i < c:
        while k < r:
            if i in (0, c-1) or k in (0, r-1):
                print('*', end = '')
                k += 1
            else:
                print(' ', end = '')
                k += 1
        k = 0
        print('')
        i += 1
    

asterisk_perimeter(9, 4)
# %%

'''
Risolvere l'esercizio proposto nel punto precedente facendo uso degli operatori di concatenazione e ripetizione su stringhe.
'''

def asterisk_perimeter_MK2(r, c):
    i = 0
    k = 0
    while i < c:
        current_line = ''
        while k < r:
            next_seg = ' '
            if i in (0, c-1) or k in (0, r-1):
                next_seg = '*'
            current_line += next_seg
            k += 1
        k = 0
        print(current_line)
        print('')
        i += 1
    
asterisk_perimeter_MK2(5, 5)
# %%


'''
Scrivere un programma che chieda all'utente una stringa e stampi il numero di vocali che questa contiene.
'''


def vowel_counter():
    k = input('Inserisci una stringa:')
    num_vowels = 0
    for i in range(0, len(k)):
        if k[i] in 'aeiouAEIOU':
            num_vowels += 1
    print('Ci sono', num_vowels, ' vocali nella stringa.')

vowel_counter()
# %%

'''
Scrivere un programma che chieda in input due stringhe a e b. Se b è sottostringa di a il programma stampi la posizione di a a partire dalla quale compare b. Altrimenti il programma stampi -1. 
Ad esempio se a fosse la stringa 'rinoceronte' e b la stringa 'noce', il programma stamperebbe 2.
'''

def substring_find():
    a = input('Inserisci una stringa:')
    b = input('Inserisci la sottostringa da cercare in essa:')
    substring_pos = -1
    for i in range(0, len(a)-len(b)+1):
        if a[i:len(b)+i] == b and substring_pos == -1:
            substring_pos = i
    
    if substring_pos == -1:
        print('Le due stringhe non si contengono.')
    else:
        print('La sottostringa', b, 'si trova in', a, 'a partire dalla posizione', substring_pos)

substring_find()
# %%

'''
Scrivere un programma che chieda all'utente due stringhe a e b, 
se queste hanno almeno una lettera in comune il programma stampi a in orizzontale e b in verticale in modo tale che si intersechino nella prima lettera che compare sia in a che in b.
'''

def string_crossing():
    a = input('Inserisci una stringa:')
    b = input('Inserisci una stringa ancora:')
    verified_intersection = False
    for i in range(0, len(a)):
        if a[i] in b and verified_intersection == False:
            verified_intersection = True
            for k in range(1, len(b)):
                if k == i:
                    print(a)
                else:
                    print((' ' * i) + b[k])


string_crossing()

# %%
'''
Scrivere un programma che chieda in input due stringhe e le stampi allineate al centro. Ad esempio se le due stringhe fossero programmazione e Python, il programma stamperebbe

    programmazione
        Python

'''

def string_aligner():
    a = input('Inserisci una stringa:')
    b = input('Inserisci una nuova stringa:')
    bigger_string = max(len(a), len(b))
    smaller_string = min(len(a), len(b))
    alignment_space = (bigger_string - smaller_string) // 2
    if len(a) > len(b):
        print(a)
        print(' ' * alignment_space + b)
    else:
        print((' ' * alignment_space) + a)
        print(b)
    
string_aligner()

# %%

'''
Scrivere un programma che chieda in input una stringa, se questa rappresenta un numero intero allora stampi lo stesso numero con i separatori delle migliaia. 
Ad esempio, se la stringa fosse 1234567 il programma stamperebbe 1.234.567. L'esercizio deve essere svolto senza utilizzare le f-stringhe.
'''

def numeroconlemigliaia():
    a = input('Inserisci un numero: ')
    num = a[::-1]
    output = ''
    num_cifre = 0
    for i in range(0, len(num)):
        num_cifre += 1
        output += num[i]
        if num_cifre == 3:
            output += '.'
            num_cifre = 0
    print(output[::-1])

numeroconlemigliaia()
# %%

'''
Scrivere un programma che chieda in input una stringa, la stampi e ne evidenzi le vocali inserendo un carattere * al di sotto di queste. 
Ad esempio, se la stringa fosse programmazione il programma stamperebbe
programmazione
  *  *  * ** *
'''

def vowel_highlight():
    a = input('Inserisci una stringa:')
    print(a) 
    asterisk_string = ''
    for i in range(0, len(a)):
        if a[i] in 'aeiouAEIOU':
            asterisk_string += '*'
        else:
            asterisk_string += ' '
    print(asterisk_string)

vowel_highlight()
# %%
