/*Implemente uma fun��o que inverta uma string atrav�s de uma pilha encadeada de caracteres.

Input Format

Na primeira linha deve ser lida uma string.

Constraints

As pilhas devem ser manipuladas apenas por fun��es. Por exemplo, o acesso a elementos deve ser feito apenas atrav�s da fun��o desempilhar ou que retorne o valor que est� no topo.

Output Format

Imprimir a string invertida.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

typedef struct Cell Cell;
typedef struct PilhaE PilhaE;

struct Cell{
    char item;
    Cell *next;
};



struct PilhaE{
    Cell *topo;
};



Cell* criar_celula(char key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}



PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}



void empilhar(char key, PilhaE *p){
    Cell *aux;


    if (p == NULL)
        p = criar_pilhaE();


    aux = criar_celula(key);

    aux->next = p->topo;

    // Atualizar topo da pilha
    p->topo = aux;
}



char desempilhar(PilhaE *p){
    Cell *aux;
    char item = ' ';

    if (!pilhaE_vazia(p)){

        aux = p->topo;


        item = aux->item;


        p->topo = aux->next;


        free(aux);
    }

    return item;
}

int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

void inverter (char *str){
    int i;
    PilhaE *p;

    if (str!=NULL){
        p = criar_pilhaE();

        for (i=0; i<strlen(str); i++)//strlen tam da string
            empilhar (str[i], p);

        i=0;

        while (!pilhaE_vazia(p)){
            str[i]=desempilhar(p);
            i++;
        }
        liberar_pilha(p);
    }
}

int main() {
    char str[100];

    scanf("%s", str);

    inverter(str);

    printf("%s", str);

    return 0;
}

