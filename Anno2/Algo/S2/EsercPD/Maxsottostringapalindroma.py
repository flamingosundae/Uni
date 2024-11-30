def opt(s:str)->int:
    n = len(s)
    M = [[0] * n for _ in range(n)] #Creo n liste inizializzate a 0 lunghe n.
    for i in range(n):
        M[i][i] = 1
    for d in range(1, n):
        for i in range(n-d):
            j = i + d


    
    return 0