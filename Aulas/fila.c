#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fila.h"

struct Fila{
	int item[TAM_MAX];
	int ini; // posi��o do primeiro item
	int fim; // posi��o do �ltimo item
	int tam; // tamanho da fila
};

// Criar uma fila vazia
Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = f->fim = -1; 
    f->tam = 0;

    return f;
}

// Verificar se a fila est� cheia
int fila_cheia(Fila *f){

    if (f == NULL)
        return -1; // A fila � nula
    else if (f->tam < TAM_MAX)
        return 0; // A fila n�o est� cheia, pois o seu tamanho n atingiu a capacidade m�xima
    else
        return 1; // fila cheia
}

// Verificar se a fila est� vazia
int fila_vazia(Fila *f){
    if (f == NULL)
        return -1; // A fila � nula
    else if (f->tam > 0)
        return 0; // A fila n�o est� vazia, pois o seu tamanho � maior que zero
    else
        return 1; // fila vazia
}

// Colocar um item na fila
int enfileirar(Fila *f, int chave){
    // Se a fila for vazia, um espa�o � alocado para ela
    if (f == NULL)
        f = criar_fila();

    // Se a fila n�o estiver cheia, enfileirar um item
    // ! => opera��o l�gica de nega��o
    // Exemplos:
    // !0 = 1
    // !(n�mero diferente de 0) = 0
    // Caso a fila seja nula, antes de entrar no comando if, ela � criada
    // ou seja, n�o precisa fazer "if (pilha_cheia(p) == 0)"
    if (!fila_cheia(f)){
    	if (f->ini ==-1)
    	   f->ini= f->fim=0

        // Ao enfileirar um item, a posi��o do �ltimo elemento da fila
        // deve se atualizada. Antes da atualiza��o, se a posi��o fim
        // for menor que a capacidade m�xima da lista menos 1, basta
        // apenas incrementar o campo fim. Caso contr�rio, f->fim = 0;
        else if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        // Ap�s a atualiza��o da posi��o final da fila, basta atribuir o
        // novo item na �ltima posi��o da fila
        f->item[f->fim] = chave;

        // Atualizar o tamanho da fila, que aumentou
        f->tam++;

        return 1; // Opera��o bem sucedida
    }

    return 0; // A fila estava cheia
}

// remover um item da fila
int desenfileirar(Fila *f){
    int item = INT_MIN;

    // Verificar se a fila � vazia (1) ou nula (-1)
    // A �nica condi��o para "entrar" no comando if � a fun��o abaixo
    // retornar 0, cuja nega��o � 1
    // Para qualquer retorno diferente de 0, a nega��o ser� 0
    if (!fila_vazia(f)){
        item = f->item[f->ini];
        
        f->tam--; // a fila reduz o seu tamanho
	
	// Se a fila ficar vazia ap�s a opera��o de desenfileirar, ini e 
	// fim passar a ser -1. Caso a fila n�o ficar vazia, o campo ini 
	// deve ser ser atualizado. Se a posi��o ini for menor que a 
	// capacidade m�xima da lista menos 1, basta apenas incrementar o 
	// campo ini. Caso contr�rio, f->ini = 0;
	if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
    }

    return item;
}

// Imprimir conte�do da fila
void imprimir_fila(Fila *f){
    // Uma c�pia da fila deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela opera��o desempilhar, ou seja,
    // se usarmos a fila original (f), perder�amos os seus dados
    Fila aux;
    int item;
    
    if(f!=NULL){
    	Fila aux = *f;
	}

    // Como a vari�vel aux n�o � ponteiro, para utilizamos o seu
    // endere�o como par�metro para chamarmos a fun��o fila_vazia
    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

// liberar fila
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}
