public class Variables
{
    public static void main(String[] args)
    {
        var_type(args);
    }

    public static void variables(String[] args)
    {
        int x = 45; //dichiarazione e assegnazione di variabile. Nota che come in C, la dichiarazione è esplicita. Non possiamo spuntarla ponendo x = 8, e.g.
        int y;
        y = 10; //inizializzazione con assegnazione separata.
        String nome = "prova";
        double numero = 33.25; //l'equivalente dei float di C.
        int numeroDiCammelliInSala = 5; /*
        Nota importante va fatta per l'uso del lower camel case
        in assegnazione di variabili. La prima parola va in minuscolo, le successive in maiuscolo.
        Non è strettamente necessario, ma è buona etichetta e condotta. */
        
        System.out.println(x);
        System.out.println(y);
        System.out.println(nome);
        System.out.print(numero);
    }

    public static void var_type(String[] args)
    {
        {
            //Lista breve dei tipi di dato (primitive):
            boolean luce = true;
            byte num1 = 2; //Il tipo di variabile più piccolo per salvare un numero. È di un byte, i.e.
            //è solo nel range -128 fino a 127.
            short num2 = 30000; //Altra variabile numerica. 2 byte invece di 1.
            int num3 = 250000; //L'int classico. 4 byte di spazio occupato.
            long num4 = 500000000L; //Occupa il doppio di un int. Attenzione alla L a fine numero, segnala la fine della stringa numerica.

            float num5 = 5.25f; //Il float che conosci e ami. È lungo 4 byte(i.e. 6-7 cifre decimali). Attenzione alla f a fine numero.
            double num6 = 17.4444; // 8 byte. Fino a 15 decimali.

            char num7 = 'a'; //Nota che come in C il singolo/doppio adice distingue il char/la stringa.
            String str = "Cazzo? Palle, perfino?"; /*Anche qui, territorio già esplorato. Nota che a differenza di
            C, non è inizializzata come un array! Quindi non devi fare magheggi per il numero di caratteri.
            Nota che la String è una REFERENCE: i.e., un tipo di dato composto di RIFERIMENTI a delle primitive base.
            Sono differenziate dalle primitive dal fatto che il nome di variabile inizia in maiuscola.
            Inoltre, sono provviste dei propri metodi vari ed eventuali.*/

            String strMaGrande = str.toUpperCase();
            System.out.print(strMaGrande);
        }
    }

}
