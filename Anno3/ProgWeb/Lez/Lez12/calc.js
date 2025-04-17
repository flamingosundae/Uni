"use strict";
let n1, n2, res;
n1 = prompt("Inserisci il primo numero"); /*Nota che il risultato viene castato come STRINGA, non numero. Dobbiamo quindi convertirlo prima di usarlo.*/
n2 = prompt("Inserisci il secondo numero");
n1 = Number(n1);
n2 = Number(n2);
res = n1 + n2


alert("La somma è" + res);
/*Nota che in modalità non strict, se annulliamo uno dei prompt, otterremo null + numero, dando come risultato il numero.
In modalità strict, ritornerà Nan(not a number).*/

let a = "5"; //Variabile globale.
let b = 5;
alert(a == b); //Ritornerà true, in quanto converterà implicitamente uno dei due.
alert(a === b); //Ritornerà false! === e !== , identico e non identico, ritornano true solo se i due elementi sono identici in DATO E TIPO. 
alert(a ?? b);//Operatore di coaleshing. Ritorna a se a è definito. b altrimenti.
//Truy o falsy: nel caso venga dato in input un valore non booleano, l'interprete assegnerà valori di verità TENDENTI al vero o al falso. E.g. "ciao" è vero (è una stringa), "" è falso (non è una stringa). 100 è vero, ma 0 è falso. Undefined, NaN sono falsi.
//Number(true) = 1; Number(false) = 0. Non fare domande.


function calcolatrice() //esempio di funzione.
{
    let n1, n2, somma;
    n1 = prompt("Primo numero");
    n2 = prompt("Secondo numero");
    res = somma(n1,n2);
    alert("La somma è " + res);
}

function somma(a, b) //Variabili locali. Nota che se viene invocata la funzione con meno parametri, li imposta a undefined, mentre parametri di troppo verranno scartati.
{
    return a + b;
}

calcolatrice();

function print(b = 'ciao!') //Impostazionne di un valore di default.
{
    console.log(b);
}


let sommaFuncExp = function (a, b) //Nota che con le espressioni funzionali non puoi invocare la funzione creata PRIMA della definizione, a differenza di una funzione basic.
{
    let somma = a + b;
    return somma;
}
let s = somma(3, 2);


function ask(question, yes, no)
{
    if (confirm(question)) yes();
    else no();
}

ask
{
    "Do you agree?"
}





let pipo = (a, b) => a + b //Arrow function. Modo più sintetico di definire una funzione. Formato let dato = (parametri) => return.