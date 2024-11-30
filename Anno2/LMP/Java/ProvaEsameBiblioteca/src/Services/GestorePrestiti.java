package Services;
import Models.*;

import java.time.LocalDate;
import java.time.Period;

public class GestorePrestiti {


    public int checkMaxPeriod(Supporto supporto)
    {
        int max_prest_duration = 0;
        for(int i = 0; i < supporto.get_list_size(); i++)
        {
            LocalDate date_start = supporto.get_prest(i).getDataInitPrest();
            LocalDate date_end = supporto.get_prest(i).getDataRicEffett();
            Period currentPrestPer = date_start.until(date_end);
            int tot_time = currentPrestPer.getDays() + (currentPrestPer.getMonths() * 30) + (currentPrestPer.getYears() * 365);
            if(tot_time > max_prest_duration)
            {
                max_prest_duration = tot_time;
            }
        }
        return max_prest_duration;
    }

    public String checkInconsist(Supporto supporto)
    {
        for(int i = 0; i < supporto.get_list_size()-1; i++)
        {
            LocalDate prestito_curr = supporto.get_prest(i).getDataRicEffett();
            LocalDate prestito_succ = supporto.get_prest(i+1).getDataInitPrest();
            if(prestito_succ.isBefore(prestito_curr))
            {
                return("Trovata un'inconsistenza fra il prestito " + i + " finito il" + prestito_curr + " e il prestito " + (i+1) + "iniziato il " + prestito_succ);
            }
        }
        return "Nessuna inconsistenza trovata";
    }

    public void modGiornoRic(int giorniNuovi, Supporto supporto)
    {
        Prestito prest = supporto.get_prest(supporto.get_list_size()-1);
        prest.setGiorniRicPrev(giorniNuovi);
        prest.setDataRicPrev(prest.getDataInitPrest().plusDays(giorniNuovi));
    }

}
