//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args)
    {
        Studente studente1 = new Studente("Luca", "Rossi", "Storia");
        studente1.saluta();
        /*Le conseguenze della costruzione di una classe ereditaria sono autointuitive:
        studente, in quanto sottoclasse di persona, avrà accesso a tutti gli attributi e i metodi della superclasse,
        nonché la possibilità di invocarne il costruttore.
         */
        Insegnante insegnante1 = new Insegnante("Marco","Bianchi", "Storia");
        insegnante1.insegna();
    }
}