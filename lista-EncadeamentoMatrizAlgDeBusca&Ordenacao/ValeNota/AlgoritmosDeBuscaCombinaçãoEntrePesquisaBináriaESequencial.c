/*Implemente a fun��o que receba quatro par�metros: n�mero inteiro a ser procurado, vetor de inteiros (v[] ou *v), tamanho do vetor (n) e um n�mero inteiro representando tamanho m�nimo (m). Nessa fun��o, enquanto o espa�o de busca (espa�o coberto entre os �ndices esquerdo e direito em uma busca bin�ria, ou seja, direito - esquerdo + 1) for maior que m, o m�todo de busca bin�ria deve ser aplicada. Quando o espa�o de busca ficar menor ou igual a m, a busca sequencial dever� ser executada. Se a busca sequencial for aplicada, o espa�o de busca dever� ser impresso (caso houver). Ao final a posi��o do item procurado no vetor � retornada. Caso o item n�o seja encontrado, a fun��o dever� retornar -1.

Input Format

Na primeira linha deve ser lido um n�mero inteiro que dever� ser procurado. Na segunda linha deve ser lido o tamanho do vetor. Na terceira devem ser lidos os elementos do vetor. Na quarta linha deve ser lida o tamanho m�nimo da parti��o (m) para fazer a busca bin�ria.

Constraints
.

Output Format

Na primeira linha deve ser impresso o subvetor referente ao espa�o de busca a partir do momento em que a busca sequencial � executada. Na pr�xima linha deve ser impressa a posi��o retornada pela fun��o.

Caso a busca sequencial n�o tenha sido executada, apenas a posi��o retornada pela fun��o deve ser impressa.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_bin_seq(int x, int v[], int n, int m){
    int ini = 0;
    int fim = n - 1;
    int meio, i;

    if((fim-ini+1)>m){
        while (fim-ini+1>m){
            meio = (ini + fim) / 2;

            if (x == v[meio])
                return meio;
            else if (x < v[meio])
                fim = meio - 1;
            else
                ini = meio + 1;
        }
    }

    if((fim-ini+1)<=m) {

            for (i=ini; i<=fim; i++){
                printf("%d ", v[i]);
            }

            printf("\n");


        for (i=ini; i <=fim ; i++){
            if (x == v[i]){

                return i;
            }
        }
    }


    return -1;

}


int main() {
    int m, n, i,x, result;
    int *v;

    scanf("%d", &x);

    scanf("%d", &n);

    v=(int*)malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    result = busca_bin_seq(x, v, n, m);

    printf("%d", result);




    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

