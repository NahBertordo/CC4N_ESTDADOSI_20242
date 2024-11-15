/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação complexa radixsort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipação das funções
int encontrarMaior(int array[], int tamanho);         // Função para encontrar o maior número no array
void countingSort(int array[], int tamanho, int exp); // Função para fazer a ordenação por contagem para cada dígito
void radixSort(int array[], int tamanho);             // Função principal do Radix Sort
void imprimirArray(int array[], int tamanho);         // Função para imprimir o array
int numRepetido(int array[], int tamanho, int num);   // Função para verificar se existe um número repetido no array

// Função main
int main()
{
    srand(time(0));                                 // Gerando números aleatórios
    int array[50];                                  // Declarando um array de inteiros
    int tamanho = sizeof(array) / sizeof(array[0]); // Calculando o tamanho do array
    int i;

    for (i = 0; i < tamanho; i++)
    {
        array[i] = rand() % 100; // Atribuindo um número aleatório entre 0 e 99 a cada elemento do array
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    // Imprimindo o array original
    printf("Array original: \n");
    imprimirArray(array, tamanho);

    printf("--------Ordenando o array com o RadixSort:--------\n");

    radixSort(array, tamanho);

    // Imprimindo o array ordenado
    printf("Array ordenado: \n");
    imprimirArray(array, tamanho);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\n");

    // Testes e analise de complexidade em código
    printf("--------Testes e analises de complexidade em código:------------------------------------------------------------------------------------------------\n\n");
    // Array já ordenado
    int array_ordenado[50];
    int tamanho_ordenado = sizeof(array_ordenado) / sizeof(array_ordenado[0]);
    for (i = 0; i < tamanho_ordenado; i++)
    {
        array_ordenado[i] = 50 + i;
    }
    printf("--------Teste com array já ordenado:----------------------------------------------------------------------------------------------------------------\n");
    printf("Array original:\n");
    imprimirArray(array_ordenado, tamanho_ordenado);
    printf("Array ordenado:\n");
    radixSort(array_ordenado, tamanho_ordenado);
    imprimirArray(array_ordenado, tamanho_ordenado);

    // Array reverso
    int array_reverso[50];
    int tamanho_reverso = sizeof(array_reverso) / sizeof(array_reverso[0]);
    for (i = 0; i < tamanho_reverso; i++)
    {
        array_reverso[i] = 99 - i;
    }
    printf("--------Teste com array reverso:-------------------------------------------------------------------------------------------------------------------\n");
    printf("Array original:\n");
    imprimirArray(array_reverso, tamanho_reverso);
    printf("Array ordenado:\n");
    radixSort(array_reverso, tamanho_reverso);
    imprimirArray(array_reverso, tamanho_reverso);

    // Array aleatório
    int array_aleatorio[50];
    int tamanho_aleatorio = sizeof(array_aleatorio) / sizeof(array_aleatorio[0]);
    int j = 0;
    while (j < tamanho_aleatorio)
    {
        int num = rand() % 100; // Gerando um número aleatório entre 0 e 99

        if (!numRepetido(array_aleatorio, tamanho_aleatorio, num)) // Verificando se o número já existe no array
        {
            array_aleatorio[j] = num; // Adicionando o número se não estiver
            j++;
        }
    }

    printf("--------Teste com array aleatório e sem repetições:-------------------------------------------------------------------------------------------------\n");
    printf("Array original:\n");
    imprimirArray(array_aleatorio, tamanho_aleatorio);
    printf("Array ordenado:\n");
    radixSort(array_aleatorio, tamanho_aleatorio);
    imprimirArray(array_aleatorio, tamanho_aleatorio);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    return 0;
}

// Construção das funções
int encontrarMaior(int array[], int tamanho)
{
    int maior = array[0]; // Inicializando o maior número como o 1° elemento
    for (int i = 1; i < tamanho; i++)
    {
        if (array[i] > maior)
        {
            maior = array[i]; // Atualizando o maior número se 'maior for encontrado
        }
    }
    return maior; // Retornando o maior número encontrado
}

void countingSort(int array[], int tamanho, int exp)
{
    int output[tamanho]; // Array de saída que terá os números ordenados
    int count[10] = {0}; // Array de contagem inicializado com zeros

    // Armazenando a contagem de ocorrências de cada dígito
    for (int i = 0; i < tamanho; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    // Alterando count[i] para que contenha a posição atual do dígito
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Construindo o array de saída
    for (int i = tamanho - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copiando o array de saída para o array original, para conter números ordenados de acordo com o dígito atual
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int array[], int tamanho)
{
    // Encontrando o maior número para saber o número de dígitos
    int maior = encontrarMaior(array, tamanho);

    // Fazendo o counting sort para cada dígito
    for (int exp = 1; maior / exp > 0; exp *= 10)
    {
        countingSort(array, tamanho, exp);
    }
}

void imprimirArray(int array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]); // Imprimindo cada elemento
    }
    printf("\n");
}

int numRepetido(int array[], int tamanho, int num)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] == num)
        {
            return 1; // Número já existe
        }
    }
    return 0; // Número não existe
}