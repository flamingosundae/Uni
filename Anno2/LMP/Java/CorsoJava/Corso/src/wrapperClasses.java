import java.io.DataOutput;

public class wrapperClasses {
    public static void main(String[] args)
    {

    }

    public static void wrapClass(String[] args)
    {
        /*Le wrapper class ci permettono di utilizzare delle primitive come delle reference, il che ci fornisce accesso a una serie di metodi che non potremmo usare con le corrispettive primitve.
        Hanno un significativo svantaggio: al momento della compilazione, la pseudoreference va "spacchettata" (Il processo è chiamato unboxing/autoboxing).
        come primitiva. Questo porta a significativi cali di performance, in larga scala, in quanto le wrapper usano più memoria.
        */

        Boolean vero = true;
        Boolean falso = false;
        Character carattere = 'a';
        Integer numero = 5;
        Double virgola = 5.23;
        String stringa = "Reference";
        boolean a = true;
        char b = 'a';
        int c = 5;
        double d = 5.23;
        if(vero == a) //Nota che è questa è una comparazione di tipo, non di valore assegnato. carattere == b restituisce comunque true(sono entrambi interpretati come char).
        {
            System.out.println("Ciao");
        }
    }
}
