//aula dia 02/09 Pilhas(estrutura que mais se utilisa em nosso dia a dia )
//aloca��o encadeada
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include "pilha.h"
//remo��o s� no topo, desempilhar
//pilhas est�ticas (h� um  cursor para apontas o topo)(variavel topo � iniciada no -1)
//Stack overflow - estorar pilha;
int main(){
	Pilha *p= criar_pilha();
	
	empilhar (p, 1);
	empilhar (p, 2);
	empilhar (p, 3);
	empilhar (p, 4);
	empilhar (p, 5);
	
	imprimir_pilha(p);
	
	desempilhar (p);
	
	imprimir_pilha(p);
	
	desempilhar (p);
	
	
	return 0;
}

