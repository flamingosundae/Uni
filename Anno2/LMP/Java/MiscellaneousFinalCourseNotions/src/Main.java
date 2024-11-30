import java.time.*;
import java.time.format.DateTimeFormatter;

public class Main {

    public static void main(String[] args)
    {
        double x = 9.5f;//Nota che questo è un casting implicito. Abbiamo inizializzato un float in valore, ma è castato implicitamente in un double(in quanto semplicemente un float con più precisione).
        System.out.println(x);
        int y = (int) 9.5;//Questa è un'operazione di casting esplicito.
        LocalDate a = LocalDate.now(); //Restituisce la data nel formato yyyy-mm-dd.
        DateTimeFormatter itaFormat = DateTimeFormatter.ofPattern("EEEE/dd/MM/yyyy");
        LocalTime b = LocalTime.now(); //Restituisce l'ora nel formato ora:minuti:secondi:nanosecondi.
        LocalDateTime c = LocalDateTime.now();//Restituisce la combinazione dei due sopra.
        System.out.println(a.format(itaFormat));



    }
}
