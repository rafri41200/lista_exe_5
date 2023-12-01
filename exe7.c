#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularRMSE(int *vetorA, int *vetorB, int tamanho) {
    float somaQuadrados = 0.0;

    for (int i = 0; i < tamanho; i++) {
        float diferenca = vetorA[i] - vetorB[i];
        somaQuadrados += diferenca * diferenca;
    }

    float mse = somaQuadrados / tamanho;
    float rmse = sqrt(mse);

    return rmse;
}

int main() {
    // Tamanho dos vetores
    int tamanho = 10;

    // Aloca dinamicamente os vetores de inteiros
    int *vetorA = (int *)malloc(tamanho * sizeof(int));
    int *vetorB = (int *)malloc(tamanho * sizeof(int));

    // Inicializa a semente para gerar números pseudo-aleatórios
    srand(42); // Usando uma semente fixa para resultados reproduzíveis

    // Preenche os vetores com números pseudo-aleatórios entre 1 e 10
    for (int i = 0; i < tamanho; i++) {
        vetorA[i] = rand() % 10 + 1; // Números aleatórios de 1 a 10
        vetorB[i] = rand() % 10 + 1; // Números aleatórios de 1 a 10
    }

    // Imprime os vetores gerados
    printf("Vetor A:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorA[i]);
    }
    printf("\n");

    printf("Vetor B:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("\n");

    // Calcula e imprime o RMSE
    float rmse = calcularRMSE(vetorA, vetorB, tamanho);
    printf("RMSE: %.2f\n", rmse);

    // Libera a memória alocada para os vetores
    free(vetorA);
    free(vetorB);

    return 0;
}
