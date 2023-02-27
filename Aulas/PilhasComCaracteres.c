// pilha caractere
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaC.h"

#define TAM_MAX 100

struct PilhaC{
    char item[TAM_MAX];
    int topo;
};

// Criar uma pilha vazia
PilhaC* criar_pilha(){
    PilhaC *p = (PilhaC*) malloc(sizeof(PilhaC));

    p->topo = -1;

    return p;
}

// Verificar se a pilha est� cheia (stack overflow)
int pilha_cheia(PilhaC *p){
    // Uma solu��o simples
    // Antes de verificar o topo da pilha, primeiro devemos verificar se
    // a pilha � nula
    //return (p != NULL) && p->topo == (TAM_MAX - 1);

    //outra alternativa para implementa��o dessa fun��o para retornar
    //-1: se a pilha for nula
    // 0: se a pilha n�o estiver cheia
    // 1: se a pilha estiver cheia
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

// Verificar se a pilha est� vazia (stack overflow)
int pilha_vazia(PilhaC *p){
    // Uma solu��o simples
    // Pilha nula ou com o topo igual a -1 � uma pilha vazia
    //return (p == NULL) || (p->topo == -1);

    //outra alternativa para implementa��o dessa fun��o para retornar
    //-1: se a pilha for nula
    // 0: se a pilha n�o estiver vazia
    // 1: se a pilha estiver vazia
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

// Inserir um novo item na pilha, caso houver espa�o
int empilhar(PilhaC *p, char item){
    // Se a pilha for nula, reservar um espa�o na mem�ria para ela
    if (p == NULL)
        p = criar_pilha();

    // Se a pilha n�o estiver cheia, empilhar um item
    // ! => opera��o l�gica de nega��o
    // Exemplos:
    // !0 = 1
    // !(n�mero diferente de 0) = 0
    // Caso a pilha seja nula, antes de entrar no comando if, ela � criada
    // ou seja, n�o precisa fazer "if (pilha_cheia(p) == 0)"
    if (!pilha_cheia(p)){
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item; // um novo item � empilhado

        return 1; // opera��o bem sucedida
    }

    return 0; // opera��o mal sucedida
}

// Remover item do topo da pilha, caso essa estrutura n�o estiver vazia
char desempilhar (PilhaC *p){
    char item= ' '; // p caso esteja vasia

    // Verificar se a pilha � vazia (1) ou nula (-1)
    // A �nica condi��o para "entrar" no comando if � a fun��o abaixo
    // retornar 0, cuja nega��o � 1
    // Para qualquer retorno diferente de 0, a nega��o ser� 0
    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

// Imprimir conte�do da pilha
void imprimir_pilha(PilhaC *p){
    // Uma c�pia da pilha deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela opera��o desempilhar, ou seja,
    // se usarmos a pilha original (p), perder�amos os seus dados
    PilhaC aux = *p;
    char item;

    // Como a vari�vel aux n�o � ponteiro, para utilizamos o seu
    // endere�o como par�metro para chamarmos a fun��o pilha_vazia
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


// Obter a posi��o da pilha em que est� o topo
int obter_posicao_topo(PilhaC *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}
int consistente (char str[]){ //verificar se a cada abre parenteses tem um fecha parenteses
	int i,aux;
	PilhaC p= criar_plha();
	
	for(i=0; i< strlen(str); i++)
	   if (str[i]=='(')
	     empilhar(p, '(');
	     
	   else if (str[i]==')'){
	   	
	   	  if (!pilha_vazia(p))
	   	    desempilhar(p);
	   	    
	   	  else { //cai aqui se tem o fecha parenteses a mais
	   	  	liberar_pilha(p);
	   	  	
	   	  	return 0;
			}
	   }
	
	aux = pilha_vazia(p);
	
	liberar_pilha(p);
	
	return aux;
}

