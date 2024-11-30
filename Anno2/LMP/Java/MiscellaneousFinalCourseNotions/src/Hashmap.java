import java.util.HashMap;

public class Hashmap {
    public static void main(String[] args) {
        HashMap<String, String> capitali = new HashMap<>(); //Una HashMap ci permette, similmente ai dizionari di Python, di memorizzare delle coppie <chiave, valore>.

        capitali.put("Italia", "Roma");//Il metodo put aggiunge una coppia chiave valore alla map. Nota che ad ogni chiave può essere associato ad un solo valore. I.e., per valori multipli dovremo usare un array/arraylist.
        capitali.put("Francia", "Parigi");
        capitali.put("Germania", "Berlino");

        capitali.remove("Francia"); //Rimuove la voce legata alla chiave in input.
        capitali.clear();//Svuota la map.


    }
}
