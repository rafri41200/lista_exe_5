#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para binarizar a matriz com base no limiar t
void binarizarMatriz(int **matrizM, int **matrizS, int linhas, int colunas, int limiar) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizS[i][j] = (matrizM[i][j] > limiar) ? 1 : 0;
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Definir as dimensões da matriz
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Alocar dinamicamente a matriz M e a matriz S
    int **matrizM = (int **)malloc(linhas * sizeof(int *));
    int **matrizS = (int **)malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++) {
        matrizM[i] = (int *)malloc(colunas * sizeof(int));
        matrizS[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Inicializar a semente para gerar números pseudo-aleatórios
    srand(time(NULL));

    // Preencher a matriz M com valores pseudo-aleatórios entre 0 e 10
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizM[i][j] = rand() % 11; // Números aleatórios de 0 a 10
        }
    }

    // Imprimir a matriz M original
    printf("Matriz M (Original):\n");
    imprimirMatriz(matrizM, linhas, colunas);

    // Definir o limiar t
    int limiar;

    printf("Digite o limiar (t): ");
    scanf("%d", &limiar);

    // Binarizar a matriz M e criar a matriz S
    binarizarMatriz(matrizM, matrizS, linhas, colunas, limiar);

    // Imprimir a matriz S binarizada
    printf("Matriz S (Binarizada com limiar %d):\n", limiar);
    imprimirMatriz(matrizS, linhas, colunas);

    // Liberar a memória alocada para as matrizes
    for (int i = 0; i < linhas; i++) {
        free(matrizM[i]);
        free(matrizS[i]);
    }

    free(matrizM);
    free(matrizS);

    return 0;
}
