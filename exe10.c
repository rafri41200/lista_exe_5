#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para inicializar um vetor com números pseudoaleatórios no intervalo [0, N-1]
void inicializarVetor(int *vetor, int tamanho, int N) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % N;
    }
}

// Função para criar a matriz de coocorrências M
void criarMatrizCoocorrencias(int *X, int *Y, int *M, int tamanho, int N) {
    for (int i = 0; i < tamanho; i++) {
        M[X[i] * N + Y[i]]++;
    }
}

// Função para imprimir a matriz M
void imprimirMatriz(int *M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i * N + j]);
        }
        printf("\n");
    }
}

int main() {
    // Definir N e o tamanho dos vetores
    int N = 7;
    int tamanho = 14;

    // Alocar dinamicamente os vetores X, Y e a matriz M
    int *X = (int *)malloc(tamanho * sizeof(int));
    int *Y = (int *)malloc(tamanho * sizeof(int));
    int *M = (int *)calloc(N * N, sizeof(int)); // Inicializado com zeros usando calloc

    // Inicializar a semente para gerar números pseudoaleatórios
    srand(time(NULL));

    // Inicializar os vetores X e Y
    inicializarVetor(X, tamanho, N);
    inicializarVetor(Y, tamanho, N);

    // Criar a matriz de coocorrências M
    criarMatrizCoocorrencias(X, Y, M, tamanho, N);

    // Imprimir os vetores X e Y
    printf("Vetor X:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    printf("Vetor Y:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    // Imprimir a matriz de coocorrências M
    printf("Matriz M:\n");
    imprimirMatriz(M, N);

    // Liberar a memória alocada
    free(X);
    free(Y);
    free(M);

    return 0;
}
