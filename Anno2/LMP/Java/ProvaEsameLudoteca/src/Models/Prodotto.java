package Models;

public class Prodotto {
    private String titolo;
    private String autore;
    private String publisher;
    private int annoPub;
    private int nCopie;

    public Prodotto(String titolo, String autore, String publisher, int annoPub, int nCopie)
    {
        this.titolo = titolo;
        this.autore = autore;
        this.publisher = publisher;
        this.annoPub = annoPub;
        this.nCopie = nCopie;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public int getAnnoPub() {
        return annoPub;
    }

    public void setAnnoPub(int annoPub) {
        this.annoPub = annoPub;
    }

    public String getAutore() {
        return autore;
    }

    public void setAutore(String autore) {
        this.autore = autore;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public int getnCopie() {
        return nCopie;
    }

    public void setnCopie(int nCopie) {
        this.nCopie = nCopie;
    }

}
