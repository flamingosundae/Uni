public class Persona
{
    String nome;
    String cognome;
    static int numeroPersone = 0; //Questa è una variabile statica. Le variabili e i metodi static sono condivisi tra TUTTE le istanze di classe, acquisendo lo STESSO valore per ciascuna.
    int numPersonaSingola;
    Persona(String nome, String cognome)
    {
        this.nome = nome;
        this.cognome = cognome;
        numeroPersone++;
        this.numPersonaSingola = numeroPersone;
        //Questo è un COSTRUTTORE DI CLASSE. Quando instanziamo un oggetto appartenente a x classe, se presente un costruttore custom, viene usato quello(altrimenti viene usato il costruttore di default).
        //Il metodo this è la classe di metodi che ci permette di interagire con gli attributi dell'oggetto in fase di instanziazione, nei metodi o nel costruttore.
    }

    void saluta()
    {
        int prova = 5;
            /*Nota la differenza in scope tra, e.g., prova ed eta.
            Prova ha scope locale, i.e. è una variabile utilizzabile(ed esistente, importantemente, dato che lo spazio che occupa su stack viene liberato alla fine) SOLO nel metodo in cui è definita.
            eta è globale, il che vuol dire che può essere usata da ogni metodo della classe.
            */
    }

    public String toString()
    {
        String stringa = this.nome + "\n" + this.cognome + "\n" + "Sono la persona n." + this.numPersonaSingola;
        return stringa;
    }

    void saluta(Persona persona)//Esempio di metodo che usi un oggetto come parametro. Abbastanza autointuitivo.
    {
        System.out.println("Ciao " + persona.nome + ", sono " + this.nome);
    }

}


