/*Implemente uma fun��o que receba, pelo menos, uma chave e um vetor do tipo inteiro. A fun��o dever� efetuar, utilizando recurs�o, busca sequencial em vetores.

Input Format

Na primeira linha deve ser lido o tamanho do vetor.

Na segunda linha devem ser lidos os elementos do vetor.

Na terceira linha deve ser lido o n�mero de casos de teste (quantidade de chaves que dever�o ser procuradas).

A partir da pr�xima linha, as chaves que ser�o procuradas devem ser lidas.

Constraints

.

Output Format

Para cada chave procurada (caso de teste) deve ser impressa a posi��o no vetor ou -1 (se n�o for encontrada)*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_seq_rec(int chave, int *v, int i, int n){
    if (i<n)
        return (v[i]==chave)? i : busca_seq_rec(chave, v, i+1, n);  // ? antes if : depois else
    else
        return -1;
}

int main() {
    int i, n, n_casos, teste;
    int *v;

    scanf("%d", &n);

    v=(int*)malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &n_casos);

    while(n_casos>0){
        scanf("%d", &teste);
        printf("%d\n", busca_seq_rec(teste,v,0, n));

        n_casos--;
    }

    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

