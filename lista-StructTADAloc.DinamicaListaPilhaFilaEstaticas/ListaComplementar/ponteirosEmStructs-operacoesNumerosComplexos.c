/*Dada a estrutura abaixo:

typedef struct{
    float real, img, mod;
}complexo;
Implemente uma fun��o que receba um ponteiro do tipo complexo e duas vari�veis est�ticas do tipo float que represente as partes real e imagin�ria de um n�mero complexo. A partir das var�veis do tipo float, os campos das estrutura devem ser atualizados.

Em seguida, imprima os campos do "complexo" no seguinte formato: real sinal img i.

Para a implementa��o do exerc�cio proposto considere o seguinte prot�tipo de fun��o e a equa��o abaixo:

void atualizar_complexo(complexo *c, float real, float img);
M�dulo de um n�mero complexo:

z = sqrt(real * real + img * img);

Para o c�lculo da raiz quadrada, voc� pode utilizar a fun��o sqrt da biblioteca math.h.

Input Format

Na primeira linha deve ser lido dois dados do tipo float.

Constraints
.

Output Format

Na primeira linha deve ser impresso o n�mero complexo no seguinte formato: real sinal_numero_imagin�rio img i

Na segunda linha, deve ser impresso o m�dulo do n�mero complexo.

Para a impress�o de floats, considere a precis�o de uma casa decimal (%.1f).*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float real, img, mod;
}complexo;

void atualizar_complexo(complexo *c, float real, float img){
    c->real= real;
    c->img =img;
    c->mod = sqrt(real * real + img * img);
}

int main() {

    complexo c;
    float r, i;

    scanf ("%f %f", &r, &i);

    atualizar_complexo(&c, r, i);

    if (c.img>=0)
       printf ("%.1f+%.1fi\n", c.real, c.img);
    else
        printf("%.1f%.1fi\n", c.real, c.img);

    printf ("%.1f", c.mod);

    return 0;
}
