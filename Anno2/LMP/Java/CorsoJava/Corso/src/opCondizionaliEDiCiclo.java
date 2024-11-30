public class opCondizionaliEDiCiclo {
    public static void main(String[] args)
    {
        opCiclo(args);
    }

    public static void opCondizionali(String[] args)
    {
        //Lista breve degli operatori condizionali.
        boolean eVero = true;
        boolean eFalso = false;

        if(eVero == true)
        {
            System.out.println("La verità è sempre vera");
        }
        else if (eFalso == false)
        {
            System.out.print("Ciò che è falso è sempre falso");
        }
        else
        {
            System.out.println("Ciò che è nel mezzo non può essere conosciuto");
        }

        String x = 3 < 10? "ciao" : "buongiorno"; //Questo è un operatore ternario. Associa condizionalmente uno dei due valori possibili alla variabile in base all'esito della verifica.
        //Sintassi: condizione? Esito true: esito false;

        System.out.println(x);
    }


    public static void sw(String[] args)
    {
        String nome = "Luca";

        switch(nome)
        {
            case "Luca":
                System.out.println("Ciao, Luca");
                break;
            case "Marco":
                System.out.println("Ciao, Marco");
                break;
            case "Anna":
                System.out.println("Ciao Anna");
                break;
            default:
                System.out.println("Ciao, chiunque tu sia");
                break;
        }
        /*Questo è uno Switch. È un modo alternativo di introdurre una serie di
        if-else, analizzando caso per caso ciascuna delle sue condizioni.
        Una nota estremamente importante è che a differenza degli if, una volta trovata
        una condizione verificata, NON esegue esclusivamente il corpo di quello specifico if.
        Scorrerà caso per caso lo switch, anche dopo un esito positivo. Da qui la necessità dei break a fine codice.*/

    }

    public static void opCiclo(String[] args)
    {
        int i = 0;
        int k = 0;
        while(i < 10)
        {
            System.out.println("Il valore corrente di i è " + i);
            i++;
        }

        do
        {
           System.out.println("Il valore corrente di k è " + k);
           k++;
        }while(k < 10);

        /*Nota la differenza sostanziale tra while e do while, i.e. che do while
        verifica la condizione POST esecuzione del corpo(mentre while controlla prima). Questo comporta, notabilmente,
        che il ciclo viene eseguito ALMENO una volta anche se la condizione non è verificata.
         */
        int m;
        for(m = 0; m < 10; m++)
        {
            System.out.println("Il valore corrente di m è " + m);
            //Il for è usato, solitamente, per ciclare negli array. A parte quello, è basilarmente intercambiabile con i while.
        }

        int[] numeri = {10, 20, 30, 40, 50};
        for(int x: numeri) //ciclo for each. È basilarmente il for in di Python. Nota la signassi dichiarazione variabile di ciclo(dichiarabile separatamente): array da scorrere.
        {
            System.out.println(x);
        }

        //Nota veloce su break e continue: li conosci già. Break esce dal blocco al momento in esecuzione, continue passa alla prossima iterazione del ciclo in automatico.
    }
}
