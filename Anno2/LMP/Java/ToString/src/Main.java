//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args)
    {
        Persona persona = new Persona("Luca", "Rossi", 25, "blu", "Roma");
        //Nota che se provassimo a fare un print del nostro oggetto persona, il risultato sarebbe la collocazione dell'oggetto nello stack. Come fare, quindi, per estrarne gli attributi
        System.out.println(persona);
        /*Nota: quando invochiamo una print di un oggetto non string, il programma casta automaticamente il metodo toString()
        per quell'oggetto. Se nella classe di provenienza è presente un toString custom, il metodo di default toString verrà sovrascritto,
        e verrà invece utilizzato il metodo di classe.
         */
    }
}