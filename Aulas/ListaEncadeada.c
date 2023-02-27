#include <stdio.h>
#include <stdlib.h>
#include "listaE.h"

// Estrutura para representar c�lulas
struct Cell{
    int item; // Pode ser uma struct, union, ou qualquer tipo de dados.
              // Para possibilitar o reuso dessa c�lula para qualquer
              // tipo de informa��o, recomendo o uso de ponteiro
              // gen�rico. Exemplo: void* item;
    Cell *next;
};


// Estrutura para representar listas encadeadas
struct ListaE{
    Cell *head; // Ponteiro para o primeiro elemento da lista
};


// Cria uma nova c�lula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Fun��o para criar uma lista encadeada
ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}


// Verifica se um item existe na lista
int procurar(int key, ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma vari�vel auxiliar para n�o perder a
    	       // cabe�a da lista

    if (!listaE_vazia(l)){
        aux = l->head;

	// Percorrer a lista encadeada: enquanto a chave n�o
	// for encotrada e o valor nulo (NULL) n�o for
	// alcan�ado, percorrer cada c�lula
        while (aux != NULL){
            if (aux->item == key)
            	return 1;

            aux = aux->next;
        }
    }

    return 0;
}


// Um item � inserido no in�cio da lista
void inserir_primeiro(int key, ListaE *l){
    Cell *aux= criar_celula(key); // Nova c�lula

    // Caso a lista encadeada seja nula,
    // alocar um espa�o para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Apontar a nova c�lula para a cabe�a da
    // lista
    aux->next = l->head;

    // Atualizar a cabe�a da lista
    l->head = aux;
}


// Um item � inserido no final da lista
void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo; // c�lula auxiliar e nova,
                      // respectivamente

    // Caso a lista encadeada seja nula,
    // alocar um espa�o para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Se a lista estiver vazia, n�o faz sentido
    // percorr�-la
    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

	// Percorrer a lista at� encontrar a �ltima
	// c�lula
        while(aux->next != NULL)
            aux = aux->next;

        // Criar nova c�lula
        novo = criar_celula(key);

	// O �ltimo elemento da lista aponta para a
	// nova c�lula
        aux->next = novo;
    }
}


/* O item procurado e removido da lista caso ela. Para isso,
 a lista n�o deve estar vazia e o item deve existir.
 A fun��o retorna 1 se a opera��o for bem sucedida ou 0,
 caso contr�rio*/
int remover(int key, ListaE *l){
    Cell *auxA, *auxR = NULL; // c�lulas auxiliares

    if (!listaE_vazia(l)){ // apontar o auxA para a cabe�a da lista

        // Verificar se o elemento est� na cabe�a da lista
        if(l->head->item == key){
            // Atualizar a cabe�a
            auxR=l->head;
            l->head = l->head->next;//l->head=auxR->next
        }else{
            // apontar auxP para auxA
            auxR = auxA=l->head;

            // Procurar a c�lula que deve ser removida
            while((auxR != NULL) && (auxR->item != key)){
                //if (auxP != NULL)
                    auxA = auxR; // Guardar o endere�o auxA

                auxR = auxR->next; // Atualizar auxA
            }
        }

        if (auxR != NULL){
            // Caso a chave seja encontrada, ou seja, auxA diferente de
            // nulo, fazer a c�lula predecessora (auxP) apontar o ponteiro
            // "next" para o pr�ximo elemento de auxA
            if (auxA != NULL)
            	auxA->next = auxR->next; // funciona mesmo se auxP for igual a auxA

            // Agora, a c�lula auxA pode ser removida com seguran�a
            free(auxA);

            return 1; // Opera��o bem-sucedida
        }

    }

    return 0;
}


// Imprimir o conte�do da lista
void imprimir(ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma vari�vel auxiliar para n�o perder a
    	       // cabe�a da lista


    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

// Liberar lista
// Retorna 1 se a opera��o for bem-sucedida ou 0, caso contr�rio
int liberar_LE(ListaE *l){
    Cell *aux = NULL; // Para percorrer a lista, deve ser utilizada
    	       // uma vari�vel auxiliar para n�o perder a
    	       // cabe�a da lista

    // Diferentemente de uma lista est�tica, que pode ser ter todos
    // seus elementos desalocados de uma vez, em uma lista encadeada,
    // primeiramente deve ser desolocada c�lula por c�lula
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


// Obter o tamanho de uma lista encadeada
int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

