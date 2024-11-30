#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#define STDOUT 1

int main(int argc, char **argv)
{
	char msg[] = "Hello World!\n";
	int nr = SYS_write;
	syscall(nr, STDOUT, msg, sizeof(msg)); //syscall, incluso con il #include <sys/syscall.h>. È specialmente utile per invocare chiamate che non hanno un wrapper (funzione o chiamata che permette interazione con chiamate di 
					       //basso livello per maggiore semplicità di accesso e leggibilità. E.g. write() da unistd è un wrapper).
					       //Parametri:
					       //int nr permette di scegliere quale system call invocare. L'int in input rappresenta l^ID associato alla chiamata in linguaggio assembly.
					       //Gli altri parametri sono condizionali a quale funzione stiamo invocando.
	return 0;
}
