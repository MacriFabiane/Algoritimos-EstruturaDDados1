// aloca��o por encadeamento --lista encadeada -- lista estatica
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "lista.h"
//dois types listas lineares e n�o lineares(generalizadas)
//vamos aprender as lineares
//tipo especiais de lista-- fila, pilha;

//lista estatica - cole��o de elementos armazenados de forma cont�nua na memoria, pode ser percorrida linearmente em qualquer
//dire��o
//economia de memory e siple implementa��o
//custo para retirar itens, se atingir o lim de armazenamento n � poss�vel realocar mem�ria

int main (){
	Lista*l= criar_lista();

	inserir (l, 1);
	inserir (l, 2);
	inserir (l, 3);
	inserir (l, 4);
	inserir (l, 5);
	inserir (l, 6);
	inserir (l, 7);
	inserir (l, 8);

	imprimir_lista(l);

	remover (l,8);
	remover (l, 5);

	imprimir_lista(l);

	//remover (l, 1);

	//imprimir_lista(l);

	//remover (l, 5);



	return 0;
}
