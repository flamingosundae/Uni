package Models;

public class Componente {
    private String nome;
    private String prov;
    private int tempoOrd;
    private int costo;
    private boolean isPriv;

    public Componente(String nome, String prov, int tempoOrd, int costo, boolean isPriv)
    {
        this.nome = nome;
        this.prov = prov;
        this.tempoOrd = tempoOrd;
        this.costo = costo;
        this.isPriv = isPriv;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCosto() {
        return costo;
    }

    public void setCosto(int costo) {
        this.costo = costo;
    }

    public String getProv() {
        return prov;
    }

    public void setProv(String prov) {
        this.prov = prov;
    }

    public int getTempoOrd() {
        return tempoOrd;
    }

    public void setTempoOrd(int tempoOrd) {
        this.tempoOrd = tempoOrd;
    }

    public boolean isPriv() {
        return isPriv;
    }

    public void setPriv(boolean priv) {
        isPriv = priv;
    }
}
