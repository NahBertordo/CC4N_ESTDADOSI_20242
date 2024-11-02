/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação insertionsort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipação da função
void insertionsortFunction(int arrayInt[], int tamanho); // Função que fará o insertionsort no array

// Função main
int main()
{
    srand(time(0)); // Gerando números aleatórios para cada vez que o código for executado

    int arrayInt[50];                                     // Declaração do array de inteiros com 50 números
    int tamanho = sizeof(arrayInt) / sizeof(arrayInt[0]); // Calculando o número de elementos no array = 50
    int i;

    // Preenchendo o array com os números inteiros aleatórios
    for (i = 0; i < tamanho; i++)
    {
        arrayInt[i] = rand() % 100; // Atribuindo um número aleatório entre 0 e 99 a cada elemento do array
    }
    // Imprimindo o array original
    printf("Array original: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    printf("--------Ordenando o array com o insertionsort:--------\n");

    insertionsortFunction(arrayInt, tamanho); // Chamando a função insertionsort para realizar a oredenação do array

    // Imprimindo o array ordenado
    printf("Array ordenado: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    return 0;
}

// Construção da função
void insertionsortFunction(int arrayInt[], int tamanho)
{
    int i, temp, j;               // Declaração de variáveis
    for (i = 1; i < tamanho; i++) // Iterando a partir do índice 1 até o último
    {
        temp = arrayInt[i]; // Guarda o elemento atual que será inserido na parte ordenada do array
        j = i - 1;          // Inicilizando j como índice do elemento anterior à temp

        // Movendo os elementos que são maiores que temp para a posição à frente
        while (j >= 0 && arrayInt[j] > temp) // Enquanto j não for negativo e o elemento à esquerda for maior que temp
        {
            arrayInt[j + 1] = arrayInt[j]; // Movendo o elemento maior para a direita
            j = j - 1;                     // Decrementando j para continuar a comparação
        }
        arrayInt[j + 1] = temp; // Inserindo temp na posição certa no array
    }
}