/*Crie uma struct para representar um n�mero racional, ou seja, nessa estrutura deve haver os seguintes campos: numerador e denominador.
Em seguida, crie uma fun��o que receba dois n�meros racionais. A fun��o dever� retornar um outro n�mero racional resultante da divis�o dos n�meros fornecidos como entrada.
A primeira linha � composta pelo numerador e denominador, respectivamente, do primeiro n�mero racional.
A segunda linha � composta pelo numerador e denominador, respectivamente, do segundo n�mero racional.
Constraints
As entradas lidas devem ser armazenadas em var�aveis do tipo de estrutura que voc� criou.
Output Format
N�mero racional resultante da divis�o dos n�meros fornecidos como entrada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct racional{
    int numerador;
    int denominador;
    
}racional;

racional divisao (racional n1, racional n2)
{
    racional n3;
    
    n3.numerador= n1.numerador * n2.denominador;
    n3.denominador= n1.denominador * n2.numerador;

    return n3;
}
int main() {
    racional n1;
    racional n2;
    racional n;
    
    scanf("%d %d", &n1.numerador, &n1.denominador);
    scanf("%d %d", &n2.numerador, &n2.denominador);
    
    n=divisao(n1,n2);
    
    printf ("%d %d", n.numerador, n.denominador);
    
    return 0;
}
