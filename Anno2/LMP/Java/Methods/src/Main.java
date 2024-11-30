//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args)
    {
        Pasta();
        cucina("teste");
    }

    // metodi /funzioni. In C, dove potevano essere native o meno, la distinzione era più netta. Ma in Java, dove tutto è orientato agli oggetti e classi, ogni funzione è tecnicamente metodo(da verificare).

    static void Pasta() //
    {
        System.out.println("Pasta pasta pasta");
    }

    static void cucina(String cibo)
    {
        System.out.println("Sto cucinando " + cibo);
    }

    /*Una nota sui "parametri" che abbiamo assegnato al metodo:
    static significa che il metodo è proprio della classe, e non di una singola istanza.
    Può essere quindi eseguito indistintamente da ogni istanza di classe.
    void significa che la funzione non effettua return di nessun tipo.
     */
}