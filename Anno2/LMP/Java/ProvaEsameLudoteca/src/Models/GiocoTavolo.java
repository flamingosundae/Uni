package Models;

public class GiocoTavolo extends Prodotto{
    int durataPartita;

    public GiocoTavolo(String titolo, String autore, String publisher, int annoPub, int durataPartita, int nCopie)
    {
        super(titolo, autore, publisher, annoPub, nCopie);
        this.durataPartita = durataPartita;
    }

    public int getDurataPartita() {
        return durataPartita;
    }

    public void setDurataPartita(int durataPartita) {
        this.durataPartita = durataPartita;
    }

}
