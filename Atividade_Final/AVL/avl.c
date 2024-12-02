/*
    * Autor(a): Nathalia Bertordo
      Árvores de Busca (AVL) - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
struct No *novoNo(int valor);                   // Função para criar um novo nó
int altura(struct No *raiz);                    // Função para obter a altura de um nó
int balancemento(struct No *raiz);              // Função para calcular o fator de balanceamento de um nó
struct No *rotacaoDireita(struct No *y);        // Função de rotação à direita
struct No *rotacaoEsquerda(struct No *x);       // Função de rotação à esquerda
struct No *inserir(struct No *raiz, int valor); // Função para inserir um valor na árvore AVL
void preOrder(struct No *raiz);                 // Função para realizar o percurso pré-ordem (raiz, esquerda, direita)
void inOrder(struct No *raiz);                  // Função para realizar o percurso em-ordem (esquerda, raiz, direita)
void postOrder(struct No *raiz);                // Função para realizar o percurso pós-ordem (esquerda, direita, raiz)

// Definindo a estrutura do nó da árvore
struct No
{
    int valor;           // Valor armazenado no nó
    struct No *esquerda; // Ponteiro do filho da equerda
    struct No *direita;  // Ponteiro do filho da direita
    int altura;          // Altura do nó
};

int main()
{
    struct No *raiz = NULL; // Inicializando a raiz da árvore como NULL
    int array[50] = {
        71, 35, 84, 23, 45, 58, 62, 6, 3, 15,
        97, 22, 19, 55, 41, 66, 87, 28, 79, 92,
        90, 11, 14, 48, 7, 64, 60, 70, 27, 17,
        9, 43, 31, 34, 49, 53, 37, 80, 63, 4,
        33, 68, 18, 50, 30, 36, 56, 5, 72, 20}; // Array de inteiros para inserção na árvore

    // Inserindo todos os números na árvore AVL
    for (int i = 0; i < 50; i++)
    {
        raiz = inserir(raiz, array[i]); // Inserindo cada elemento na árvore
    }

    // Exibindo os percursos
    printf("Pré-ordem: ");
    preOrder(raiz);
    printf("---------------------------------------------------------------\n");
    printf("Em-ordem: ");
    inOrder(raiz);
    printf("---------------------------------------------------------------\n");
    printf("Pós-ordem: ");
    postOrder(raiz);
    printf("---------------------------------------------------------------\n");
    // Imprimir a representação da árvore
    printf("Representação da árvore:\n");
    printf("A mesma se encontra no arquivo chamado RepresentacaoBST.png existente nesse projeto!");

    return 0;
}

struct No *novoNo(int valor)
{
    struct No *No = (struct No *)malloc(sizeof(struct No)); // Alocando a memória para um novo nó
    No->valor = valor;                                      // Definindo o valor do nó
    No->esquerda = No->direita = NULL;                      // Inicilizando os filhos
    No->altura = 1;                                         // Inserindo o 1 ao nó é inicialmente inserido com altura 1
    return No;
}

int altura(struct No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return raiz->altura; // retornando a altura do nó
}

int balancemento(struct No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return altura(raiz->esquerda) - altura(raiz->direita); // Retornando a diferença entre os filhos
}

struct No *rotacaoDireita(struct No *y)
{
    struct No *x = y->esquerda; // Armazenando o filho da esquerda de y
    struct No *T2 = x->direita; // Armazenando o filho da esquerda de x

    // Realizando a rotção
    x->direita = y;   // O filho da direita de x agora é y
    y->esquerda = T2; // O filho da esquerda de y agora é T2

    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita)); // Atualizando a altura de y
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita)); // Atualizando a altura de x

    return x;
}

struct No *rotacaoEsquerda(struct No *x)
{
    struct No *y = x->direita;   // Armazenenando o filho da direita de x
    struct No *T2 = y->esquerda; // Armazenenando o filho da direita de y

    // Realizando a rotação
    y->esquerda = x; // O filho da esquerda de y agora é x
    x->direita = T2; // O filho da direita de x agora é T2

    // Atualizando as alturas
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita)); // Atualiza a altura de x
    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita)); // Atualiza a altura de y

    return y;
}

struct No *inserir(struct No *raiz, int valor)
{
    if (raiz == NULL) // Se a raiz é NULL, cria um novo nó
    {
        return novoNo(valor); // Retornando um novo nó
    }

    // Inserindo o valor na subárvore correta
    if (valor < raiz->valor) // Se o valor é menor que o valor do nó atual
    {
        raiz->esquerda = inserir(raiz->esquerda, valor); // Inserindo na subárvore esquerda
    }
    else if (valor > raiz->valor) // Se o valor é maior que o valor do nó atual
    {
        raiz->direita = inserir(raiz->direita, valor); // Inserindo na subárvore direita
    }
    else
    {
        return raiz; // Valores duplicados não são permitidos na árvore
    }

    // Atualizando a altura do nó
    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));

    // Verificando o fator de balanceamento e realiza as rotações, se necessário
    int balance = balancemento(raiz);

    // Caso 1: rotação à esquerda
    if (balance > 1 && valor < raiz->esquerda->valor)
    {
        return rotacaoDireita(raiz);
    }

    // Caso 2: rotação à direita
    if (balance < -1 && valor > raiz->direita->valor)
    {
        return rotacaoEsquerda(raiz);
    }

    // Caso 3: rotação à esquerda-direita
    if (balance > 1 && valor > raiz->esquerda->valor)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Caso 4: rotação à direita-esquerda
    if (balance < -1 && valor < raiz->direita->valor)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void preOrder(struct No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preOrder(raiz->esquerda); // Chamando a função recursivamente para a subárvore esquerda
        preOrder(raiz->direita);  // Chamando a função recursivamente para a subárvore direita
    }
}

void inOrder(struct No *raiz)
{
    if (raiz != NULL)
    {
        inOrder(raiz->esquerda); // Chamando a função recursivamente para a subárvore esquerda
        printf("%d ", raiz->valor);
        inOrder(raiz->direita); // Chamando a função recursivamente para a subárvore direita
    }
}

void postOrder(struct No *raiz)
{
    if (raiz != NULL)
    {
        postOrder(raiz->esquerda); // Chamando a função recursivamente para a subárvore esquerda
        postOrder(raiz->direita);  // Chamando a função recursivamente para a subárvore direita
        printf("%d ", raiz->valor);
    }
}
