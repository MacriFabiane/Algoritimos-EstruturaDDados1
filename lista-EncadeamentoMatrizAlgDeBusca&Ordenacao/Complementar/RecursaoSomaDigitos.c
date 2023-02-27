/*Implemente uma fun��o que receba um n�mero inteiro. A fun��o dever� calcular, utilizando recurs�o, a soma dos d�gitos do n�mero inteiro.

Exemplo:

-- Entrada: 375

-- Sa�da: 3 + 7 + 5 = 15

Input Format

Na primeira linha deve ser lido um n�mero inteiro.

Constraints

.

Output Format

Imprimir o resultado da soma dos d�gitos.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int soma_digitos(int n){
    if (n==0)
        return n;
    else
        return (n%10)+soma_digitos(n/10);
}

int main() {
    int n;
    scanf ("%d", &n);
    printf("%d", soma_digitos(n));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

