/*Implemente a vers�o iterativa da busca bin�ria.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor. Na terceira linha deve ser lido o n�mero de casos de teste (quantidade de chaves que dever�o ser procuradas). A partir da pr�xima linha, as chaves que ser�o procuradas devem ser lidas.

Constraints

.

Output Format

Para cada chave procurada (caso de teste) deve ser impressa a posi��o no vetor ou -1 (se n�o for encontrada)*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_binaria_int(int chave, int v[], int n){
    int ini =0, fim= n-1, m;

    while (ini<=fim){
        m=(ini+fim)/2;

        if(v[m]==chave)
            return m;
        else if (chave<v[m])
            fim= m-1;
        else
            ini =m+1;
    }
    return -1;
}
int main() {
    int n, i, item, ct;
    int *v;

    scanf("%d", &n);
    v= malloc(sizeof(int)*n);

    for (i=0; i<n; i++){
        scanf("%d", &item);

        v[i]=item;
    }

    scanf("%d", &ct);

    while(ct>0){
        scanf("%d", &item);

        printf("%d\n", busca_binaria_int(item, v, n));

        ct--;
    }
    free(v);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

