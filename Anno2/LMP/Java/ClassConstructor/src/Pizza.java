
public class Pizza
{
    String impasto;
    String salsa;
    String formaggio;
    String extra;


    Pizza(String impasto)
    {
        this.impasto = impasto;
    }

    Pizza(String impasto, String salsa)
    {
        this.impasto = impasto;
        this.salsa = salsa;
    }
    Pizza(String impasto, String salsa, String formaggio)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
    }

    Pizza(String impasto, String salsa, String formaggio, String extra)
    {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
    }
/*Esempio di costruttori sovraccaricati. Il meccanismo funzionale è simile a quello dei metodi
sovraccaricati: a seconda di tipo e numero di parametri, possiamo usare diversi costruttori custom per la stessa classe.
 */
}