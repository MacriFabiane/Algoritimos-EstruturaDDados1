/*Dada a estrutura abaixo:

typedef struct{
    float raio, area, volume, diametro;
}esfera;
Implemente uma fun��o que receba um ponteiro do tipo esfera e uma vari�vel est�tica do tipo float que represente um valor de raio. A partir da var�vel do tipo float, os campos das estrutura devem ser atualizados.

Em seguida, imprima os campos da "esfera".

Para a implementa��o do exerc�cio proposto considere o seguinte prot�tipo de fun��o e as equa��es, onde pi = 3.14:

void atualizar_esfera(esfera *e, float r);
area = 4 * pi * R�

volume = (3/4) * pi * R�

diametro = 2 * R

Input Format

Na primeira linha da entrada deve ser lido um �nico float.

Constraints

.

Output Format

Em cada linha deve ser impresso, considerando uma casa decimal, um campo da esfera na seguinte sequ�ncia: raio, �rea, volume e di�metro.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14

typedef struct{
    float raio, area, volume, diametro;
}esfera;

void atualizar_esfera(esfera *e, float r){
    e->raio =r;
    e->area = 4.0 *pi* pow(r,2);
    e->volume = (3.0/4.0)*pi*pow(r,3);
    e->diametro = 2.0*r;
}

int main() {

    float raio;
    esfera e;
    scanf ("%f", &raio);

    atualizar_esfera (&e, raio);
    printf ("raio: %.1f\n", e.raio);
    printf ("area: %.1f\n", e.area);
    printf ("volume: %.1f\n", e.volume);
    printf ("diametro: %.1f\n", e.diametro);

    return 0;
}
