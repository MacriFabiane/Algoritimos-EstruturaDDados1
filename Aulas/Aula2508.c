//aula 25/08 ALOCA��O DIN�MICA
//MEM�RIA � dividida em duas est�tica(declaradas no inicio) e dinamica (dividida em pilha-acessa o q vem first-, Heap- restante do
//espaco que tem livre, alocado durante a execu��o do programa-)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//func�o malloc recebe um numero inteiro que da  o tamanho d aloca��o
//calloc esvasia a memoria que aloca;
int main ()
{	
	int n =15;
	int *v1 =malloc(sizeof(int)*n); //sizeof e tam da variavel n= quat de variaveis a serem armazenadas
	int *v2 = calloc(n, sizeof(int)); //x= quantidade y= tipo
	char *str = malloc(sizeof(char)*20);
	
	strcpy (str, "oi, eu sou o goku");
	
	printf ("Antes: %s\n", str);
	
	str =realloc (str, 25);
	strcat(str, "!"); //concatenar
	
	printf ("Depois: %s\n", str);
	
	free(v1);
	free(v2);//libera espa�o NUNCA ESQUECER, liberar o espa�o alocado depois de usado
	
//    *v1= 10;
	
//	printf ("%d\n", *v1);
	
	return 0;
}
