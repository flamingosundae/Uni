package Models;
import java.time.LocalTime;

public class Uso {
    Prodotto prodotto;
    LocalTime oraRichiesta;
    String cliente;
    LocalTime oraRiconsegna;

    public Uso(Prodotto prodotto, LocalTime oraRichiesta, String cliente)
    {
        this.prodotto = prodotto;
        this.oraRichiesta = oraRichiesta;
        this.cliente = cliente;
    }

    public LocalTime getOraRichiesta() {
        return oraRichiesta;
    }

    public void setOraRichiesta(LocalTime oraRichiesta) {
        this.oraRichiesta = oraRichiesta;
    }

    public Prodotto getProdotto() {
        return prodotto;
    }

    public void setProdotto(Prodotto prodotto) {
        this.prodotto = prodotto;
    }

    public String getCliente() {
        return cliente;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public LocalTime getOraRiconsegna() {
        return oraRiconsegna;
    }

    public void setOraRiconsegna(LocalTime oraRiconsegna) {
        this.oraRiconsegna = oraRiconsegna;
    }

    @Override
    public String toString() {
        return super.toString() + oraRiconsegna;
    }
}
