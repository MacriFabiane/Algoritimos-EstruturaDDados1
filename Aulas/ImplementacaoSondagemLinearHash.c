#include <stdio.h>
#include <stdlib.h>
#include "hashT.h"

/**
Valores poss�veis para cada bucket da tabela hash
-1: bucket vazio
0: bucket vazio, mas j� houve uma chave, a qual foi removida
> 0: h� uma chave no bucket
*/

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}


// Fun��o hash, onde k � a chave e B � o tamanho da tabela
static int hashingF(int k, int B){
    return k % B;
}


// Implementa��o de uma fun��o rehash por overflow progressinvo
// hashC: resultado de uma fun��o hash
// tentativa: � o n�mero da tentativa para localizar ou posicionar uma chave
static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}

//Antes
/*int buscar(int key, HashT *t){
    int x = hashingF(key, t->tam);

    if (t->buckets[x] == key)
        return x;

    return -1;
}*/


//Depois
int buscar(int key, HashT *t){
    int x = hashingF(key, t->tam); // Posi��o ou c�digo hash (primeira tentativa) para chave key
    int i, rh;

    if (t->buckets[x] == key) // se chave foi encontrada na primeira tentativa, retornar a posi��o definida pela fun��o hash
        return x;
    else if (t->buckets[x] >= 0){ // Se a chave localizada na tabela hash for diferente da procurada, verificar se o bucket da posi��o x n�o est� vazia (ou seja, n�o tenha o valor -1)
        i = 1; // tentativa
        rh = x; // rehash

        /* Loop para continuar a busca da chave atrav�s de rehash
        Crit�rios de parada:
        1: as tentativas foram esgotadas (i == t->tam)
        2: a chave foi encontrada (t->buckets[rh] == key)
        3: uma posi��o vazia � encontrada (t->buckets[rh] == -1)
        */
        while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] >= 0)){
            rh = overflow_prog(x, t->tam, i); // aplicar a fun��o rehash

            i++; // atualizar a tentativa
        }

        // Verificar se a chave foi encontrada, ou seja, n�o foram esgotadas as tentativas
        // e o bucket na posi��o rh n�o  vazio (chave maior que -1)
        if ((i < t->tam) && (t->buckets[rh] == key))
            return rh;
    }else
        return -1;
}

//Antes
/*int inserir(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] < 0){
            t->buckets[x] = key;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int inserir(int key, HashT *t){
    int x;
    int i, rh;

    // verificar se a tabela n�o � nula e se a chave a ser inserida � v�lida
    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam); // Aplica��o de fun��o hash na chave key

        // Caso o bucket na posi��o x seja vazio (valor negativo) ou represente uma
        // remo��o (igual a zero), basta incluir a chave key
        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{ // Se a posi��o x n�o for vazia, tentar encontrar um bucket vazio
            i = 1; // tentativa
            rh = x; // rehash

            /*
            Loop para procurar um bucket vazio
            Crit�rios de parada:
            1: as tentativas foram esgotadas (i == t->tam), ou seja, a tabela est� cheia
            2: a chave foi encontrada (t->buckets[rh] == key): como a chave j� existe, ent�o n�o � feita a inser��o
            3: uma posi��o vazia � encontrada (t->buckets[rh] == -1)
            */
            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = overflow_prog(x, t->tam, i); // aplicar a fun��o rehash

                i++; // atualizar a tentativa
            }

            // Se as tentativas n�o foram esgotadas e um bucket apropriado (vazio ou com sinal de que a chave foi removida) foi encontrado, incluir a chave na posi��o rh
            if ((i < t->tam) && (t->buckets[rh] <= 0)){ //0 � o marcador de est
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}


// Antes
/*int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] == key){
            t->buckets[x] = -1;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(key, t); // procurar a chave

        // Se a chave existir, basta atribuir valor 0 para sinalizar a remo��o da chave key na posi��o x
        if (x >= 0){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
        }
    }
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}
