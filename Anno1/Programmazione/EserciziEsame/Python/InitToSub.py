def initial_to_substring(a):
    '''
    Si scriva una funzione, denominata initial_to_substring, che prenda in input una
    stringa a e restituisca un dizionario che mappi ogni carattere c di a nella sottostringa più lunga di a che inizi per c.
    '''
    d = {}
    for x in a:
        i = 0
        max_len = 0
        for n in range(len(a)):
            if x == a[n]:
                max_len = 
                