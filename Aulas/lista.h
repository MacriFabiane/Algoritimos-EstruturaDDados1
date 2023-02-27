#define MAX_SIZE 100 // tamanho m�ximo da lista

typedef struct Lista Lista; // Renomea��o da estrutura struct Lista

// Fun��o para criar uma lista est�tica
Lista* criar_lista();

// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int lista_vazia(Lista *l);

// Retorna 1 se a lista est� cheia ou 0, caso contr�rio
int lista_cheia(Lista *l);

// Procura a posi��o de um item com a chave e retorna a sua respectiva posi��o
// Caso o item n�o seja encontrado, � retornado -1
int buscar(Lista *l, int chave);

// Um item � inserido no final da lista caso ela n�o estiver cheia.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int inserir(Lista *l, int chave);

// O item procurado e removido da lista caso ela. Para isso, a lista n�o deve estar vazia e o item
// deve existir.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int remover(Lista *l, int chave);

// Imprime o conte�do da lista
void imprimir_lista(Lista *l);

// Libera a lista
// Retorna 1 se a opera��o for bem-sucedida ou 0, caso contr�rio
int liberar_lista(Lista *l);

Lista* concatenar (Lista *l1, Lista *l2);
int inserir_ordenado(Lista *l, int chave);

