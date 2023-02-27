/*Implemente uma fun��o recursiva que calcule o m�ximo divisor comum entre dois n�meros inteiros: -> mdc(x, y) = y, se x >= y e x mod y = 0 -> mdc(x, y) = mdc(y, x), se x < y -> mdc(x, y) = mdc(x, x mod y), caso contr�rio

Input Format

Na primeira linha devem ser lidos dois n�meros inteiros.

Constraints

.

Output Format

Imprimir o m�ximo divisor comum entre os dois n�meros.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int mdc(int a, int b){
    if (b==0)
        return a;
    else
        return mdc(b, a%b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf ("%d", mdc(a,b));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

