import java.io.*;

public class Main {
    public static void main(String[] args)
    {
        /*
        File file = new File("/home/alessio/Desktop/Prova.txt");
        if(file.exists())//Ritorna true se il file specificato nel pathname esiste effettivamente nella working directory attuale(a meno che il path assoluto non specifichi diversamente).
        {
            System.out.println("Il file esiste");
        }else
        {
            System.out.println("Il file non esiste");
        }
        System.out.println(file.getPath());//Ritorna il path del file come specificato in instanziazione.
        System.out.println(file.getAbsolutePath());//Ritorna il path assoluto del file.
        System.out.println(file.isFile()); //Ritorna true se file è un file normale(non una cartella).
        file.delete();//cancella il file.*/

        try {//Nota che l'instanziazione di un fileWriter/Reader genera eccezioni considerate potenzialmente pericolose. Dovremo quindi fornire un catch per l'IOException.
            FileWriter writer = new FileWriter("/home/alessio/Desktop/Prova.txt");//Se il file non è già presente nell'abspath ne crea uno nuovo.
            writer.write("Ciao, sono Alessio e non dormo un cazzo da settimane!");
            writer.append("\n Aiuto! Per favore!");//Come già noto, append aggiunge al fondo del file, laddove write sovrascrive il contenuto di partenza in chiamata.
            writer.close();
        } catch (IOException e) {
            e.printStackTrace(); //Stampa l'output dell'errore.(Non consigliato per il logging).
        }
        try{
            FileReader reader = new FileReader("/home/alessio/Desktop/Prova.txt");
            int data = reader.read(); //Nota che usiamo ASCII per leggere i caratteri, hence l'uso dell'int poi castato a char.
            while(data != 1) {
                System.out.print((char)data);
                data = reader.read();
            }


        }catch (IOException e){
            e.printStackTrace();
        }

    }


}
