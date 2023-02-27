#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "filaE.h"


// Estrutura para representar c�lulas
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa c�lula para qualquer 
              // tipo de informa��o, recomendo o uso de ponteiro 
              // gen�rico. Exemplo: void* item;
    Cell *next;
};


// Estrutura para representar filas encadeadas
struct FilaE{
    Cell *inicio;
    Cell *fim;
};


// Cria uma nova c�lula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Fun��o para criar uma fila encadeada
FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


// Retorna 1 se a fila est� vazia ou 0, caso contr�rio
int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


// Enfileirar um item
void enfileirar(int key, FilaE* f){
    Cell *aux; // Nova c�lula

    // Caso a pilha encadeada seja nula,
    // alocar um espa�o para essa estrutura
    if (f == NULL)
        f = criar_filaE();

    // Criar nova c�lula
    aux = criar_celula(key);

    // Caso a fila ainda esteja vazia, o primeiro e
    // o �ltimo elemento s�o iguais
    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        // Caso a fila n�o esteja vazia, basta atualizar
        // o final da estrutura
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


// Desenfileirar um item da fila
int desenfileirar(FilaE* f){
    Cell *aux; // Primeiro elemento da fila
    int item = INT_MIN; // Valor que est� no in�cio da fila

    if (!filaE_vazia(f)){
    	// obter o primeiro elemento da fila
        aux = f->inicio;

        f->inicio = aux->next;

        // Acessar o conte�do da c�lula
        item = aux->item;

        // Liberar a c�lula desenfileirada
        free(aux);
    }

    return item;
}


// Imprimir o conte�do da fila
void imprimir_fila(FilaE* f){
    Cell *aux; // Para percorrer a fila, deve ser utilizada
    	       // uma vari�vel auxiliar para n�o perder o
    	       // topo da lista

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d\n", aux->item);
            aux = aux->next;
        }
    }
}


// Desalocar a fila
int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}
