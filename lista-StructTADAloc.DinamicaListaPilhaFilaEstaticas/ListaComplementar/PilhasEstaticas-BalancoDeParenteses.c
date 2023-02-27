/*Dada uma express�o qualquer com par�nteses, indique se a quantidade de par�nteses est� correta ou n�o, sem levar em conta o restante da express�o. Por exemplo:

a+(b*c)-2-a est� correto (a+b*(2-c)-2+a)*2 est� correto

enquanto

(a*b-(2+c) est� incorreto 2*(3-a)) est� incorreto )3+b*(2-c)( est� incorreto

Ou seja, todo par�nteses que fecha deve ter um outro par�nteses que abre correspondente e n�o pode haver par�nteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

Para a solu��o desse exerc�cio, utilize uma pilha est�tica de caracteres.

Input Format

Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir � uma express�es (1 <= N <= 10000), cada uma delas com at� 1000 caracteres.

Constraints

As pilhas devem ser manipuladas apenas por fun��es. Por exemplo, o acesso a elementos deve ser feito apenas atrav�s da fun��o desempilhar.

Output Format

O arquivo de sa�da dever� ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>
#define TAM_MAX 100

typedef struct PilhaC PilhaC;

struct PilhaC{
    char item[TAM_MAX];
    int topo;
};


PilhaC* criar_pilha(){
    PilhaC *p = (PilhaC*) malloc(sizeof(PilhaC));

    p->topo = -1;

    return p;
}


int pilha_cheia(PilhaC *p){

    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(PilhaC *p){

    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}


int empilhar(PilhaC *p, char item){

    if (p == NULL)
        p = criar_pilha();


    if (!pilha_cheia(p)){
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}
char desempilhar (PilhaC *p){
    char item= ' ';

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(PilhaC *p){

    PilhaC aux = *p;
    char item;


    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

// Liberar a pilha
void liberar_pilha(PilhaC *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(PilhaC *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}
int parenteses (char str[]){
    PilhaC *p =criar_pilha();
    int i, res =1;

    for (i =0; (i< strlen(str))&& res; i++){
        if (str[i]== '(')
            empilhar(p, str[i]);
        else if (str[i]== ')'){
            if (!pilha_vazia(p))
                desempilhar (p);
            else
                res =0;
        }
    }

    if ((res == 1)&& !pilha_vazia(p))
        res=0;

    liberar_pilha(p);
    return res;
}

int main() {
    int n, i, res;
    char *str;

    scanf("%d", &n);
    for (i=0; i<n; i++){
        str= (char *)malloc(sizeof(char)*1000);

        scanf ("%s", str);

        res=parenteses(str);

        if (res==1)
            printf ("correct\n");
        else
            printf ("incorrect\n");

        free(str);
    }
    return 0;
}
