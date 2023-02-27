/*Luciano Capit�o Am�rica tem um quadro no seu programa "Geladeira do Capit�o Am�rica" onde � passada uma sequ�ncia de caracteres (string) que representa um alfabeto e uma sequ�ncia de n�meros inteiros, sendo cada n�mero a posi��o de um determinado caractere. O participante deve decifrar a mensagem utilizando o alfabeto e a sequ�ncia de n�meros inteiros.

Exemplo de alfabeto: oabeucis,-gfk Mensagem codificada: 1 7 9 10 4 5 10 8 1 5 10 1 10 11 1 13 5 Mensagem decodificada: oi,-eu-sou-o-goku

Para ajudar os participantes desse quadro no programa, implemente uma fun��o que receba uma string (alfabeto) e um vetor de n�meros inteiros (mensagem codificada) alocado dinamicamente. A fun��o dever� retornar uma string resultante da decodifica��o da mensagem utilizando o alfabeto.

Input Format

Na primeira linha deve ser lida uma string Na segunda linha, enquanto -1 n�o for lido, deve ser lido um n�mero inteiro.

Constraints
.

Output Format

Deve ser impressa a mensagem decodificada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char* decodificar (char *string, int *v, int n){
    int i,k ;
    char *code;

    code=(char*)malloc(sizeof(char)*n);


    for (i=0; i<n; i++){
        k=v[i];
        code[i]=string[k];

    }


    return code;
}
int main() {
    char string[50], *code;
    int *v;
    int i, n;

    scanf ("%s", string);

    v= (int*)malloc (sizeof(int)*1);

    do{
    	v= (int*)realloc(v, (n+1)*sizeof(int));
        scanf ("%d", &v[n]);

		if (v[n]!=-1)
            n++;
        else
           break;

    }while (v[n]!=-1);

    code=(char*)malloc(sizeof(char)*n);

    code=decodificar(string, v, n);

    printf ("%s",code);



    return 0;
}

