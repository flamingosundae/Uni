public class Auto extends Veicolo
{

    @Override
    void muovi()
    {
        System.out.println("Vroom vroom");
    }

    @Override
    void frena()
    {
        System.out.println("Non vroom non vroom");
    }
}
