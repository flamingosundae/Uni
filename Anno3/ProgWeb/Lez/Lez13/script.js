"use strict";

let a = {
    nome : "Pippo",
    cognome : "Cazzo",
    età : 80,
    scores : [1, 2, 3],
    lezioni : {pw : 30, fi: 18},
    saluta : function()
    {
        alert("Ciao!");
    },
    salutanome : function()
    {
        alert("Ciao! Sono" + this.nome); //Accesso ad un'altra proprietà dell'oggetto tramite this.proprietà. Valutato a call-time, non in definizione di funzione.
    }
}; //Creazione di un nuovo oggetto. Un oggetto è una lista di coppie proprietà - valore, i quali possono essere dati primitivi, altri oggetti o funzioni.
//Nota che nonostante le similitudini a java, NON ci sono valori privati.

a.voto = 12; //Aggiunta proprietà.

console.log(a.voto);
console.log(a["voto"]); //Accesso ad una proprietà. Non ci sono differenze salienti fra i metodi.

delete a.lezioni; //Rimozione proprietà.


d = a; //Nota che questo non COPIA l'oggetto, ma crea un nuovo puntatore all'oggetto preesistente. Per creare un nuovo oggetto, dovremo fare:
c = {}

a.saluta(); //Ogni funzione definita in un oggetti sarà chiamato metodo.

function sayMyName()
{
    alert("My name is! uh! My name is" + this.name);
}

a.myName = sayMyName; //Binding di funzione.
b.myName = sayMyName;
sayMyName(); //Nota che chiamando la funzione non bindata, this.name non sarà bindato a nulla, quindi uscirà undefined.

function User(name) //Costrruttore di oggetti. 
{
    this.name = name;
    this.isAdmin = false;
}

let user = new User("Contedellepalle");

let arr = [5, "ciao", true, undefined];
//Classico array. Nota che può contenere oggetti diversi.
console.log(arr[0]);
arr.push("Prova"); //Push di un elemento in fondo.
arr.unshift("Prova2") //Push di un elemento in cima.
arr[1] = "Lelelelelelelelel";
arr.pop();//Rimozione di un elemento in fondo, poi ritornato.
arr.shift();//Rimozione di un elemento in cima, poi ritornato.
arr.length();//Ritorna la lunghezza dell'array.
//Nota che eliminando elementi interni, NON viene riallocato l'array, ma viene sostituito l'elemento cancellato con un elemento EMPTY. Per deallocare gli empty, dovremo ridefinire l'array nuovamente.
let arrB= [1, 2, 3, 4, 5];
let arrsliced = arrB.slice(1, 3); //Slicing dell'array. Return [2, 3, 4]
let arrspliced = arrB.splice(3, 2); //Cancella i primi [secondo indice] elementi a partire dalla posizione [primo indice], includendo anche l'elemento in posizione [primo indice], poi li ritorna. Return [4, 5], con b = [1, 2, 3].
arrB.indexOf('1') //Ricerca di un elemento nell'array. Ritorna l'indice di posizione dell'array.

let arrC = ["uno", "due", "tre", "quattro", "cinque"];

function itLenght(item, idx, array)
{
    console.log(item.length);
}

arrC.map(itLenght); //Richiama la funzione richiesta su OGNI OGGETTO dell'array, nel formato map(item(i-esimo oggetto dell'array), index(indice oggetto, partendo da 0), array(l'array))


let names = ["tizio", "caio", "sempronio"];

