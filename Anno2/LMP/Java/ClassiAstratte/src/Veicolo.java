public abstract class Veicolo
{
    /*Questa è una classe ASTRATTA.
    Ciò significa che NON può essere istanziata,
    di per sé, ma esiste solo per essere sottoclassata.
    Può avere due tipi di metodi, astratti(vuoti, vanno
    NECESSARIAMENTE implementati dalle sottoclassi se non
    astratte anche loro) o concreti(già implementati e utilizzabili).
     */

    abstract void muovi();//Metodo astratto. Come detto prima, va implementato. Non ha un void.
    abstract void frena();
}
