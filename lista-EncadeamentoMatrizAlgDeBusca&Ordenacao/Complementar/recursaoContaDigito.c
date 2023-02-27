/*Escreva uma fun��o recursiva para determinar quantas vezes um determinado d�gito X ocorre em um n�mero N. Por exemplo, o d�gito 3 ocorre 4 vezes em 3304353.

Input Format

Na primeira linha, devem ser lidos dois n�meros inteiros: o primeiro deve ser o d�gito a ser procurado e o segundo deve ser o n�mero natural onde o d�gito � procurado.

Constraints

.

Output Format

Imprimir a quantidade de vezes que o d�gito procurado ocorre.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int conta_digito (int d, int n){
    if ((abs(n)>=0) &&(abs(n)<=9))
        return n ==d;
    else
        return ((n%10)==d)+conta_digito (d, n/10);
}
int main() {
    int d, n;
    scanf("%d %d", &d, &n);
    printf("%d", conta_digito(d, n));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
