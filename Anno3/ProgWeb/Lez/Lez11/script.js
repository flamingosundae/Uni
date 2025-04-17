"use strict"; //Attiva la modalità strict, dove errori draconiani sono segnalati (senza assunzioni implicite da parte dell'interprete) Garantisce retrocompatibilità con gli ES precedenti.


let testString = "test"; //Definizione di una variabile. Nota che il tipo è implicito, come Python.
let testNum = 5; //Definizione di un int.
let testFloat = 3.1 //Definizione di un float.
let testSum = testNum + testFloat; //Operazioni supportate: +-*/%**
let empty; //Definizione di una variabile vuota. Possiamo anche usare var [variabile], invece di let. Vedremo più tardi la differenza.
let testNull = null;
let testBool = true;
empty = testNum;
let testString2 = "belle palle";
let num = Number("33"); //Conversione di tipi.
let pi = (3.14199999).toFixed(2); //Regola il numero di cifre.
let answer = "45" - 3 //JS supporta la conversione automatica di tipo. Answer sarà un Number.

console.log(testString);
console.log("Wow" + testString2);
