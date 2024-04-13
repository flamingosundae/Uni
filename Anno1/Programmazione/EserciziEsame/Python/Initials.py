def initials(a):
    '''
    input: una stringa, a, formata da parole separate da spazi.
    output: un dizionario che associ a ciascuna iniziale delle parole nella stringa una lista delle parole che hanno quell'iniziale.
    '''
    d = {}
    if a[0] == ' ' or a[len(a)] == ' ':
        print('Non ci devono essere spazi vuoti a inizio o fine stringa.') #controllo per evitare di creare chiavi vuote, e per evitare problemi di segmentazione con l'ultima parola nella stringa.
    else:
        i,j = 0
        while j < len(a):
            if a[j] == ' ' and a[j+1] != ' ': #il secondo controllo evita di creare chiavi vuote in caso di formattazioni con più spazi consecutivi.
                d[a[i]] = d.get(a[i], [])
                d[a[i]].append(a[i:j])
                i = j+1
            j += 1
        d[a[i]] = d.get(a[i], [])
        d[a[i]].append(a[i:j+1])
    
    return d


