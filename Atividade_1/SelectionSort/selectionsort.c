/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação selectionsort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipação da função
void selectionsortFunction(int arrayInt[], int tamanho); // Função que fará o selectionsort no array

// Função main
int main()
{
    srand(time(0));                                       // Gerando números aleatórios para cada vez que o código for executado
    int arrayInt[50];                                     // Declaração do array de inteiros com 50 números
    int tamanho = sizeof(arrayInt) / sizeof(arrayInt[0]); // Calculando o número de elementos no array = 50
    int i;

    // Preenchendo o array com os números inteiros aleatórios
    for (i = 0; i < tamanho; i++)
    {
        arrayInt[i] = rand() % 100; // Atribuindo um número aleatório entre 0 e 99 a cada elemento do array
    }
    // Imprimindo o array original
    printf("Array original:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    printf("--------Ordenando o array com o selectionsort:--------\n");

    selectionsortFunction(arrayInt, tamanho); // Chamando a função selectionsort para realizar a oredenação do array

    // Imprimindo o array ordenado
    printf("Array ordenado:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    return 0;
}

// Construção da função
void selectionsortFunction(int arrayInt[], int tamanho)
{
    int i, j, minIndex, temp; // Declaração das variáveis

    for (int i = 0; i < tamanho - 1; i++) // Percorrendo cada posição do array
    {
        minIndex = i;                     // Assumindo que o elemento atual é o menor
        for (j = i + 1; j < tamanho; j++) // Loop para achar o menor elemento no resto do array
        {
            if (arrayInt[j] < arrayInt[minIndex]) // Se o elemento atual for menor que o valor já armazenado como o menor
            {
                minIndex = j; // Atualizando o índice do menor elemento
            }
        }
        // Trocando o menor elemento encontrado com o elemento na posição i
        temp = arrayInt[minIndex];        // Guardando o menor elemento na variável temp
        arrayInt[minIndex] = arrayInt[i]; // Colocando o elemento na posição i
        arrayInt[i] = temp;               // Colocando o menor elemento posição certa
    }
}