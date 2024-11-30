public class Studente extends Persona //Questo ci indica che studente è una SOTTOCLASSE della SUPERCLASSE persona.
{
    String materiaPreferita;//Questi sono attributi AGGIUNTIVI. I.e., propri alla sottoclasse. Creando sottoclassi della sottoclasse, li erediteranno a loro volta.

    Studente(String nome, String cognome, String materiaPreferita)
    {
        super(nome, cognome);
        this.materiaPreferita = materiaPreferita;
        /*La keyword super, nella definizione di una costruzione di una classe ereditaria,
        fa sì che il costruttore della classe di base (superclasse) venga chiamato per l'assegnazione degli attributi.
        In questo caso, per esempio, stiamo chiamando il costruttore di Persona, di modo che assegni
        this.nome = nome;
        this.cognome = cognome;
         */
    }

    void studia()
    {
        System.out.println("Sto studiando..."); //Metodo aggiuntivo. Stesso discorso degli attributi aggiuntivi.
    }

    void saluta()
    {
        System.out.println("Ciao profu!"); //Questo è un override di metodo(come segnalato dall'@ in riga 23). Come il nome lascia intuire, sostituisce il metodo della superclasse di appartenenza quando invocato.

    }

}

