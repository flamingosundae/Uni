#definizione var. decisionali.

var x1, x2, x3 >= 0;

#definizione funzione bersaglio

maximize Objective:
    4 * x1 + 3*x2 + 5*x3;
;


#definizione vincoli
subject to C1: x1 + 2*x2 + 2*x3 <= 4;

subject to C2: 3*x1 + 4*x3 <= 6;

subject to C3 : 2*x1 + x2 + 4*x3 <= 8;