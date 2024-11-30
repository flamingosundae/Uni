package Models;
import java.time.LocalDate;
import java.time.Period;
public class Prestito {

    private static int giorniRicPrev = 7;
    private LocalDate dataInitPrest;
    private LocalDate dataRicPrev;
    private LocalDate dataRicEffett;
    private String user;
    private int costoAff;

    public Prestito(LocalDate dataInitPrest, LocalDate dataRicEffett, String user, int costoAff)
    {
        this.dataInitPrest = dataInitPrest;
        this.dataRicEffett = dataRicEffett;
        this.user = user;
        this.costoAff = costoAff;
        this.dataRicPrev = dataInitPrest.plusDays(giorniRicPrev);
    }

    public void setDataInitPrest(LocalDate dataInitPrest) {
        this.dataInitPrest = dataInitPrest;
    }

    public LocalDate getDataInitPrest() {
        return dataInitPrest;
    }

    public void setDataRicEffett(LocalDate dataRicEffett) {
        this.dataRicEffett = dataRicEffett;
    }

    public LocalDate getDataRicEffett() {
        return dataRicEffett;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public int getCostoAff() {
        return costoAff;
    }

    public void setCostoAff(int costoAff) {
        this.costoAff = costoAff;
    }

    public LocalDate getDataRicPrev() {
        return dataRicPrev;
    }

    public int getGiorniRicPrev() {
        return giorniRicPrev;
    }

    public void setGiorniRicPrev(int newGiorni)
    {
        giorniRicPrev = newGiorni;
    }

    public void setDataRicPrev(LocalDate dataRicPrev) {
        this.dataRicPrev = dataRicPrev;
    }


}
