import Models.CompSing;
import Models.Prodotto;
import Models.Componente;
import Services.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        //Classe main che fornisca un esempio d'uso delle classi Prodotto, CompSing e Componente, e GestoreProd.
        //Il main deve creare un oggetto di tipo GestoreProd e aggiungere almeno 3 prodotti con relativi componenti.
        //Infine deve stampare a video i prodotti e il ranking dei prodotti.
        //Il main deve essere scritto in modo da non generare errori di compilazione.
        //Codice:
        GestoreProd gestoreProd = new GestoreProd();
        Componente comp1 = new Componente("comp1", "prov1", 1, 1, false);
        Componente comp2 = new Componente("comp2", "prov2", 2, 2, false);
        Componente comp3 = new Componente("comp3", "prov3", 3, 3, false);
        Componente comp4 = new Componente("comp4", "prov4", 4, 4, false);
        Componente comp5 = new Componente("comp5", "prov5", 5, 5, false);
        Componente comp6 = new Componente("comp6", "prov6", 6, 6, false);
        Componente comp7 = new Componente("comp7", "prov7", 7, 7, false);
        Componente comp8 = new Componente("comp8", "prov8", 8, 8, false);
        Componente comp9 = new Componente("comp9", "prov9", 9, 9, false);
        CompSing compSing1 = new CompSing(comp1, 1);
        CompSing compSing2 = new CompSing(comp2, 2);
        CompSing compSing3 = new CompSing(comp3, 3);
        CompSing compSing4 = new CompSing(comp4, 4);
        CompSing compSing5 = new CompSing(comp5, 5);
        CompSing compSing6 = new CompSing(comp6, 6);
        CompSing compSing7 = new CompSing(comp7, 7);
        CompSing compSing8 = new CompSing(comp8, 8);
        CompSing compSing9 = new CompSing(comp9, 9);
        ArrayList<CompSing> listaComp1 = new ArrayList<>();
        listaComp1.add(compSing1);
        listaComp1.add(compSing2);
        listaComp1.add(compSing3);
        ArrayList<CompSing> listaComp2 = new ArrayList<>();
        listaComp2.add(compSing4);
        listaComp2.add(compSing5);
        listaComp2.add(compSing6);
        ArrayList<CompSing> listaComp3 = new ArrayList<>();
        listaComp3.add(compSing7);
        listaComp3.add(compSing8);
        listaComp3.add(compSing9);
        Prodotto prod1 = new Prodotto(1, "prod1", listaComp1, 1);
        Prodotto prod2 = new Prodotto(2, "prod2", listaComp2, 2);
        Prodotto prod3 = new Prodotto(3, "prod3", listaComp3, 3);
        gestoreProd.addprod(prod1);
        gestoreProd.addprod(prod2);
        gestoreProd.addprod(prod3);
        gestoreProd.PresentazioneProd();
        gestoreProd.rankingProd();

    }





}
