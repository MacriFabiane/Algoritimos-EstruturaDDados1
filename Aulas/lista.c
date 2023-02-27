#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


// Estrutura para uma lista est�tica
struct Lista{
    int item[MAX_SIZE]; // A lista pode ser de qualquer tipo. Nesse caso, � uma lista de int, mas tamb�m pode ser de float, char, string, etc.
    int tam; // tamanho da lista
};

// Fun��o para criar uma lista est�tica
Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;// Ao iniciar a lista, a mesma estar� "vazia"

    return l;
}

// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int lista_vazia(Lista *l){

    if (l==NULL)
     return -1;
    else if(l->tam >0)
      return 0;
    else
	  return 1;
}

// Retorna 1 se a lista est� cheia ou 0, caso contr�rio
int lista_cheia(Lista *l){
    if (l==NULL)
     return -1;
    else if(l->tam < MAX_SIZE)
      return 0;
    else
	  return 1;
}

// Procura a posi��o de um item com a chave e retorna a sua respectiva posi��o
// Caso o item n�o seja encontrado, � retornado -1
int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        // Procurar na parte "n�o vazia" da lista
        for (i = 0; i <= l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;// Se chegou aqui � porque a lista est� vazia ou o item n�o foi encontrado
}

int inserir(Lista *l, int chave){
	if (l==NULL)
	  l=criar_lista();

    if (!lista_cheia(l)){//  se n O item � adicionado no final da lista

        l->item[l->tam] = chave;

        l->tam++; // Se foi adicionado um elemento, ent�o a lista cresceu

        return 1;// A inser��o foi bem-sucedida
    }

    return 0;// Se chegou aqui � porque a lista estava cheia (ou nula)
}

// O item procurado e removido da lista caso ela. Para isso, a lista n�o deve estar vazia e o item
// deve existir.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int remover(Lista *l, int chave){
    int i, p;

   // if (l!=NULL){
    	p = buscar(l, chave);

    	if (p>=0){
    		for (i=p; i< l->tam - 1; i++)// Deslocamento de itens da lista para ocupar o espa�o do item removido
    		   l->item[i]= l->item[i+1];

               l->tam--;

    		   return 1; //sucesso
    		}
		//}
    return 0;
}

void imprimir_lista(Lista *l){// Imprime o conte�do da lista
    int i;

    if (l!=NULL){
    	for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
	}
}

int liberar_lista(Lista *l){ // Libera a lista
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}

Lista* concatenar (Lista *l1, Lista *l2)
{
	Lista*l3 =NULL;
	int i;

	if(l1==NULL)
		l3=l2;

	else if (l2==NULL)
	 	l3=l1;

	else{
		l3= criar_lista();

		for(i=0; i< l1->tam; i++)
			inserir (l3, l1->item[i]);

	    for(i=0; i< l2->tam; i++)
			inserir (l3, l2->item[i]);

		return l3;
	}
}

int inserir_ordenado(Lista *l, int chave){
	int i;

	if (l==NULL)
	  l=criar_lista();

    if (!lista_cheia(l)){

    	l->tam++;


    	for (i=l->tam-1; (i> 0)&& (chave<l->item[i-1]); i--)
    		l->item[i]=l->item[i-1];

        l->item[i]=chave;

        return 1;
}
return 0;// Se chegou aqui � porque a lista estava cheia (ou nula)
}
