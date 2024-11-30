#include <unistd.h>
#include <stdio.h>

#define STDOUT 1 //Tecnicamente simile a inizializzare STDOUT come variabile, ma ha molteplici vantaggi (per inizializzare risorse costanti), come minore possibilità di errori sintattici nel codice, più leggibilità, conservazione di
		 //memoria, ecc. In generale è meglio usare #define per strutture costanti e con convenzioni di scrittura specifiche associate.

int main()
{
	char msg[] = "Hello World!\n";
	write(STDOUT, msg, sizeof(msg)); //write() scrive un messaggio in input sul file di destinazione e ritorna il numero di byte scritti. 
					 //Parametrizzazione: write(int fd, const void *buf, size_t *count)
					 //int fd: rappresenta DOVE verrà scritto il messaggio attraverso l'ID del file descriptor. Id notabili: 0 per STDIN, 1 per STDOUT e 2 per STDERR.
					 //void *buf: rappresenta il messaggio da scrivere. È void, quindi accetta qualsiasi tipo, ma richiede comunque casting opportuno.
					 //size_t *count: rappresenta la GRANDEZZA in byte del messaggio da scrivere.

	return 0;
}
