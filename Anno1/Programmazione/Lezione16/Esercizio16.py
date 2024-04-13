#In[] esercizio1
def find_in_file (filename, k):
    '''
	Input: filename e k sono str, filename è il nome di un file
	Output: una tupla (r0, r1, ...) di interi che indicano le righe del file in cui compare k  
	'''
    t = ( ) #O(1)
    f = open(filename) #O(1) 
    r = 0 #O(1)
    for line in f: #con n = num.righe file, O(n)
        r += 1 #O(1)
        if k in line: #se len(line) è costante, O(1) operazioni. 
            t += (f'r{r}', ) #O(len(t) + 1) per ogni concatenazione. Ricorda che la tupla è immutabile.
    
    f.close() #O(1) #ricordati di chiudere il file, specie se aperto in modalità scrittura.
    
    return t #O(1)


a = find_in_file('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione4\\Lezione4.py', 'len')
print(a)
#corretto, ma nel caso peggiore (in cui c'è k in ogni riga), O(n^2). Ovviamente può essere ottimizzato.

#In[] 
def find_in_file_adv(filename, k):
    '''
    Input: filename e k sono str, filename è il nome di un file
    Output: una tupla ( (r0, c0), (r1, c1), ...) di coppie di interi che indicano le
    righe e le colonne del file in cui compare k. Per colonna si intende la posizione
    all'interno della riga.
    '''
    t = ()
    r = 1
    f = open(filename)
    for line in f:
        r += 1
        if k in line:
            for c in range(len(line)):
                if k in line[c:len(k)+c]:
                    t += ((f'r{r}, c{c}'), )
            
    f.close()
    
    return t

a = find_in_file_adv('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione4\\Lezione4.py', 'len')
print(a)
#In[] ottimizzazione find_in_file
#possiamo scalare da O(n^2) a O(n) per find_in_file in modo estremamente semplice. Basta rendere t una lista e usare l'append invece di concatenare. In questo modo, O(n).
def find_in_file (filename, k):
    '''
	Input: filename e k sono str, filename è il nome di un file
	Output: una tupla (r0, r1, ...) di interi che indicano le righe del file in cui compare k  
	'''
    lines = [] #O(1)
    f = open(filename) #O(1) 
    r = 0 #O(1)
    for line in f: #con n = num.righe file, O(n)
        r += 1 #O(1)
        if k in line: #se len(line) è costante, O(1) operazioni. 
            lines.append(f'r{r}') #O(1) per ogni operazione. Le liste sono mutabili. Yeeee.
    
    f.close()
    
    #nota che abbiamo reso il return una lista, che è ovviamente più efficiente in termini di costo computazionale ma viola i termini della docstring.
    return tuple(lines) #O(n), nel caso peggiore. Non dissimilmente da altri tipi di typecasting, tuple(x) rende il parametro in input una tupla.

#il costo finale di questa versione è O(n), se len(line) è costante.
#è invece O(nm), se la len(line) non è più costante ma O(m). O, in altre parole, il costo del ciclo for.

#In[] soluzione del rossi - esercizio2
def find_in_file_adv_rossi(filename, k):
    '''
    Input: filename e k sono str, filename è il nome di un file
    Output: una tupla ( (r0, c0), (r1, c1), ...) di coppie di interi che indicano le
    righe e le colonne del file in cui compare k. Per colonna si intende la posizione
    all'interno della riga.
    '''
    lines = []
    r = 1
    f = open(filename)
    for line in f:
        r += 1
        if k in line:
            for c in range(len(line) - len(k)+1):
                if k == line[c:len(k)+c]:
                    lines.append((f'r{r}, c{c}'), ) 
            
    f.close()
    
    return tuple(lines)

# %%
