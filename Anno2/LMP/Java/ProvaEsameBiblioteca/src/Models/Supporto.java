package Models;

import java.time.LocalDate;
import java.util.ArrayList;

public class Supporto {
    private String titolo;
    private String publisher;
    private int annoPub;
    private ArrayList<Prestito> listaPrest = new ArrayList<>();

    public Supporto(String titolo, String publisher, int annoPub)
    {
        this.titolo = titolo;
        this.publisher = publisher;
        this.annoPub = annoPub;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setAnnoPub(int annoPub) {
        this.annoPub = annoPub;
    }

    public int getAnnoPub() {
        return annoPub;
    }

    public void add_prest(LocalDate dataInitPrest, LocalDate dataRicEffett, String user, int costoAff)
    {
        listaPrest.add(new Prestito(dataInitPrest, dataRicEffett, user, costoAff));
    }

    public Prestito get_prest(int pos)
    {
        return listaPrest.get(pos);
    }

    public int get_list_size()
    {
        return listaPrest.size();
    }
}
