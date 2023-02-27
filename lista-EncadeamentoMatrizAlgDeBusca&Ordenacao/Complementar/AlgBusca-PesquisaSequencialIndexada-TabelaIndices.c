/*Implemente uma fun��o que receba um vetor, o tamanho do vetor e um n�mero inteiro M. A fun��o dever� gerar uma tabela de �ndices de tamanho M.

Input Format

Na primeira linha dever� ser lido o tamanho da tabela de �ndice.

Na segunda linha dever� ser lido o tamanho do vetor.

Nas linhas seguintes dever�o ser lidos os elementos do vetor.

Constraints

.

Output Format

Imprimir cada elemento da tabela de �ndices, que � composto por uma posi��o no vetor e o elemento localizado nessa posi��o.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct IF_Item IF_Item;

typedef struct Arq_Seq_In Arq_Seq_In;

struct IF_Item{
    int chave;
    int pos_arq;
};

struct Arq_Seq_In{
    int tam_arq;
    int tam_index;
    int *arq;
    struct IF_Item *index;
};


Arq_Seq_In* criar_arq_seq_ind(int tam_index, int *arquivo, int n){
    Arq_Seq_In* arqSI = (Arq_Seq_In*) malloc(sizeof(Arq_Seq_In));
    int i, tam_bloco;

    arqSI->tam_arq = n;
    arqSI->tam_index = tam_index;
    arqSI->arq = (int*) malloc(n * sizeof(int));
    arqSI->index = (IF_Item*) malloc(tam_index * sizeof(IF_Item));

    for (i = 0; i < n; i++)
        arqSI->arq[i] = arquivo[i];

    tam_bloco = n / tam_index;

    for (i = 0; i < tam_index; i++){
        arqSI->index[i].pos_arq = i * tam_bloco;
        arqSI->index[i].chave = arquivo[arqSI->index[i].pos_arq];
    }

    return arqSI;
}


void imprimir_tab_indices(Arq_Seq_In* arqSI){
    int i;

    if (arqSI != NULL){
        for (i = 0; i < arqSI->tam_index; i++)
            printf("%d: %d\n", arqSI->index[i].pos_arq, arqSI->index[i].chave);
    }
}


int main() {
    int n, ti, i, item;
    int *v;
    Arq_Seq_In *a;

    scanf("%d", &ti);
    scanf("%d", &n);

    v=malloc(sizeof(int)*n);

    for (i=0; i<n; i++){
        scanf("%d", &item);

        v[i]= item;
    }

    a=criar_arq_seq_ind(ti,v, n);

    imprimir_tab_indices(a);

    free(v);
    free(a);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
