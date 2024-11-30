public class Pesce implements Preda,Predatore {

    @Override
    public void caccia()
    {
        System.out.println("Il pesce grosso sta cacciando...");
    }

    public void scappa()
    {
        System.out.println("Il pesce piccolo sta scappando...");
    }
}
