/*Inplemente uma fun��o recursiva que verifique se uma string � pal�ndromo.

Input Format

Na primeira linha, deve ser lida uma string.

Constraints

Se a fun��o n�o for recursiva, ser� atribu�da nota 0 (zero).

Output Format

Imprimir "palindromo" se a string de entrada for pal�ndromo, ou imprimir "n�o palindromo", caso contr�rio.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int palindromo(char *str, int ini, int fim){
    if (ini>=fim)
        return 1; //palindromo
    else if (str[ini]!=str[fim])
        return 0;
    else
        return palindromo(str, ini+1, fim-1);

}

int main() {
    char str[100];
    scanf("%s", str);
    if (palindromo(str,0, strlen(str)-1))
        printf("palindromo");
    else
        printf ("nao palindromo");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
