//Trova la somma di tutti i numeri di Fibonacci pari sotto 4.000.000.

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, f, f1, f2;

    f1 = 0;
    f2 = 1;

    printf("%d %d", f1, f2);

	for(int i=2; i<=1000; i++){
        f = f1 + f2;
        f1 = f2;
        f2 = f;

        printf("%d ", f);
    }
	return 0;
}
