import java.util.ArrayList;

public class arrayList {
    public static void main(String[] args)
    {
        arrayL(args);
    }

    public static void arrayL(String[] args)
    {
        /*Le ArrayList, a differenza degli array standard, sono dinamici,
        il che vuol dire che non hanno dimensione fissa e supportano l'aggiunta
        e rimozione di elementi. Nota, importantemente, che supportano solo reference e VANNO
        tipizzate in inizializzazione. Non può usare quindi le primitive, ma supporta
        le corrispettive WrapperClasses.
         */
        ArrayList<String > persone = new ArrayList<String>();
        persone.add("Luca");//metodo per aggiungere un elemento ad una ArrayList.
        persone.add("Anna");
        persone.add("Marco");
        persone.set(2, "Paola"); //Metodo per sostituire l'elemento indicizzato dall'int in input con il secondo parametro.
        persone.remove(0);//rimuove l'elemento indiicizzato dall'int in input.
        persone.clear();//Rimuove tutti gli elementi dalla lista.

        for(int i = 0; i < persone.size(); i++)//L'equivalente di .lenght per le arraylist.
        {
            System.out.println(persone.get(i));//Metodo per ottenere l'elemento indicizzato della List dal parametro in input.
        }

        ArrayList<ArrayList<String>> test = new ArrayList();//È possibile anche costruire arraylist di arraylist. Svolgono, a livello concreto, il ruolo degli array2d visti in precedenza.
    }
}
