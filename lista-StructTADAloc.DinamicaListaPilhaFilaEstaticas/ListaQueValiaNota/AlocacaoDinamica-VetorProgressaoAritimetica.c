/*Implemente uma fun��o que receba dois n�meros inteiros, sendo uma para o tamanho do vetor (n) e a outra para raz�o (r). A fun��o dever� retornar um vetor de tamanho n ordenado de forma crescente representado uma sequ�ncia de elementos de uma progress�o aritm�tica iniciada por 0.

Para a implementa��o da solu��o, considere o prot�tipo de fun��o abaixo:

int * prog_arit(int n, int r);
Input Format

Na primeira linha devem ser lidos dois n�meros inteiros, sendo o primeiro referente ao tamanho do vetor e o segundo, � raz�o da progress�o aritm�tica.

Constraints
.

Output Format

Vetor que represente uma sequ�ncia de elementos de uma progress�o aritm�tica.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int * prog_arit(int n, int r){
    int *prog, i;

    prog =(int*)malloc(sizeof(int)*n);

    prog[0]=0;
    for (i=1; i<n; i++)
        prog[i]=prog[i-1]+r;

    return prog;
}
void imprimir (int *prog, int n){
    int i;

    for (i=0; i<n; i++)
        printf ("%d ", prog[i]);
}
int main() {
    int n, r, *prog;

    scanf ("%d %d", &n, &r);

    prog=prog_arit(n, r);

    imprimir(prog, n);


    return 0;
}

