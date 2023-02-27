#include <stdio.h>
#include <stdlib.h>
#include "pesquisa_indexada.h"

struct IF_Item {
	int chave; // valor da chave no elemento do arquivo de �ndice
	int pos_arq; // posi��o onde a busca � iniciada no arquivo (tabela)
};

struct Arq_Seq_In {
	int tam_arq; // tamanho do arquivo (tabela)
	int tam_index; // tamanho do �ndice
	int *arq; // arquivo (tabela)
	struct IF_Item *index; // arquivo de �ndice
};


Arq_Seq_In* criar_arq_seq_ind(int tam_index, int *arquivo, int n) {
	Arq_Seq_In* arqSI = (Arq_Seq_In*) malloc(sizeof(Arq_Seq_In));
	int i, tam_bloco;

	arqSI->tam_arq = n;
	arqSI->tam_index = tam_index;
	arqSI->arq = (int*) malloc(n * sizeof(int));
	arqSI->index = (IF_Item*) malloc(tam_index * sizeof(IF_Item));

	for (i = 0; i < n; i++)
		arqSI->arq[i] = arquivo[i];

	tam_bloco = n / tam_index;

	for (i = 0; i < tam_index; i++) {
		arqSI->index[i].pos_arq = i * tam_bloco;
		arqSI->index[i].chave = arquivo[arqSI->index[i].pos_arq];
	}

	return arqSI;
}


int buscar_item(int chave, Arq_Seq_In* arqSI) {
	int i, j, n;

	if (arqSI != NULL) {
		// Se a chave procurada for a menor que a primeira chava da tabela de �ndice,
		// ent�o ela n�o est� no arquivo
		if (chave < arqSI->index[0].chave)
			return -1;

		// busca no �ndice
		for (i = 0; (i < arqSI->tam_index) && (chave < arqSI->index[i].chave); i++);

		if (chave == arqSI->index[i].chave)
			return arqSI->index[i].pos_arq;

		// busca na tabela
		else {
			// Se a execu��o do c�digo chegou at� aqui, significa que arqSI->index[i].chave � a primeira
			// chave maior que a procurada
			// Pr�ximo passo: obter o limite do espa�o de busca
			// Caso a busca n�o seja a partir da posi��o do �ltimo elemento da tabela de �ndice, a busca
			// pela chave na tabela ser� entre arqSI->index[i - 1].pos_arq + 1 e
			// arqSI->index[i].pos_arq
			if (i < arqSI->tam_index)
				// Obter o limite do espa�o de busca na tabela
				n = arqSI->index[i].pos_arq;
			// Caso i for maior ao tamanho da tabela de �ndice, significa que a busca ser� no �ltimo
			// "bloco" coberto pela tabela de �ndice, ou seja, entre arqSI->index[i - 1].pos_arq + 1
			// e arqSI->tam_arq
			else
				n = arqSI->tam_arq;

			// Como um dos crit�rios de parada do primeiro for � quando a chave da tabela de �ndices for
			// maior a chave procurada, ent�o, busca � feita a partir da posi��o indicada pelo
			// (i - 1)-�simo elemento da tabela auxilar, j� que a sua chave � a �ltima a ser menor que a
			// procurada
			for (j = arqSI->index[i - 1].pos_arq + 1; j < n; j++)
				if (chave == arqSI->arq[j])
					return j;
		}
	}

	return -1;
}
