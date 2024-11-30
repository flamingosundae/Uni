public class Main {
    /*L'incapsulamento è una parte fondamentale
    della programmazione ad oggetti. Attraverso
    il controllo dell'accesso ai vari attributi e metodi
    delle classi usando i vari modificatori(private, public, protected)
    Nascondiamo i dettagli interni del funzionamento ad utenti esterni,
    rendendo più facile 1)L'utilizzo per chi non ha familiarità con la programmazione
    2)La manutenzione ed updating per futuri utilizzi.
    3)La sicurezza.
     */
    public static void main(String[] args)
    {
        Persona persona = new Persona("Luca", "Rossi");
        System.out.println(persona.getNome());
    }
}
