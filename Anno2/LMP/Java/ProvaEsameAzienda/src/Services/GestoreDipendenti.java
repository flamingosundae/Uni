package Services;
import Models.*;

import java.time.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.NoSuchElementException;

public class GestoreDipendenti {

    private ArrayList<Dipendente> listaDipendenti;

    public GestoreDipendenti() {
        this.listaDipendenti = new ArrayList<>();
    }

    public void addDipendente(Dipendente dipendente) {
        this.listaDipendenti.add(dipendente);
    }

    public void addDipendente(String nome, String cognome, LocalDate dataNascita, LocalDate dataAssunzione, Dipartimento dipartimento, Mansione mansione, int livello, Dipendente capo) {
        Dipendente nuovoDip = new Dipendente(nome, cognome, dataNascita, dataAssunzione, dipartimento, mansione, livello, capo);
        this.listaDipendenti.add(nuovoDip);
    }

    public Dipendente getDipendente(String nome, String cognome) {
        for (Dipendente dipendente : this.listaDipendenti) {
            if (dipendente.getNome().equals(nome) && dipendente.getCognome().equals((cognome))) {
                return dipendente;
            }
        }
        throw new NoSuchElementException("Il dipendente cercato non esiste!");
    }

    public Dipendente getDipendente(String numMatricola)
    {
        for(Dipendente dipendente: this.listaDipendenti)
        {
            if(dipendente.getNumMatricola().equals(numMatricola))
            {
                return dipendente;
            }
        }
        throw new NoSuchElementException("Nessun dipendente ha questa matricola");
    }

    public ArrayList<String> getCOC(Dipendente dipendente)
    {
        ArrayList<String> COC = new ArrayList<>();
        Dipendente currDip = dipendente;

        while(currDip.getCapo() != null)
        {
            COC.add(currDip.getCapo().getNome() + currDip.getCapo().getCognome());
            currDip = currDip.getCapo();
        }
        return COC;
    }

    public Dipendente trovaSost(Dipendente dipendente)
    {
        for(Dipendente dip: this.listaDipendenti)
        {
            if(dip == dipendente || dip.getCapo() == null)
            {
                continue;
            }

            if(dip.getMansione().equals(dipendente.getMansione()) && dip.getCapo().equals(dipendente.getCapo()))
            {
                System.out.println("L'impiegato " + dipendente.getNome() + dipendente.getCognome() + "è sostituibile con " + dip.getNome()+ dip.getCognome());
                return dip;
            }
        }
        throw new NoSuchElementException("L'impiegato è insostituibile");
    }


    public ArrayList<Dipendente> sameYearOfHire() {
        ArrayList<Dipendente> dipSameYearOfHire = new ArrayList<>();

        for (Dipendente d1 : this.listaDipendenti) {
            for (Dipendente d2 : this.listaDipendenti) {
                if (!d1.equals(d2)) {
                    if (d1.getDipartimento().equals(d2.getDipartimento()) &&
                            d1.getDataAssunzione().getMonth() == d2.getDataAssunzione().getMonth() &&
                            d1.getDataAssunzione().getYear() == d2.getDataAssunzione().getYear()) {
                        dipSameYearOfHire.add(d1);
                    }
                }
            }
        }

        return dipSameYearOfHire;

    }

    public Dipendente getDipendente(int pos)
    {
        return listaDipendenti.get(pos);
    }

}




