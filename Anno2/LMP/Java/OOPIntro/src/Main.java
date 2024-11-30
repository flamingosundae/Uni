//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args)
    {
        Persona persona1 = new Persona();
        System.out.println(persona1.nome);
        persona1.saluta();
        Persona persona2 = new Persona(); //persona 1 e persona 2 sono parte della stessa classe, ma sono due ISTANZE DISTINTE.

    }
    /*OOP: Objected Oriented Programming. Filosoficamente, è simile al rapporto tra significante e significato.
    Il significante è la classe, il segno dell'oggetto che identifica la struttura generale e le caratteristiche comuni di ogni copia dell'oggetto.
    L'istanza è il significato, la manifestazione fisica dell'oggetto con le sue caratteristiche specifiche(tecnicamente meglio il referente per questo esempio, ma hai capito.)
     */
}