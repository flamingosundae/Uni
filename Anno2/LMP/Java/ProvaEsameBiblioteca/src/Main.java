import Models.*;
import Services.*;
import java.time.LocalDate;

public class Main {

    public static void main(String[] args)
    {
        Libro libro1 = new Libro("Il signore degli anelli", "Feltrinelli", 1999, 800);
        DVD DVD1 = new DVD("Biancaneve", "Disney", 1992, 150);
        GestorePrestiti gp = new GestorePrestiti();
        libro1.add_prest(LocalDate.of(2024, 5, 20), LocalDate.of(2024, 5, 30), "Alessio Fortini", 20);
        libro1.add_prest(LocalDate.of(2024, 6, 30), LocalDate.of(2024, 7, 30), "Giovanni Bianchi", 15);
        libro1.add_prest(LocalDate.of(2024, 8, 1), LocalDate.of(2024, 10, 1), "Marco Verdi", 10);
        DVD1.add_prest(LocalDate.of(2024, 7, 12), LocalDate.of(2024, 10, 9), "Luca Neri", 8);
        DVD1.add_prest(LocalDate.of(2024, 8, 12), LocalDate.of(2024, 9, 12), "Giovanni Rossi", 20);
        System.out.println("Il massimo periodo in cui Il signore degli anelli è stato prestato è " + gp.checkMaxPeriod(libro1) + "giorni");
        System.out.println(gp.checkInconsist(DVD1));

    }

}
