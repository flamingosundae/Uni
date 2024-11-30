public class Main
{
    public static void main(String[] args)
    {
        Leone leone = new Leone();
        Gazzella gazzella = new Gazzella();
        Pesce pesce = new Pesce();

        leone.caccia();
        gazzella.scappa();
        pesce.caccia();
        pesce.scappa();
    }

}
