package Models;

import java.util.ArrayList;

public class Prodotto {
    static int fattGuad = 1;
    static private int costoReal = 1;
    private int id;
    private String etichettaRiferimento;
    private int costoProd;
    private int prezzoAcq;
    private ArrayList<CompSing> listaComp = new ArrayList<>();
    private int tempoOrd;
    private int tempoReal;

    public Prodotto(int id, String etichettaRiferimento, ArrayList<CompSing> listaComp, int tempoReal)
    {
        this.id = id;
        this.etichettaRiferimento = etichettaRiferimento;
        this.listaComp = listaComp;
        this.tempoReal = tempoReal;
        this.costoProd = calcolaCostoProd();
        this.tempoOrd = calcolaTempoOrd();
        this.prezzoAcq = calcolaPrezzoAcq(this.costoProd, costoReal, fattGuad);
    }

    public int getCostoProd() {
        return costoProd;
    }

    public static int getFattGuad() {
        return fattGuad;
    }

    public static void setFattGuad(int fattGuad) {
        Prodotto.fattGuad = fattGuad;
    }


    public int calcolaCostoProd()
    {
        int costo_tot = 0;
        for(CompSing i: this.listaComp)
        {
            costo_tot += i.getComp().getCosto() * i.getNumNec();
        }
        return costo_tot;
    }

    public int calcolaTempoOrd()
    {
        int tempo_tot = 0;
        for(CompSing i: this.listaComp)
        {
            if(i.getComp().getTempoOrd() > tempo_tot)
            {
                tempo_tot = i.getComp().getTempoOrd();
            }
        }
        return  tempo_tot;
    }

    public int calcolaPrezzoAcq(int costoProd, int costoReal, int fattGuad)
    {
        return (this.costoProd + (costoReal * tempoReal)) * fattGuad;
    }

    public int getTempoOrd() {
        return tempoOrd;
    }

    public int getPrezzoAcq() {
        return prezzoAcq;
    }

    public int getTempoReal() {
        return tempoReal;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getEtichettaRiferimento() {
        return etichettaRiferimento;
    }

    public void setEtichettaRiferimento(String etichettaRiferimento) {
        this.etichettaRiferimento = etichettaRiferimento;
    }

    public void addComp(CompSing compSing)
    {
        listaComp.add(compSing);
        this.tempoOrd = calcolaTempoOrd();
        this.costoProd = calcolaCostoProd();
        this.prezzoAcq = calcolaPrezzoAcq(this.costoProd, costoReal, fattGuad);
    }


    public void printoutProd() {
        System.out.println(this.etichettaRiferimento);
        System.out.println(this.prezzoAcq);
        System.out.println(("Lista prodotti"));
        for(CompSing i: listaComp)
        {
            if(!i.getComp().isPriv())
            {
                System.out.println("Componente: " + i.getComp().getNome()+ "di costo " + i.getComp().getCosto());
            }
        }
    }
}
