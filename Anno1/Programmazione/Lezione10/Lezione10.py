#In[] liste
#finora abbiamo visto due tipologie di dato: scalari(indivisibili e unitarie, come int e float), strutturati(composti da una sequenza di dati non sostituibili, come le stringhe e le tuple).

#data una tupla ad n elementi, un'operazione di concatenazione richiederà n(copia tupla originale) + 1(creazione nuova tupla) + 1(aggiunta nuovo elemento) operazioni.
#la lista, similmente alla tupla, è una sequenza di elementi. Ma c'è una differenza fondamentale: sono modificabili, il che vuol dire che possiamo rimpiazzare ed eliminare elementi.
#questo non è solo rilevante in termini di praticità, ma anche di costo computazionale. L'aggiunta di un elemento alla lista ha costo computazionale 1.(Rispetto all'n della tupla).

a0 = []
a1 = [9, 'python', (1, 2), [], 3.14]
#come i precedenti dati strutturati, supporta indicizzazione, slicing, ripetizione, concatenazione, len(), ecc.

a2 = a0 + a1 #nuova lista. Richiede len(a0) + len(a1) operazioni elementari.
a3 = a1 * 2 #nuova lista. Richiede len(a1) * 2 operazioni elementari.

print(a0, a1, a2, a3)

a2.append('mondo') #il metodo append aggiunge un elemento in fondo ad una lista. Notabilmente, stavolta, non stiamo creando una nuova lista, ma modificandone una preesistente con una sola operazione complessiva.

print(a2)


a2[0] = 'Ciao' #come menzionato precedentemente, possiamo modificare elementi preesistenti.

print(a2)

del(a2[0]) #nota che stavolta il costo computazionale non è 1, ma al massimo n-1 (a seconda della posizione dell'elemento nella lista).

print(a2)