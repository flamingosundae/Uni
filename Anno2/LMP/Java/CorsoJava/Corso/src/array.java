public class array {

    public static void main(String[] args)
    {

    }

    public static void parliamoDiArray(String[] args)
    {
        int[] num_pari = new int[3];
        /*Nota che come in C, gli array sono STATICI. L'allocazione di memoria è fissa,
         e la creazione di un nuovo array segue gli stessi magheggi di C. Coddio.
         Nota, però, che a differenza di C, gli elementi interni dell'array sono modificabili liberamente,
         senza dover creare un nuovo array da capo.*/
        num_pari[0] = 2;
        num_pari[1] = 4;
        num_pari[2] = 6;

        System.out.println(num_pari.length); //Il metodo array.lenght ritorna la lunghezza dell'array.
        System.out.println(num_pari[0]);//Indicizzazione

        num_pari[0] = 10;
        int[] num_dispari = {1, 3, 5, 7}; //È supportata anche l'inizializzazione tramite elencazione.
        for(int i = 0; i < num_dispari.length; i++)
        {
            System.out.println(num_dispari[i]);
        }
        for(int x: num_dispari)
        {
            System.out.println(x); //Ciclo dell'array con for each.
        }
    }

    public static void array2D(String[] args)
    {
         String[][] classi = new String[3][3]; //nota l'indicizzazione [riga][colonna]
         classi[0][0] = "Luca";
         classi[0][1] = "Anna";
         classi[0][2] = "Marco";

         classi[1][0] = "Edoardo";
         classi[1][1] = "Giovanni";
         classi[1][2] = "Andrea";

         classi[2][0] = "Alessio";
         classi[2][1] = "Orazio";
         classi[2][2] = "Verbena";

         for(int r=0; r < classi.length; r++)
         {
             for(int c = 0; c < classi[r].length; c++)
             {
                 System.out.println(classi[r][c]);
             }
         }

         int[][] numeri =
                 {
                         {1,2,3},
                         {4,5,6},
                         {7,8,9}
                 };
    }

}





