











                    max_tempo = usePer;
                    minTime = tempoStim;
                LocalTime start = listaPrest.get(i).getOraRichiesta();
                LocalTime startTime = uso.getOraRichiesta();
                LocalTime stop = listaPrest.get(i).getOraRiconsegna();
                LocalTime tempoStim = startTime.plus(giocoRic.getDurataPartita(), MINUTES);
                if (tempoStim.isBefore(minTime))
                if(usePer > max_tempo)
                long usePer = start.until(stop, ChronoUnit.MINUTES);
                {
                {
                }
                }
            LocalTime tempoRim = checkExpTime(giocoRic);
            System.out.println("Non ci sono copie disponibili di "+ giocoRic.getTitolo());
            System.out.println("Non ci sono copie disponibili di" + libroRic.getTitolo());
            System.out.println("Orario di disponibilità: " + tempoRim);
            giocoRic.setnCopie(giocoRic.getnCopie()-1);
            if(listaPrest.get(i).getProdotto() == prod)
            if(uso.getProdotto() == giocoRic)
            libroRic.setnCopie(libroRic.getnCopie()-1);
            listaPrest.add(new Uso(giocoRic, oraRic, cliente));
            listaPrest.add(new Uso(libroRic, oraRic, cliente));
            {
            {
            }
            }
        LocalTime minTime = LocalTime.of(23, 59);
        else
        else
        for (int i = 0; i < listaPrest.size(); i++)
        for(Uso uso: listaPrest)
        if(giocoRic.getnCopie() == 0)
        if(libroRic.getnCopie() == 0)
        long max_tempo = 0;
        prestTerm.put(prodottoUsato.toString(), giornoPrest);
        prodottoUsato.setOraRiconsegna(oraRic);
        return max_tempo;
        return minTime;
        {
        {
        {
        {
        {
        {
        }
        }
        }
        }
        }
        }
    private ArrayList<Uso> listaPrest = new ArrayList<>();
    private HashMap<String, LocalDate> prestTerm = new HashMap<>();
    public LocalTime checkExpTime(GiocoTavolo giocoRic)
    public long checkMaxUsage(Prodotto prod) {
    public void richiesta(GiocoTavolo giocoRic, LocalTime oraRic, String cliente)
    public void richiesta(Libro libroRic, LocalTime oraRic, String cliente)
    public void riconsegna(Uso prodottoUsato, LocalTime oraRic, LocalDate giornoPrest)
    {
    {
    {
    {
    }
    }
    }
    }
    }
import Models.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.HashMap;
import static java.time.temporal.ChronoUnit.MINUTES;
package Services;
public class GestorePrestiti {
}
