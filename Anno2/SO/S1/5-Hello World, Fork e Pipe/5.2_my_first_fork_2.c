#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0 //I numeri associati convenzionalmente alla lettura e scrittura di una pipe sono 0 e 1, rispettivamente. Nota il parallelismo con STDIN e STOUT. 
#define PIPE_WR 1

int main(int argc, char** argv) {

	pid_t cat_pid, sort_pid; //Il tipo di dato pid_t viene utilizzato per la memorizzazione dei pid dei processi figli.
	int fd[2];//Inizializziamo un array per la conservazione dei file descriptor della pipe. Potremo invocare quindi la lettura e scrittura della pipe con fd[0]/fd[PIPE_RD] e fd[1]/fd[PIPE_WR], rispettivamente.

	pipe(fd); //Creiamo una pipe innomine e associamogli l'array fd per interagire con essa.
	
	cat_pid = fork(); //Creiamo un processo child. Il child riceverà 0 come risultato della chiamata (NON uguale a dire che il suo PID sarà 0), mentre il parent riceverà il PID del figlio. Così facendo possiamo gestire entrambi
			  //e le interazioni tra essi.

	if ( cat_pid == 0 ) { //Operiamo sul figlio creato dalla fork.
		close(fd[PIPE_RD]); //Chiude il file descriptor per la lettura su pipe,
		close (STDOUT); //e lo STDOUT. Questi sono necessari al ridirezionamente corretto dell'output, e all'evitare operazioni non necessarie sulla pipe, che possano portare ad errori nel processo di scrittura.
		dup(fd[PIPE_WR]); //duplica l'estremità di scrittura  della pipe, creando un clone che punta alla STESSA risorsa interna del fd originale.
		execl("/bin/cat", "cat", "names.txt", NULL); //Esegue un comando, specificando nel primo parametro il path del comando, nel secondo il nome del comando e nei successivi i parametri necessari ad esso.
							     //Deve sempre terminare con un puntatore a NULL.
	}

	sort_pid = fork();

	if ( sort_pid == 0 ) {
		close(fd[PIPE_WR]);
		close (STDIN);
		dup(fd[PIPE_RD]); 
		execl("/usr/bin/sort", "sort", NULL);//Ripetiamo essenzialmente lo stesso processo di sopra, ma per il sort, e ridirezionado al file per la lettura della pipe.
						     //dup è spesso usato in concomitanza con le pipe per ridirezionare STDOUT e STDIN di modo da scrivere su/da pipe.
	}

	
	close(fd[PIPE_RD]); 
	close(fd[PIPE_WR]); //Chiude i FD della pipe di modo da evitare uno spreco di risorse.
	
	/* wait for children to finish */ 
	waitpid(cat_pid, NULL, 0); //Aspetta che i processi figli terminino il loro operato, di modo da sincronizzare parent e child. 
				   //Il secondo parametro permette, se necessario, di catturare lo stato dei child.
				   //Il terzo, invece, fornisce specifiche condizioni per la cattura. Con 0, attendiamo semplicemente il loro termine.
	waitpid(sort_pid, NULL, 0);
			
	return 0; 
}
