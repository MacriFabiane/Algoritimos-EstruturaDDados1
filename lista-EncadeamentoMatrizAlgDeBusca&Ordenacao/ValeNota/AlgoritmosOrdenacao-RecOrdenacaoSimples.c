/*Implemente, utilizando recurs�o, um dos algoritmos de ordena��o simples apresentados em sala de aula (bublesort, selection sort ou insertion sort).

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.

Constraints

Dica: para os c�digos apresentados em aulas, transforme apenas o for externo em recurs�o. Em outras palavras, no seu c�digo pode ter, no m�ximo, apenas um la�o for.

Output Format

Imprimir o vetor ordenado.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectsort2(int v[], int i, int n){
    int j, p, aux;

    if ( i < n - 1){
        p = i;

        for (j = i + 1; j < n; j++)
            if (v[j] < v[p])
                p = j;

        if (p != i){
            aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
        selectsort2(v, i+1, n);
    }
}



int main() {
    int i, n, *v;

    scanf("%d", &n);

    v= (int*) malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    selectsort2(v, 0, n);

    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

