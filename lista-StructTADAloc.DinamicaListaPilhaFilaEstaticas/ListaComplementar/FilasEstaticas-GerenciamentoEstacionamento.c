/*O Sr. Pupunha, um grande investidor, comprou um terreno e decidiu faz�-lo um estacionamento, o qual tem capacidade para 10 carros. Ao estacionar o autom�vel,
o cliente recebe um ticket representando por um n�mero inteiro. No entanto, o terreno � muito estreito e, consequentemente, os carros devem ser colocados em
fila. Nesse terreno, a entrada � pelos fundos e a sa�da � pela frente. Caso um cliente precisar sair com o seu carro, os outros autom�veis dever�o ser retirados
e estacionados novamente. Por exemplo, considere a seguinte fila de carros: {1, 2, 3, 4, 5, 6, 7, 8}, onde o primeiro elemento � o ve�culo que est� mais
pr�ximo � sa�da e o �ltimo � mais pr�ximo da entrada. Caso o carro 4 for retirado, os ve�culos 1, 2 e 3 devem estacionados novamente pela entrada do
estacionamento. Desse modo, ap�s a remo��o do ve�culo 4, o estacionamento ficaria na seguinte forma: {5, 6, 7, 8, 1, 2, 3}.

Implemente uma fun��o que receba uma fila est�tica (representa��o do estacionamento) e um n�mero inteiro (ticket ou id do carro) como par�metros e fa�a o
gerenciamento de ve�culos no estacionamento do Pupunha. Enquanto o ticket n�o for encontrado, o primeiro elemento da fila dever� ser removido e recolocado no
final da da fila. Tamb�m, deve ser tratado o caso em que o elemento n�o � encontrado na fila. A fun��o dever� retornar um n�mero inteiro representado a
quantidade de ve�culos que precisaram ser estacionados novamente para que o cliente pudesse retirar o seu carro.

Input Format

Na primeira linha, enquanto -1 n�o for lido, ler n�meros inteiros. Na segunda linha deve ser lido um n�mero inteiro que ser� o ticket a ser procurado na fila.

Constraints

O acesso aos elementos da fila deve ser atrav�s da fun��o desenfileirar.

Output Format

Na primeira linha, o conte�do da fila, ap�s a opera��o de busca, deve ser impresso.

Na segunda linha impresso a quantidade de movimenta��es que foram necess�rias para procurar o ticket.

Na terceira linha deve ser impressa a string "sucesso" caso o ticket for encontrado, ou "falha", caso contr�rio.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam; // tamanho da fila
};

// Criar uma fila vazia
Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1; // fila cheia
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1; // fila vazia
}

// Colocar um item na fila
int enfileirar(Fila *f, int chave){

    if (f == NULL)
        f = criar_fila();


    if (!fila_cheia(f)){
        // Caso a fila estiver vazia
        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;


        f->item[f->fim] = chave;


        f->tam++;

        return 1;
    }

    return 0; // A fila estava cheia
}

// remover um item da fila
int desenfileirar(Fila *f){
    int item = INT_MIN;


    if (!fila_vazia(f)){
        item = f->item[f->ini];
        f->tam--; // a fila reduz o seu tamanho

    if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
    }

    return item;
}


void imprimir_fila(Fila *f){

    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

// liberar fila
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}
int tamanho_fila(Fila *f){
    if (f!=NULL)
        return f->tam;
    else
        return 0;
}
int gerenciar_estacionamento(Fila *f, int t){
    int x=tamanho_fila(f);
    int item= ' ', contador= 0;

    if(f!=NULL){
    do{
        item = desenfileirar(f);

        if (item!=t){
            enfileirar(f,item);
            contador++;
        }
        x--;
    }while((x>0)&&(item!=t));
    }

    imprimir_fila(f);

    printf ("%d\n", contador);

    if (item==t)
        printf("sucesso\n");
    else
        printf("falha\n");

    return contador;
}

int main() {
    Fila *f = criar_fila();
    int item = 0, t;

    while (item!=-1){
        scanf("%d", & item);

        if (item!=-1)
            enfileirar(f, item);

    }
    scanf ("%d", & t);

    gerenciar_estacionamento(f, t);

    liberar_fila(f);

    return 0;
}

