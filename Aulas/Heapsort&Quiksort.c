#include <stdio.h>
#include <stdlib.h>
//complexidade n*log n
/*	   	n  -> n  movimenta��es
   n/2        n/2   ->n mov
n/4 n/4    n/4 n/4   ->n mov*/
//mais eficiente no melhor caso(conjunto j� ordenado) do que o heapsort(que vair ter o trabalho de reordenar again)
void quicksort(int x[], int esq, int dir){
	int i = esq, j = dir, pivo = x[(i + j) / 2], aux;

	do{
		while (x[i] < pivo)
			i++;

		while (x[j] > pivo)
			j--;

		if (i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i++;
			j--;
		}
	}while (i <= j);

	if (j > esq)
		quicksort(x, esq, j);
	if (i < dir)
		quicksort(x, i, dir);
}
// heap pode ser representada por uma arvore binaria, cada n� seguinte deve ser menor que a anterior
// em todos os cen�rios O(n*log n)
// Implementa��es relacionadas ao heapsort
//*******************************************
static void gerarHeap(int v[], int n){
	int esq = n / 2;

	// Para o vetor ser rearranjado como heap, o processo come�a
	// pelos "n�s folhas" e a troca pode ocorrer at� o "n� raiz" 
	while (esq >= 0){
		refazer(v, esq, n - 1);
		esq--;
	}
}


static void refazer(int v[], int esq, int dir){
	int j = (esq + 1) * 2 - 1; // posi��o de um n� descendente (esquerda) 
				    // do n� localizado na posi��o esq
	int x = v[esq]; // representa o n� raiz, ou seja, o elemento a partir
			// do qual ser� testada a condi��o de heap

	// Pa partir do n� na posi��o esq, o arranjo � percorrido at� o 
	// "n� folha"
	while (j <= dir){
		// � verificado se o "n� filho" esquerdo � menor que o direito
		if ((j < dir) && (v[j] < v[j + 1]))
			j++;

		// Se o x for maior que o seu descendente, a condi��o de heap
		// n�o foi violada
		if (x > v[j])
			break;

		// Quando a condi��o de heap � violada, devem haver trocas
		// de posi��es entre os elementos
		v[esq] = v[j];
		esq = j; // posi��o de um dos descendentes do elemento localizado
		         // em esq
		j = (esq + 1) * 2 - 1; // descendente "esquerdo" de v[esq]
	}

	v[esq] = x;
}


void heapsort(int v[], int n){
	int x;
	int dir = n - 1;

	gerarHeap(v, n); // primeiro passo, gera��o da heap

	// Em cada passo dessa repeti��o, a raiz da heap �
	// reposicionada em sua posi��o correta e a heap
	// � refeita. Isso � feito at� que a heap esteja
	// "vazia".
	while (dir > 0){
		x = v[0];
		v[0] = v[dir];
		v[dir] = x;
		dir--;

		refazer(v, 0, dir);
	}
}
//*******************************************


int main(){

    return 0;
}
