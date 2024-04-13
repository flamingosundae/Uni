#In[] funzione open() e operazione su file

a = 'C:\\Users\\forti\\Desktop\\Appunti\\Programmazione\\Lezione15\\Lezione15.py'

f = open(a) #la funzione open ci garantisce accesso al contenuto di un dato file per operare su di esso in diversi modi.
print(type(f))

for line in f: #iterando su un file, ad ogni ciclo verrà associato alla variabile una riga del fire in formato di stringa.
    print(line)


f.close() #chiude il file. Abbastanza autoesplicativo.
#alcune note sul metodo open: il secondo parametro, impostato di default a 'r', specifica la modalità di accessp al file. In modalità r, abbiamo accesso di sola lettura.
#altre modalità sono w, che crea un nuovo file per la scrittura (sovrascrivendo automaticamente eventuali omonimi) e a, che permette la scrittura ma attaccando il nuovo contenuto al fondo del file. (Tipo un append.)

#riproviamo a scrivere browse_dir con le nuove conoscenze che abbiamo.

import os
def browse_dir(d, ext = None):
    b = []
    cartella = os.listdir(d)
    
    for x in cartella:

        fullpath = os.path.join(d, x)
        
        if os.path.isfile(fullpath) and fullpath.split('.')[-1] == ext:
            f = open(fullpath)
            for line in f:
                if ext in line:
                    b.append(fullpath)
                    break
            f.close() #è fondamentale chiudere il file, una volta operato su di esso. Le cause variano a seconda dell'OS, ma generalmente non chiudere il file comporta errori/imprecisioni/mancamenti nella modifica del file.
        elif os.path.isdir(fullpath):
            c = browse_dir(fullpath, ext = ext)
            b.extend(c)
    return b
    
    
a = browse_dir(os.getcwd(), 'len')
print(a)

#In[] apertura file in scrittura

f = open('provascrittura.txt', mode = 'w')
f.write('prima riga\n') #la funzione write è un metodo del file che scrive la stringa in input come parametro al suo interno.
f.write('seconda riga')
f.close()
f = open('provascrittura.txt', mode = 'a') 
f.write('\n prima riga \n')
f.write('seconda riga')
f.close()

#In[] 