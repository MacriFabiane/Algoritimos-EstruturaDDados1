#include <stdio.h>
//como listas encadeadas simples/duplamente s�o lineares esse m�todo n�o se aplica a elas, j� que n � linear
// Busca bin�ria, onde x � a chave procurada, v � o vetor (tabela),
// ini � a posi��o inicial do espa�o de busca e fim, a posi��o final.
// Em outras palavras 
static int busca_bin(int x, int v[], int ini, int fim){
	int meio;

	// Caso base, quando ini � igual a fim
	if ((ini == fim) && (x == v[ini]))
		return ini;
	// Em seguida � verificada se ini � menor que fim
	else if (ini < fim){
		// A primeira compara��o � sempre no meio do vetor,
		// ou sub-vetor (nas posi��es entre ini e fim)
		meio = (ini + fim) / 2;

		// E o elemento procurado for o do meio, retorna a posi��o
		if (x == v[meio])
			return meio;
		// Se a chave procurada for menor que a do meio vetor, a
		// busca � continuada na metade inferior
		else if (x < v[meio])
			return busca_bin(x, v, ini, meio - 1);
		// Caso contr�rio, a busca � continuada na metade superior
		else
			return busca_bin(x, v, meio + 1, fim);
	}else
		return -1;
}


int busca_binaria(int x, int v, int n){
	return busca_bin(x, v, 0, n - 1);
}


// A l�gica para busca por interpola��o � a mesma da bin�ria.
// A �nica diveren�a � a forma em que o "meio" � calculado.
static int busca_in(int x, int v[], int ini, int fim){
	int meio;
	
	if ((ini == fim) && (x == v[ini]))
		return ini;
	else if (ini < fim){
		meio = ini + (fim - ini) * (x - v[ini]) / (v[fim] - v[ini]);
		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			return busca_interpolacao(x, v, ini, meio - 1);
		else
			return busca_interpolacao(x, v, meio + 1, fim);
	}else
		return -1;
}


int busca_interpolacao(int x, int v, int n){
	return busca_in(x, v, 0, n - 1);
}


int main(){

    return 0;
}
