package Models;

public class Libro extends Supporto{

    int numPag;

    public Libro(String titolo, String publisher, int annoPub, int numPag)
    {
        super(titolo, publisher, annoPub);
        this.numPag = numPag;
    }

    public void setNumPag(int numPag) {
        this.numPag = numPag;
    }

    public int getNumPag() {
        return numPag;
    }
}
