public class metodiStringhe {
    public static void main(String[] args)
    {

    }

    public static void stringMeths(String[] args)
    {
        String nome = "Alessio";
        //Lista breve dei metodi delle stringhe:
        boolean verifica = nome.equals("Alessio"); //String.equals ritorna true se il contenuto della stringa corrisponde al parametro. Nota che è case-sensitive.
        boolean verifica2 = nome.equalsIgnoreCase("alessio");//Come nome.equals, ma ignora la capitalizzazione.
        int lunghezza = nome.length();//Restituisce la lunghezza della stringa.
        char risultato = nome.charAt(0);//Restituisce il char della stringa indicizzato dal numero in argomento.
        int risultato2 = nome.indexOf("a");//Restituisce la posizione indicizzata nella stringha del char in input. Se vi sono più occorrenze, restituisce quella più piccola.
        boolean verifica3 = nome.isEmpty();//Ritorna true se String.length è 0(la stringa è vuota).
        String risultato3 = nome.toLowerCase();//restituisce la stringa tutta in minuscolo.
        String risultato4 = nome.trim();//Restituisce la stringa con gli spazi vuoti in testa e in coda rimossi.
        String risultato5 = nome.replace('A', 'W');//Restituisce la stringa, sostitutendo tutte le occorrenze di oldchar con newchar. Nota che è case sensitive.
    }


}
