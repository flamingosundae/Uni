import java.util.ArrayList;
import java.util.Iterator;

public class Iteratore {
    public static void main(String[] args)
    {
        ArrayList<String> persone = new ArrayList<>();
        persone.add("Luca");
        persone.add("Marco");
        persone.add("Anna");
        persone.add("Paolo");

        Iterator<String> it = persone.iterator();
        while (it.hasNext())
        {
            String persona = it.next();
            if(persona == "Anna")
            {
                it.remove();
            }
        }
    }
}
