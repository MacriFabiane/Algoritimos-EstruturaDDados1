typedef struct Cell Cell; // Renomea��o da struct Cell

typedef struct ListaE ListaE; // Renomea��o da struct ListaE

// Cria uma nova c�lula
Cell* criar_celula(int key);

// Fun��o para criar uma lista encadeada
ListaE* criar_listaE();

// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int listaE_vazia(ListaE *l);

// Verifica se um item existe na lista
int procurar(int key, ListaE *l);

// Um item � inserido no in�cio da lista
void inserir_primeiro(int key, ListaE *l);

// Um item � inserido no final da lista
void inserir_ultimo(int key, ListaE *l);

// O item procurado e removido da lista caso ela. Para isso, a lista n�o deve estar vazia e o item
// deve existir.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int remover(int key, ListaE *l);

// Imprimir o conte�do da lista
void imprimir(ListaE *l);

// Liberar lista
// Retorna 1 se a opera��o for bem-sucedida ou 0, caso contr�rio
int liberar_LE(ListaE *l);

// Obter o tamanho de uma lista encadeada
int tamanho_LE(ListaE *l);
