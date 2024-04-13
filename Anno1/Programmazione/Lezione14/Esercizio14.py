
import os

#In[] esercizio1
def browse_dir_adv(d, ext = ''):
    '''
    input: una stringa di percorso, d, e una stringa, ext.
    output: nessuno. La funzione stampa tutti i nomi dei file all'interno della cartella e delle rispettive sottocartelle.
    Se specificato ext, verranno stampati solo i file con quell'estensione.
    '''
    cartella = os.listdir(d)

    for x in cartella:
        fullpath = os.path.join(d, x) 
        if os.path.isfile(fullpath) and fullpath.endswith(f'{ext}'):
            print(f'FILE: {fullpath}')
        elif os.path.isdir(fullpath):
            browse_dir_adv(x, ext=ext)
    
        

browse_dir_adv(os.getcwd())

#In[] esercizio2
def browse_dir_l(d, ext = ''):
    '''
    stessa funzione di prima, ma ora aggiunge i nomi dei file ad una lista.
    '''
    l = []
    cartella = os.listdir(d)
    for x in cartella:
        fullpath = os.path.join(d, x) 
        if os.path.isfile(fullpath) and fullpath.endswith(f'{ext}'):
            l.append(fullpath)
        elif os.path.isdir(fullpath):
            browse_dir_l(x, ext=ext)

    return l

a = browse_dir_l('C:\\Users\\forti\\Desktop\\Appunti\\Programmazione', '.py')
print(a)


#In[] soluzione del rossi


def browse_dir_rossi(d, ext = None):
    cartella = os.listdir(d)
    
    for x in cartella:
        fullpath = os.path.join(d, x)
        if os.path.isfile(fullpath):
            if ext == None or fullpath.split('.')[-1] == ext: #la funzione split restituisce, a partire da una stringa, una tupla contenente le parti della stringa originale spezzata rispetto al separatore(primo parametro, stringa). In questo caso prendiamo -1 perché l'estensione sarà ovvviamente sempre l'ultima parte del file.
                    print(f'FILE: {fullpath}')
        elif os.path.isdir(fullpath):
            browse_dir_rossi(fullpath, ext = ext)

browse_dir_rossi(os.getcwd(), ext = 'py')

#In[] soluzione del rossi-esercizio due

def browse_dir_rossiL(d, ext = None):
    cartella = os.listdir(d)
    
    l = []
    for x in cartella:
        fullpath = os.path.join(d, x)
        if os.path.isfile(fullpath):
            if ext == None or fullpath.split('.')[-1] == ext: #la funzione split restituisce, a partire da una stringa, una tupla contenente le parti della stringa originale spezzata rispetto al separatore(primo parametro, stringa). In questo caso prendiamo -1 perché l'estensione sarà ovvviamente sempre l'ultima parte del file.
                    l.append(fullpath)
        elif os.path.isdir(fullpath):
            c = browse_dir_rossiL(fullpath, ext = ext)
            l.extend(c) #il metodo extend prende in input un dato iterabile(stringhe, tuple, liste, ecc) e estende la lista di partenza con tutti gli elementi contenuti in esso.
            #svolge la stessa funzione del codice in riga 75-76, anche se più compatto.
            #for a in c:
            #    l.append(a)
        
        return l

browse_dir_rossiL(os.getcwd(), ext = 'py')

