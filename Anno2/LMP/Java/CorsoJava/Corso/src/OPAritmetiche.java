
public class OPAritmetiche {
    public static void main(String[] args)
    {
        op(args);
    }

    public static void op(String[] args) {
        int x = 10;
        x /= 3; // Shorthand di x = x / 3.
        x++; //Shorthand di x = x + 1. Lo conosci già.
        x--; //Shorthand di x = x - 1. Di nuovo, niente di nuovo.
        int y = 2;
        int z = x + y;
        int k = x % y;
        int m = x / y;
        //menzione veloce va fatta per la classe math, che contiene alcuni metodi relativi alle operativi aritmetiche.
        int valBase = 22;
        int valModulo = Math.abs(valBase); //Ritorna il modulo del numero.
        int valMin = Math.min(32, 25); //Ritorna il minimo in una lista di numeri.
        int valMax = Math.max(21, 99); //Ritorna il massimo in una lista di numeri.
        double valRad = Math.sqrt(36); // Ritorna la radice quadrata dell'input.

        System.out.println(z);
    }
}
