public class Persona {
    private String nome; //Questa è una variabile private, che significa che non sarà accessibile né modificabile da altre classi. La renderemo utilizzabile con i metodi getter/setter.
    private String cognome;
    Persona(String nome, String cognome)
    {
        this.setNome(nome);
        this.setCognome(cognome);
    }

    public void setNome(String nome) { //Metodo setter. Imposta un attributo(di nuovo, da dentro alla classe).
        this.nome = nome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getNome()  //Metodo getter. Ritorna l'attributo richiesto(da dentro alla classe!).
    {
        return nome;
    }

    public String getCognome()
    {
        return cognome;
    }
}

