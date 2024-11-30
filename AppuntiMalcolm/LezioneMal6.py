def finchelabarcava(x):
    print(x)


print(finchelabarcava('Hello, world!'))

#nel passaggio di una variabile in funzione, non passi la variabile, ma il suo CONTENUTO.
#lo scope globale va usato il meno possibile e le variabili locali il meno possibile.
#keep it simple, più cose aggiungi più è difficile tenere traccia di valori inizializzati, modificati e restituiti.

# In[]

x = 50

def aggiungix(x):
    x = 60
    return x


print(aggiungix(10))


