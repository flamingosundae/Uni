import Models.*;
import Services.*;

import java.time.LocalDate;
import java.util.ArrayList;

public class main
{
    public static void main(String[] args)
    {
        GestoreDipendenti gd = new GestoreDipendenti();
        gd.addDipendente("Alessio", "Fortini", LocalDate.of(2001, 5, 26), LocalDate.of(2022, 1, 23), Dipartimento.MARKETING, Mansione.DESIGN, 8, null);
        gd.addDipendente("Marco", "Gagliardi", LocalDate.of(2001, 7, 6), LocalDate.of(2022, 1, 23), Dipartimento.MARKETING, Mansione.DESIGN, 7, gd.getDipendente(0));
        gd.addDipendente("Leda", "Baol", LocalDate.of(1997, 5, 31), LocalDate.of(2023, 2, 3), Dipartimento.RISORSEUMANE, Mansione.DESIGN, 7, gd.getDipendente(0));
        gd.addDipendente("Giacomo", "Pace", LocalDate.of(2000, 2, 21), LocalDate.of(2020, 1, 13), Dipartimento.SVILUPPO, Mansione.RICERCA, 2, gd.getDipendente(1));

        ArrayList<String> COC = gd.getCOC((gd.getDipendente(3)));
        for(int i = 0; i < COC.size(); i++)
        {
            System.out.println(COC.get(i));
        }
        gd.trovaSost(gd.getDipendente(1));
    }


}
