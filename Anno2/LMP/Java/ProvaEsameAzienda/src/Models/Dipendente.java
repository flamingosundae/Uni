package Models;
import java.time.LocalDate;


public class Dipendente {
    private String nome;
    private String cognome;
    private LocalDate dataNascita;
    private LocalDate dataAssunzione;
    private String numMatricola;
    private static int nIscr = 0;
    private Dipartimento dipartimento;
    private Mansione mansione;
    private int livello;
    private Dipendente capo = null;


    public Dipendente(String nome, String cognome, LocalDate dataNascita, LocalDate dataAssunzione, Dipartimento dipartimento, Mansione mansione, int livello, Dipendente capo)
    {
        this.nome = nome;
        this.cognome = cognome;
        this.dataNascita = dataNascita;
        this.dataAssunzione = dataAssunzione;
        this.numMatricola = "CLT_" + (nIscr++);
        this.dipartimento = dipartimento;
        this.mansione = mansione;
        setLivello(livello);
        this.capo = capo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public void setDataAssunzione(LocalDate dataAssunzione) {
        this.dataAssunzione = dataAssunzione;
    }

    public LocalDate getDataAssunzione() {
        return dataAssunzione;
    }

    public void setDataNascita(LocalDate dataNascita) {
        this.dataNascita = dataNascita;
    }

    public LocalDate getDataNascita() {
        return dataNascita;
    }

    public void setLivello(int livello) {
        if(livello < 1 || livello > 8)
        {
            throw new IllegalArgumentException("Il livello deve essere compreso fra 1 e 8");
        }
        this.livello = livello;
    }

    public int getLivello() {
        return livello;
    }

    public void setCapo(Dipendente capo) {
        this.capo = capo;
    }

    public Dipendente getCapo() {
        return capo;
    }

    public void setDipartimento(Dipartimento dipartimento) {
        this.dipartimento = dipartimento;
    }

    public Dipartimento getDipartimento() {
        return dipartimento;
    }

    public void setMansione(Mansione mansione) {
        this.mansione = mansione;
    }

    public Mansione getMansione() {
        return mansione;
    }

    public String getNumMatricola() {
        return numMatricola;
    }
}
