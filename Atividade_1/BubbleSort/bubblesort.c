/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação bubblesort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipação da função
void bubblesortFunction(int arrayInt[], int tamanho); // Função que fará o bubblesort no array

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

    // Mostrando o array original formado com os números gerados
    printf("Array Original: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    printf("--------Ordenando o array com o bubblesort:--------\n");

    // Chamando a função bubblesort para realizar a oredenação do array
    bubblesortFunction(arrayInt, tamanho);

    // Mostrando o array ordenado pela função bubblesort
    printf("Array Ordenado: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arrayInt[i]);
    }
    printf("\n");

    return 0;
}

// Construção da função
void bubblesortFunction(int arrayInt[], int tamanho)
{
    int i, j, temp;                   // Declaração das variáveis
    for (i = 0; i < tamanho - 1; i++) // Loop que corre o array todo exceto o último
    {
        for (j = 0; j < tamanho - i - 1; j++) // Loop que compara os próximos elementos
        {
            if (arrayInt[j] > arrayInt[j + 1]) // Verifica e troca se o elemento atual é maior que o próximo
            {
                temp = arrayInt[j];            // Guarda o valor elemento atual na variável temp
                arrayInt[j] = arrayInt[j + 1]; // Troca o valor do elemento atual pelo próximo
                arrayInt[j + 1] = temp;        // Coloca o valor guardado na variável temp na posição do próximo elemento
            }
        }
    }
}