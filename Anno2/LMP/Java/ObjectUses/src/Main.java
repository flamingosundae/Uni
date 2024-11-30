//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args)
    {
        Persona[] persone = new Persona[3]; //Questo è un array di oggetti. Non diversamente da un array normale, supporta l'indicizzazione, nonché ogni altro metodo legato agli array.
        Persona persona1 = new Persona("Luca", "Rossi", 25, "Blu", "Roma");
        Persona persona2 = new Persona("Maria", "Bianchi", 30, "Verde", "Milano");
        Persona persona3 = new Persona("Giovanni", "Verdi", 40, "Rosso", "Napoli");

        persone[0] = persona1;
        persone[1] = persona2;
        persone[2] = persona3;

        System.out.println(persone[0]);

        Persona[] persone2 = {persona1, persona2, persona3}; //Inizializzazione dell'array di oggetti per elencazione.

        persona1.saluta(persona2);
    }
}