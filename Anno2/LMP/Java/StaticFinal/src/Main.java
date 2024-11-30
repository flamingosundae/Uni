//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args)
    {
        final int prova = 5; //La keyword final viene usata per introdurre variabili, classi e metodi costanti. Una volta inizializzata una variabile o classe come final, non potranno essere modificate/estese, a prescindere da qualsiasi altro evento nel codice.
        Persona persona1 = new Persona("Luca", "Rossi");
        Persona persona2 = new Persona("Mario", "Bianchi");
        System.out.println(persona1);
        System.out.println(persona2);
    }
}