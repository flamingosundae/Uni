#include <arpa/inet.h>  /* per inet_pton, inet_ntop */
#include <netinet/in.h> /* per struct sockaddr_in */
#include <stdlib.h>     /* per EXIT_SUCCESS, EXIT_FAILURE */
#include <string.h>     /* per memset */
#include <stdio.h>      /* per printf, fprintf, perror */

int main(int argc, char *argv[]) {

    /* Indirizzo IPv4 in notazione decimale puntata (dot-decimal notation) */
    const char *ip_address = "160.80.84.130";

    /*
        Nota relativa all'assegnazione di cui sopra: i valori letterali "stringa"  sono
        memorizzati in aree di memoria non scrivibili. Nonostante formalmente il tipo
        del literal sia char *, ho preferito usare il tipo const char *
        Si noti la posizione di "const":
        const T *ptr -> ptr e' un puntatore a una costante di tipo T
        char * T const ptr -> ptr e' un puntatore constante a una valore di tipo T (che si può modificare)
        const T * const ptr -> ne' l'indirizzo contenuto nel puntatore ne' l'area di memoria
        cui si riferisce possono essere cambiati
    */
    
    /*
        Struttura usata per descrivere l'indirizzo di una socket Internet (IPv4):
        indirizzo IP (struct in_addr sin_addr) e numero di porta (in_port_t sin_port).
    */
    struct sockaddr_in host_address; /* Esistono altre strutture sockaddr_XX per altre famiglie di indirizzi */
    memset(&host_address, 0, sizeof(host_address)); /* Setta il contenuto della zona di memoria nel primo argomento al valore del secondo, con il terzo che indica QUANTA memoria sta venendo modificata.*/
    
    host_address.sin_family = AF_INET; /*Con questa struttura modifichiamo la Socket Internet Family(SIN) della socket di input. In particolare, specifichiamo
    che la nostra socket fa parte della famiglia di indirizzi IPv4, con la dicitura standard AF_INET. Per gli IPv6 si usa AF_INET6.*/

    /*Non ti è sostanziale sapere le differenze fra IP4 e IP6, ma in generale, IP6 ha maggiore spazio di indirizzamento, è più sicuro ed è più flessibile.*/
    
    /*
        Converte una stringa che contiene un indirizzo di rete Internet (vedi prefisso inet_) IPv4 (vedi AF_INET, invece AF_INET6 per IPv6)
        nella sua rappresenta binaria per la rete (che posso usare per popolare il campo sin_addr dellla struttura sockaddr_in).

        Nota mnemonica:
        inet_ sta per Internet
        p sta per presentation (Il formato in char in base 10 puntato, tratto dagli 8 bit per numero. In IPv6 si usa l'hex).
        to ... be' indica una conversione
        n sta per network(Il valore che permette effettivamente alla socket di essere identificata nella rete).

        La funzione originale si chiamera inet_(p)(to)(n).
        L'inversa sarà inet_(n)(to)(p).
    */
    int rv = inet_pton(AF_INET, ip_address, &host_address.sin_addr); /* Il valore di ritorno permette permette di riconoscere possibili errori. 
    Abbiamo preso l'indirizzo in formato presentato(secondo parametro), convertito poi in formato binario/network utilizzabile dalla socket e scritto nel campo sin_addr della socket(terzo parametro).*/
    if (rv == 0) {
        fprintf(stderr, "Stringa non valida: %s", ip_address); /* Uso fprintf per passare stderr al fine di scrivere sullo standard error (invece che sullo standard output)*/
        return EXIT_FAILURE;
    } else if (rv == -1) { /* Si è verificato un errore.*/
        perror("inet_pton");
        return EXIT_FAILURE;
    } /* Else rv == 1 operazione riuscita */


    printf("Indirizzo IP numerico: %u\n", host_address.sin_addr.s_addr); /* Lo specificatore di formato %u sta per unsigned int 
    La struttura sin_addr ha un solo campo, s_addr, che abbiamo riempito con l'inet_pton di prima.*/

    printf("Spezziamo l'indirizzo IP nelle sue componenti: %d.%d.%d.%d\n",
        (host_address.sin_addr.s_addr >> 24) & 0xFF,
        (host_address.sin_addr.s_addr >> 16) & 0xFF,
        (host_address.sin_addr.s_addr >> 8) & 0xFF,
        (host_address.sin_addr.s_addr & 0xFF)
        /*Estraiamo le 4 parti dell'address, effettuando progressivi shift a destra. L'and con 0xFF viene usato per riportare l'ottetto che stiamo estraendo al risultato originale.*/
    ); /* Sulle macchine Intel stampa 130.84.80.160 (perche'? R. network byte order, ovvero big-endian) */


    /*Convertibile in LE con
        uint32_t swap_endian(uint32_t num) 
    {
        return ((num>>24)&0xff)      | // sposta l'ottetto più a sinistra più a destra
        ((num<<8)&0xff0000)   | // sposta il secondo ottetto a sinistra al secondo a destra
        ((num>>8)&0xff00)     | // sposta il secondo ottetto a destra al secondo a sinistra
        ((num<<24)&0xff000000); // sposta l'ottetto più a destra più a sinistra
    }*/

    const int STRING_LENGTH = 15; //255.255.255.255 
    char address_string[STRING_LENGTH + 1];  /*Un carattere in piu' per il terminatore della stringa*/

    /* Conversione di una struttura che rappresenta un indirizzo di rete (IPv4) in stringa */
    if (!inet_ntop(AF_INET, &host_address.sin_addr.s_addr, address_string, sizeof(address_string))) { /* restituisce NULL in caso di errore */
        perror("inet_ntop");
        return EXIT_FAILURE;
    }

    printf("Indirizzo IP come stringa: %s\n", address_string);

    return EXIT_SUCCESS;
}