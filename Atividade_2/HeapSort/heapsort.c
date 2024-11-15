/*
    * Autor(a): Nathalia Bertordo
    Estrutura de ordenação complexa heapsort - Código com main e funções */

// Declaração das bibliotecas
#include <stdio.h>

// Prototipação das funções
void troca(int *a, int *b);              // Função para trocar os valores de 2 variáveis
void heapify(int array[], int n, int i); // Função para criar um heap máximo
void heapsort(int array[], int n);       // Função para ordenar o array com o metodo heapsort
void imprimirArray(int array[], int n);  // Função para imprimir o array

// Função main
int main()
{
    int array[] = {20, 5, 15, 7, 10, 30};     // Declaração do array de inteiros
    int n = sizeof(array) / sizeof(array[0]); // Calculando o número de elementos no array

    printf("------------------------------------------------------------\n");
    // Imprimindo o array original
    printf("Array original:\n");
    imprimirArray(array, n);

    printf("--------Ordenando o array com o heapsort:--------\n");

    heapsort(array, n); // Chamando a função heapsort para realizar a ordenação do array

    // Imprimindo o array ordenado
    printf("Array ordenado:\n");
    imprimirArray(array, n);
    printf("------------------------------------------------------------\n");

    printf("\n\n");

    // Testes e analise de complexidade em código
    printf("--------Testes e analises de complexidade em código:--------\n\n");
    // Array já ordenado
    int array_ordenado[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n_ordenado = sizeof(array_ordenado) / sizeof(array_ordenado[0]);
    printf("--------Teste com array já ordenado:--------\n");
    printf("Array original:\n");
    imprimirArray(array_ordenado, n_ordenado);
    printf("Array ordenado:\n");
    heapsort(array_ordenado, n_ordenado);
    imprimirArray(array_ordenado, n_ordenado);

    // Array reverso
    int array_reverso[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10};
    int n_reverso = sizeof(array_reverso) / sizeof(array_reverso[0]);
    printf("--------Teste com array reverso:--------\n");
    printf("Array original:\n");
    imprimirArray(array_reverso, n_reverso);
    printf("Array ordenado:\n");
    heapsort(array_reverso, n_reverso);
    imprimirArray(array_reverso, n_reverso);

    // Array aleatório
    int array_aleatorio[] = {3, 5, 1, 9, 6, 8, 2, 7, 10, 4, 12};
    int n_aleatorio = sizeof(array_aleatorio) / sizeof(array_aleatorio[0]);
    printf("--------Teste com array aleatório:--------\n");
    printf("Array original:\n");
    imprimirArray(array_aleatorio, n_aleatorio);
    printf("Array ordenado:\n");
    heapsort(array_aleatorio, n_aleatorio);
    imprimirArray(array_aleatorio, n_aleatorio);
    printf("------------------------------------------------------------\n");
    return 0;
}

// Construção das funções
void troca(int *a, int *b)
{
    int temp = *a; // Guardando o valor apontado por 'a' na variável 'temp'
    *a = *b;       // Atribuindo o valor apontado por 'b' para o lugar apontado por 'a'
    *b = temp;     // Atribuindo o valor de 'temp'(que originalmente guardava o valor de 'a') para o lugar apontado por 'b'
}

void heapify(int array[], int n, int i)
{
    int maior = i;            // Inicializando maior com o valor de i, onde atualmente é o maior nó
    int esquerda = 2 * i + 1; // Calculando o indice do filho esquerdo em uma árvore binária
    int direita = 2 * i + 2;  // Calculando o indice do filho direito em uma árvore binária

    if (esquerda < n && array[esquerda] > array[maior]) // Verficando se o filho da esquerda existe e se o valor é maior que o valor do nó atual, armazenado em 'maior'
    {
        maior = esquerda; // Alterando o índice do 'maior' para o índice do filho da esquerda
    }
    if (direita < n && array[direita] > array[maior]) // Verificando se o filho da direita existe e se o valor é maior que o valor do nó atual, armazenado em 'maior'
    {
        maior = direita; // Alterando o índice do 'maior' para o índice do filho da direita
    }
    if (maior != i) // Verificando se o 'maior' foi alterado
    {
        troca(&array[i], &array[maior]); // Trocando os valores entre o nó em i e o nó em 'maior'
        heapify(array, n, maior);        // Chamando recursivamente a função heapify para a sub-árvore que sofreu alteração, mantendo a propriedade do heap
    }
}

void heapsort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Percorrendo todos os nós internos do heap
    {
        heapify(array, n, i); // Organizando o heap, começando do índice i
    }
    for (int i = n - 1; i > 0; i--) // Fazendo a ordenação, trocando o 1° elemento com o último não ordenado
    {
        troca(&array[0], &array[i]); // Trocando o maior elemento do heap com o último elemento do array não ordenado
        heapify(array, i, 0);        // Refazendo o heap para manter a sua propriedade
    }
}

void imprimirArray(int array[], int n)
{
    for (int i = 0; i < n; ++i) // Percorrendo todos os elementos do array
    {
        printf("%d ", array[i]); // Imprimindo os elementos do array
    }
    printf("\n");
}