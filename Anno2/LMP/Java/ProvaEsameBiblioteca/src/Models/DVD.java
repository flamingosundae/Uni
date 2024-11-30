package Models;

public class DVD extends Supporto{

    private int durata;

    public DVD(String titolo, String publisher, int annoPub, int durata)
    {
        super(titolo, publisher, annoPub);
        this.durata = durata;
    }

    public void setDurata(int durata) {
        this.durata = durata;
    }

    public int getDurata() {
        return durata;
    }
}
