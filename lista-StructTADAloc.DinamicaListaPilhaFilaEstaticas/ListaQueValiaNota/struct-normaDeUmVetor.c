/*Considerando uma estrutura para representar um vetor no R2, implemente um programa que calcule norma (ou m�dulo) do mesmo. Use o prot�tipo de fun��o abaixo

struct vetor_t{
    float x;
    float y;
    float norm;
};

vetor_t calculaNorma(vetor_t vetor){

}

int main(){

}
Input Format

A primeira linha da entrada cont�m um �nico n�mero indicando quantos pontos ser�o lidos. Seguem os valores de x e y.

Output Format

A sa�da deve apresentar o valor da norma com precis�o de 1 casa decimal*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct vetor_t{
    float x;
    float y;
    float norm;
}vetor_t;
// declarei novo tipo com a struct o tipo vetor_t

vetor_t calculaNorma (vetor_t vet)
{

    vetor_t norma;
    norma.norm=sqrt(( vet.x*vet.x)+( vet.y*vet.y));

    return norma;
}

int main() {

    int i, tam;
    scanf ("%d", &tam);
    vetor_t vet[tam];

    for (i=0; i<tam; i++)
    {
        scanf("%f %f", &vet[i].x, &vet[i].y);
        printf("Norma = %.1f\n", calculaNorma(vet[i]).norm);
    }

    return 0;
}
