import java.util.Scanner; //Classico processo di import di libreria, in questo caso specificamente
//il metodo Scanner. Necessario per l'input utente.

public class InputOutput {


    public static void main(String[] args)
    {
        inputOutput(args);
    }

    public static void inputOutput(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        /*
        Lo scanner è una reference. Nota l'uso della keyword new, che è rilevante
        specialmente nel contesto di Java. Usando new stiamo creando una nuova ISTANZA dell'oggetto,
        partendo dalla classe scanner. Questo vale per OGNI instanziazione di oggetto.
        Notabilmente, potremmo averlo fatto anche con le stringhe.
        Facendo, e.g. String str = new xy, avremmo creato UNA NUOVA istanza della stringa, separata
        e distinta da quella
        già presente nella pool delle stringhe.
        Tornando allo scanner, nota il parametro System.in, che indica che lo scanner riceve user input.
         */

        System.out.println("Come ti chiami?");
        String nome = scanner.nextLine(); //Indica che alla stringa nome verrà associato il prossimo input letto dallo scanner.
        //System.out.println("Quindi ti chiami " + nome + "? Bella merda."); Concatenazione di stringhe. Nulla di nuovo.

        System.out.println("Qual è il tuo cognome?");
        String cognome = scanner.nextLine();

        System.out.println("Quanti anni hai?");
        int eta = scanner.nextInt();
        scanner.nextLine();
        /*
        Nota: è necessario aggiungere una chiamata allo scanner per consumare
        il carattere di fine riga /n, che non è assorbito da nextInt e viene usato dalla String città.*/

        System.out.println("Dove vivi?");
        String citta = scanner.nextLine();

        System.out.println("Ciao, " + nome + " " + cognome);
        System.out.println("Hai " + eta + " anni e vivi a " + citta);
    }
}
