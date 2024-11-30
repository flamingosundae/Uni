package Services;

import Models.CompSing;
import Models.Prodotto;
import Models.Componente;

import java.util.ArrayList;
import java.util.HashMap;

public class GestoreProd {
    private ArrayList<Prodotto> listaProd;

    public GestoreProd()
    {
        listaProd = new ArrayList<>();
    }

    public void addprod(int id, String etichettaRiferimento, ArrayList<CompSing> listaComp, int tempoReal)
    {
        this.listaProd.add(new Prodotto( id, etichettaRiferimento, listaComp, tempoReal));
    }

    public void addprod(Prodotto prod)
    {
        this.listaProd.add(prod);
    }

    public void PresentazioneProd()
    {
        for(Prodotto prod: this.listaProd)
        {
            prod.printoutProd();
        }
    }


    //Genera un ranking dei prodotti in lista prod dato da prod.prezzoAcq/(prod.tempoOrd + tempoReal).
    public HashMap rankingProd()
    {
        HashMap<Prodotto, Double> ranking = new HashMap<>();
        for(Prodotto prod: this.listaProd)
        {
            ranking.put(prod, (double)prod.getPrezzoAcq()/(prod.getTempoOrd() + prod.getTempoReal()));
        }
        //Ordina il ranking in ordine decrescente.
        ranking = ranking.entrySet().stream().sorted((i, j) -> j.getValue().compareTo(i.getValue())).collect(HashMap::new, (m, c) -> m.put(c.getKey(), c.getValue()), HashMap::putAll);
        return ranking;
    }


}
