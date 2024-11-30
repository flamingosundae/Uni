package Models;

public class CompSing {
    private Componente comp;
    private int numNec;

    public CompSing(Componente comp, int numNec)
    {
        this.comp = comp;
        this.numNec = numNec;
    }

    public Componente getComp() {
        return comp;
    }

    public void setComp(Componente comp) {
        this.comp = comp;
    }

    public int getNumNec() {
        return numNec;
    }

    public void setNumNec(int numNec) {
        this.numNec = numNec;
    }
}
