package Models;

public class Libro extends Prodotto
{
    int numPag;

    public Libro(String titolo, String autore, String publisher, int annoPub, int numPag, int nCopie)
    {
        super(titolo, autore, publisher, annoPub, nCopie);
        this.numPag = numPag;
    }

    public int getNumPag() {
        return numPag;
    }

    public void setNumPag(int numPag) {
        this.numPag = numPag;
    }

}
