//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args)
    {
        Persona persona1 = new Persona("Luca", "Rossi", 25, "Rosso", "Roma");
        Persona persona2 = new Persona("Marco", "Bianchi", 33, "Bianco", "Milano");

        System.out.println(persona1.eta);
        System.out.println(persona2.provenienza);

        Pizza pizza1 = new Pizza("pinsa");
        Pizza pizza2 = new Pizza("integrale", "pomodoro");
        Pizza pizza3 = new Pizza("sfoglia", "bianca", "cheddar");

    }
}