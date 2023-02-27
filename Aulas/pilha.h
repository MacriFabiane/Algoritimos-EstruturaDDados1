//pilha. h
#define TAM_MAX 100

typedef struct Pilha Pilha;


// Criar uma pilha vazia
Pilha* criar_pilha();

// Verificar se a pilha est� cheia (stack overflow)
int pilha_cheia(Pilha *p);

// Verificar se a pilha est� vazia (stack underflow)
int pilha_vazia(Pilha *p);

// Inserir um novo item na pilha, caso houver espa�o
int empilhar(Pilha *p, int chave);

// Remover item do topo da pilha, caso essa estrutura n�o estiver vazia
int desempilhar(Pilha *p);

// Imprimir conte�do da pilha
void imprimir_pilha(Pilha *p);

// Liberar a pilha
void liberar_pilha(Pilha *p);

// Obter a posi��o da pilha em que est� o topo
int obter_posicao_topo(Pilha *p);
//ober topo
int obter_topo(Pilha *p);
