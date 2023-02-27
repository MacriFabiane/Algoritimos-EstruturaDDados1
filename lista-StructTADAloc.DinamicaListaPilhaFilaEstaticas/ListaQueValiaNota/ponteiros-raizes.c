//ponteiros-raizes
/*Implemente uma fun��o que receba 3 vari�veis e 2 ponteiros do tipo float, conforme o seguinte cabe�alho de fun��o:

void raizes(float A, float B, float C, float *X1, float *X2);
A fun��o dever� calcular as ra�zes de uma equa��o de segundo grau: , onde o endere�o apontado po X1 dever� conter o resultado da seguinte opera��o: . J� o endere�o apontado po X2 dever� conter o resultado da seguinte opera��o: .

Input Format

Na primeira linha, devem ser lidas as seguintes vari�veis em sequ�ncia: A, B e C

Constraints
.

Output Format

Na pr�xima linha, imprimir os valores de X1 e X2 em sequ�ncia.*/
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void raizes (float A, float B, float C, float *X1, float *X2){

    *X1= (-B+sqrt((double)((B*B)-(4*A*C))))/(2*A); //se o numerador der 0.0 e o denominador for negativo fica -0.0 entao
    *X2= (-B-sqrt((double)((B*B)-(4*A*C))))/(2*A);//temos que mudar o valor para 0.0
    if (*X1== -0.0){
        *X1=0.0;
        printf ("%.1f %.1f", *X1, *X2);
    }
    else if (*X2 ==-0.0){
        *X2=0.0;
        printf ("%.1f %.1f", *X1, *X2);
    }
    else
        printf ("%.1f %.1f", *X1, *X2);
}


int main() {

    float a, b, c, x1, x2;
    scanf ("%f %f %f\n",&a, &b, &c);
    raizes(a, b, c, &x1, &x2);

    return 0;
}

