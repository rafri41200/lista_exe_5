#include <stdio.h>

void normalizarMinMax(int *vetor, int tamanho) {
    // Encontrar o valor mínimo e máximo do vetor
    int minValor = vetor[0];
    int maxValor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < minValor) {
            minValor = vetor[i];
        }
        if (vetor[i] > maxValor) {
            maxValor = vetor[i];
        }
    }

    // Normalizar o vetor
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = (vetor[i] - minValor) / (float)(maxValor - minValor);
    }
}

int main() {
    // Exemplo de vetor de inteiros
    int vetor[] = {3, 8, 2, 5, 10};

    // Tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Imprimir vetor original
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Normalizar o vetor
    normalizarMinMax(vetor, tamanho);

    // Imprimir vetor normalizado
    printf("Vetor normalizado (min-max):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", (float)vetor[i]);
    }
    printf("\n");

    return 0;
}
