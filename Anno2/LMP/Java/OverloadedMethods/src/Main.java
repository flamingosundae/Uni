//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args)
    {
        int num1 = 1;
        int num2 = 2;
        int num3 = 3;
        int num4 = 4;
        System.out.println(addizione(num1, num2));
        System.out.println(addizione(num1, num2, num3));
        System.out.println(addizione(num1, num2, num3, num4));

    }

    /*Overloaded methods: definiamo un metodo sovraccaricato come
    un metodo con più definizioni all'interno della stessa classe. Potrà
    quindi supportare chiamate con un numero variabile di parametri o con tipi di parametri diversi, usando anche tipi di return diverso, se necessario. (Ogni chiamata dovrà usare parametri disambiguati, però).
    (NB: devi comunque definire il comportamento per quella specifica istanza del metodo).
     */

    static int addizione(int a, int b)
    {
        return a+b;
    }

    static int addizione(int a, int b, int c)
    {
        return a+b+c;
    }

    static int addizione(int a, int b, int c, int d)
    {
        return a+b+c+d;
    }
}