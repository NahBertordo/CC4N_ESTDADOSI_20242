/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação complexa quicksort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipação das funções
void troca(int *a, int *b);                         // Função para trocar os valores de 2 variáveis
int particionar(int array[], int baixo, int alto);  // Função para particionar o array em volta do pivo
void quickSort(int array[], int baixo, int alto);   // Função para ordenar recursivamente o array, dividindo em subarrays
void imprimirArray(int array[], int n);             // Função para imprimir o array
int numRepetido(int array[], int tamanho, int num); // Função para verificar se existe um número repetido no array

// Função Main
int main()
{
    srand(time(0));                           // Gerando números aleatórios
    int array[50];                            // Declarando um array de inteiros
    int n = sizeof(array) / sizeof(array[0]); // Calculando o tamanho do array
    int i;

    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 100; // Atribuindo um número aleatório entre 0 e 99 a cada elemento do array
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    // Imprimindo o array original
    printf("Array original: \n");
    imprimirArray(array, n);
    quickSort(array, 0, n - 1);

    printf("--------Ordenando o array com o QuickSort:--------\n");

    quickSort(array, 0, n - 1);

    // Imprimindo o array ordenado
    printf("Array ordenado: \n");
    imprimirArray(array, n);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\n");

    // Testes e analise de complexidade em código
    printf("--------Testes e analises de complexidade em código:--------\n\n");
    // Array já ordenado
    int array_ordenado[50];
    int n_ordenado = sizeof(array_ordenado) / sizeof(array_ordenado[0]);
    for (i = 0; i < n_ordenado; i++)
    {
        array_ordenado[i] = 50 + i;
    }
    printf("--------Teste com array já ordenado:----------------------------------------------------------------------------------------------------------------\n");
    printf("Array original:\n");
    imprimirArray(array_ordenado, n_ordenado);
    printf("Array ordenado:\n");
    quickSort(array_ordenado, 0, n_ordenado - 1);
    imprimirArray(array_ordenado, n_ordenado);

    // Array reverso
    int array_reverso[50];
    int n_reverso = sizeof(array_reverso) / sizeof(array_reverso[0]);
    for (i = 0; i < n_reverso; i++)
    {
        array_reverso[i] = 99 - i;
    }
    printf("--------Teste com array reverso:--------\n");
    printf("Array original:\n");
    imprimirArray(array_reverso, n_reverso);
    printf("Array ordenado:\n");
    quickSort(array_reverso, 0, n_reverso - 1);
    imprimirArray(array_reverso, n_reverso);

    // Array aleatório
    int array_aleatorio[50];
    int n_aleatorio = sizeof(array_aleatorio) / sizeof(array_aleatorio[0]);
    int j = 0;
    while (j < n_aleatorio)
    {
        int num = rand() % 100; // Gerando um número aleatório entre 0 e 99

        if (!numRepetido(array_aleatorio, n_aleatorio, num)) // Verificando se o número já existe no array
        {
            array_aleatorio[j] = num; // Adicionando o número se não estiver
            j++;
        }
    }

    printf("--------Teste com array aleatório e sem repetições:-------------------------------------------------------------------------------------------------\n");
    printf("Array original:\n");
    imprimirArray(array_aleatorio, n_aleatorio);
    printf("Array ordenado:\n");
    quickSort(array_aleatorio, 0, n_aleatorio);
    imprimirArray(array_aleatorio, n_aleatorio);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Construção das funções
void troca(int *a, int *b)
{
    int temp = *a; // Guardando o valor apontado por 'a' na variável 'temp'
    *a = *b;       // Atribuindo o valor apontado por 'b' para o lugar apontado por 'a'
    *b = temp;     // Atribuindo o valor de 'temp'(que originalmente guardava o valor de 'a') para o lugar apontado por 'b'
}

int particionar(int array[], int baixo, int alto)
{
    int pivo = array[alto]; // Definindo o último elemento do array como pivo
    int i = (baixo - 1);    // Inicializando o índice do menor elemento
    int j;
    for (j = baixo; j < alto; j++) // Comparando os elementos do aaray com o pivo e organizando
    {
        if (array[j] <= pivo) // Trocando o elemento atual com o indice 'i', se o mesmo for menor ou igual ao pivo
        {
            i++; // Incrementando o indice do menor elemento
            troca(&array[i], &array[j]);
        }
    }
    troca(&array[i + 1], &array[alto]); // Colocando o pivo na posição certa
    return (i + 1);                     // Retornando o indice do pivo
}

void quickSort(int array[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pivo = particionar(array, baixo, alto); // Encontrando o indice do pivo, ele estando na posição final do array
        // Ordenando recursivamente os suarrays antes e dspois do pivo
        quickSort(array, baixo, pivo - 1); // Ordenando o subarray antes do pivo
        quickSort(array, pivo + 1, alto);  // Ordenando o subarray depois do pivo
    }
}

void imprimirArray(int array[], int n)
{
    for (int i = 0; i < n; i++) // Percorrendo todos os elementos do array
    {
        printf("%d ", array[i]); // Imprimindo os elementos do array
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