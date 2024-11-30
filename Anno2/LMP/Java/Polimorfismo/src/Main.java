
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Studente studente1 = new Studente("Luca", "Rossi", "Matematica" );
        Insegnante insegnante1 = new Insegnante("Marco", "Verdi", "Storia");
        Studente studente2 = new Studente("Giovanni", "Mucciaccia", "Arte");

        Persona[] classe = {studente1, insegnante1, studente2};
        for(Persona persona: classe)
        {
            persona.saluta();
        }
        /*Questo è un esempio di polimorfismo.
        Nonostante siano istanze di due classi diverse,
        possiamo trattare sia studente che insegnante
        come espressioni della loro superclasse persona,
        permettendoci di inserirli contemporaneamente in un array.
         */
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.println("Inserisci un numero: ");
            int x = scanner.nextInt();
            System.out.println("Inserisci il secondo numero: ");
            int y = scanner.nextInt();

            int result = x / y;
            System.out.println("Risultato" + result);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Non puoi dividere per 0!");
        }
        catch(InputMismatchException e)
        {
            System.out.println("Input invalido. Inserisci due numeri.");
        }
        finally {
            System.out.println("Questo verrà eseguito sempre."); //Il blocco di codice finally, nell'exception handling, verrà eseguito sempre, sia in caso di eccezione che no.
        }
        /*Nota la possibilità notevole, qui, di generare un exception
        dividendo per 0. Non è strettamente un errore, bensì un caso
        specifico che altera il flusso del programma. Dobbiamo quindi ingaggiare in
        dell'exception handling.
         */

    }

}
