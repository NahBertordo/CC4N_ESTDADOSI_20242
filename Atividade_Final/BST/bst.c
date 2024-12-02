/*
    * Autor(a): Nathalia Bertordo
      Árvores de Busca (BST) - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
struct No *novoNo(int chave);                   // Função para criar um novo nó
struct No *inserirNo(struct No *No, int chave); // Função para inserir um novo nó na árvore
void inorder(struct No *raiz);                  // Função para imprimir a árvore em ordem

// Estrutura do nó da árvore
struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
};

// Função principal
int main()
{
    struct No *raiz = NULL;

    // Lista de 50 números inteiros
    int array[50] = {
        23, 45, 67, 12, 89, 34, 56, 78, 90, 1,
        22, 33, 44, 55, 66, 77, 88, 99, 0, 10,
        11, 21, 31, 41, 51, 61, 71, 81, 91, 2,
        3, 4, 5, 6, 7, 8, 9, 13, 14, 15,
        16, 17, 18, 19, 20, 30, 40, 50, 60, 70};

    // Insere os números na árvore
    for (int i = 0; i < 50; i++)
    {
        raiz = inserirNo(raiz, array[i]);
    }

    // Imprimir em ordem da árvore
    printf("Em ordem da árvore:\n");
    inorder(raiz);
    printf("\n\n");

    // Imprimir a representação da árvore
    printf("Representação da árvore:\n");
    printf("A mesma se encontra no arquivo chamado RepresentacaoBST.png existente nesse projeto!");

    return 0;
}

struct No *novoNo(int chave)
{
    struct No *No = (struct No *)malloc(sizeof(struct No));
    No->chave = chave;
    No->esquerda = NULL;
    No->direita = NULL;
    return No;
}

struct No *inserirNo(struct No *No, int chave)
{
    // Se a árvore estiver vazia, retorne um novo nó
    if (No == NULL)
        return novoNo(chave);

    // Caso recursivo
    if (chave < No->chave)
        No->esquerda = inserirNo(No->esquerda, chave);
    else if (chave > No->chave)
        No->direita = inserirNo(No->direita, chave);

    // Retorne o ponteiro do nó (não alterado)
    return No;
}

void inorder(struct No *raiz)
{
    if (raiz != NULL)
    {
        inorder(raiz->esquerda);
        printf(",%d ", raiz->chave);
        inorder(raiz->direita);
    }
}