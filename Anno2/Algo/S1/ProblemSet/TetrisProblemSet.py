def aggiungipezzo(a, pos, w, h, m):
    max_val = max(a[pos:pos+w])
    game_over = False
    if max_val != 0:
        for i in range(pos, pos+w):
            a[i] = max_val + h
            if a[i] > m:
                game_over = True
    else:
        for i in range(pos, pos+w):
            a[i] += h
            if a[i] > m:
                game_over = True


def calcolaGO(arraypezzi, n, m):
    griglia_start = [0]*n
    n_mosse = 0
    for x in arraypezzi:
        game_over = aggiungipezzo(griglia_start, x[0], x[1], x[2], m)
        n_mosse += 1
        
