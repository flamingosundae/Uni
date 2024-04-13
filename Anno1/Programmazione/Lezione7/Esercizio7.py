#scrivere una funzione che riceva in input un intero n e restituisca un float (pseudo)-casuale compreso tra 0 ed 1 composto da n cifre decimali significative dopo la virgola.
import random as ran
def float_gen(n):
    '''
    input : un intero, n.
    output: un numero pseudo-casuale, compreso tra 0 e 1, con n cifre decimali significative dopo la virgola. (Con 'significative' intendiamo diverse da 0).
    '''
    num_str = '0.'
    for i in range(0, n):
        num_str += str(ran.randint(1,9))

    num = float(num_str)
    
    return num


r = float_gen(20) #dopo un certo numero di cifre, a prescindere dall'n in input, num avrà 16 cifre. è un limite di rappresentazione dei float in python, non un errore del codice. Tutti i float hanno al massimo 16 cifre di rappresentazione dopo la virgola.

print(r)

#In[] soluzione del Rossi

def r_float(n):
    str_f = '0.'
    for c in range(n-1):
        str_f += str(ran.randint(0, 9))
        str_f += str(ran.randint(1, 9)) #questa piccola divergenza nel pool per l'ultima cifra (nota range n-1) è per evitare che l'ultima cifra sia uno 0, che la renderebbe non significativa (0, 1000 = 0,1) e quindi lo renderebbe un errore semantico rispetto alla consegna.
    
    return float(str_f) #l'unica fondamentale divergenza è che fa type-casting in fase di return, che è un trick abbastanza utile.

