public class Persona
{
    String nome;
    String cognome;
    int eta;
    String colorePref;
    String provenienza;

    Persona(String nome, String cognome, int eta, String colorePref, String provenienza)
    {
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.colorePref = colorePref;
        this.provenienza = provenienza;
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

}
