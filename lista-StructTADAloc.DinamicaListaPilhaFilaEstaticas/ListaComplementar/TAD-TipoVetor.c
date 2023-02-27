/*Crie um TAD para processamento de vetores com a seguinte estrutura e opera��es, onde item � o vetor e n � a capacidade do vetor e q a quantidade de elementos contidos no vetor:

typedef struct{
    int *item; // Array (vetor) de tamanho n
    int q; // quantidade de itens inseridos em v
    int n; // tamanho (capacidade) de v
}Vetor;

Vetor * iniciar(int n);

int inserir(Vetor *v, int x); // retorna 1 se a opera��o foi bem-sucedida

// Intercala��o entre dois vetores

Exemplo:
v1 = {1, 2, 3, 4}
v2 ={5, 6, 7, 8, 9}
Intercala��o = {1, 5, 2, 6, 3, 7, 4, 8, 9}

Vetor * intercalar(Vetor *v1, Vetor *v2);

// Concatena��o entre dois vetores

Exemplo:
v1 = {1, 2, 3, 4}
v2 ={5, 6, 7, 8, 9}
Concatena��o = {1, 2, 3, 4, 5, 6, 7, 8, 9}

Vetor * concatenar(Vetor *v1, Vetor *v2);

// Obter subvetor

ini: posi��o inicial
fim: posi��o final

Exemplo
v1 = {1, 2, 3, 4, 5, 6}
ini = 1, fim = 3
subvetor = {2, 3, 4}

Vetor * subvetor(Vetor *v1, int ini, int fim);
Observa��o: n�o � necess�rio considerar o arquivo .h, j� que no HackerRank n�o tem como "upar" arquivos .h e .c.

Input Format

Deve ser lido um valor inteiro n que representa a quantidade de elementos de um v. Em seguida, devem ser lidos os n elementos do vetor. Repetir o processo para o segundo vetor. Por fim, na �ltima linha devem ser lidas as posi��es ini e fim para a gera��o de um subvetor a partir do primeiro vetor que foi lido.

Constraints
.

Output Format

Vetores na seguinte ordem: resultantes da intercala��o, resultantes da concatena��o e subvetor.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    int *item; // Array (vetor) de tamanho n
    int q; // quantidade de itens inseridos em v
    int n; // tamanho (capacidade) de v
}Vetor;

Vetor * iniciar(int n){
    Vetor *v= (Vetor*)malloc (sizeof(Vetor));

    v->n=n;
    v->q =0;

    v-> item =(int*)malloc(sizeof(int)*n);

    return v;
}

int inserir(Vetor *v, int x){
    if ((v!=NULL) && (v->q < v->n)){ //precisa de espaco para inserir no final
        v->item[v->q]= x;
        v->q++;

        return 1;
    }
   return 0;

}

Vetor * intercalar(Vetor *v1, Vetor *v2){
    int i;
    Vetor *v3= NULL;

    if (v1==NULL)
        return v2;
    else if (v2==NULL)
        return v1;
    else{
        v3 = iniciar (v1->q+v2->q);

        for(i=0; (i< v1->q)&&(i< v2->q); i++){
            inserir(v3, v1->item[i]);
            inserir(v3, v2->item[i]);
        }

        for (i=v2->q; i<v1->q; i++)
            inserir(v3, v1->item[i]);

        for (i=v1->q; i<v2->q; i++)
            inserir(v3, v2->item[i]);

        return v3;
    }

}

Vetor * concatenar(Vetor *v1, Vetor *v2){
     int i;
    Vetor *v3= NULL;

    if (v1==NULL)
        return v2;
    else if (v2==NULL)
        return v1;
    else{
        v3 = iniciar(v1->q+ v2->q);

        for(i=0; i< v1->q; i++)
            inserir(v3, v1->item[i]);

        for(i=0; i< v2->q; i++)
            inserir(v3, v2->item[i]);

        return v3;
    }

}

Vetor * subvetor(Vetor *v1, int ini, int fim){
    int i;
    Vetor *v3 = NULL;

    if((v1!=NULL)&&(ini >= 0)&&(fim<v1->q)&& (ini<=fim)){
        v3 = iniciar(fim-ini+1);

        for (i=ini; i<=fim; i++)
            inserir(v3, v1->item[i]);

    }

    return v3;

}

void imprimir(Vetor *v){
    int i;

    if (v!=NULL){
        for (i=0; i< v->q; i++)
            printf ("%d ", v->item[i]);

        printf ("\n");
    }
}

int main() {
    int n, i, item, ini, fim;
    Vetor *v1, *v2, *v3, *v4, *v5;

    scanf ("%d", &n);

    v1 = iniciar(n);

    for (i=0; i<n; i++){
        scanf ("%d", &item);
        inserir (v1, item);
    }

    scanf ("%d", &n);

    v2 = iniciar(n);

    for (i=0; i<n; i++){
        scanf ("%d", &item);
        inserir (v2, item);
    }

    scanf ("%d %d", &ini, &fim);

    v3 = intercalar (v1, v2);
    v4 = concatenar (v1, v2);
    v5 = subvetor (v1, ini, fim);

    imprimir (v3);
    imprimir (v4);
    imprimir (v5);

    free (v1);
    free (v2);
    free (v3);
    free (v4);
    free (v5);


    return 0;
}
