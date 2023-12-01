#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para comparar elementos para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para calcular a média
float calcularMedia(int *vetor, int tamanho) {
    float soma = 0.0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return soma / tamanho;
}

// Função para calcular a mediana
float calcularMediana(int *vetor, int tamanho) {
    // Ordena o vetor
    qsort(vetor, tamanho, sizeof(int), comparar);

    // Calcula a mediana
    if (tamanho % 2 == 0) {
        // Se o tamanho for par, a mediana é a média dos dois elementos centrais
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        // Se o tamanho for ímpar, a mediana é o elemento central
        return vetor[tamanho / 2];
    }
}

// Função para calcular a moda
int calcularModa(int *vetor, int tamanho) {
    // Ordena o vetor
    qsort(vetor, tamanho, sizeof(int), comparar);

    int moda = vetor[0];
    int contagem = 1;
    int modaAtual = vetor[0];
    int contagemAtual = 1;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] == vetor[i - 1]) {
            contagemAtual++;
        } else {
            contagemAtual = 1;
            modaAtual = vetor[i];
        }

        if (contagemAtual > contagem) {
            contagem = contagemAtual;
            moda = modaAtual;
        }
    }

    return moda;
}

int main() {
    // Tamanho do vetor
    int tamanho = 10;

    // Aloca dinamicamente o vetor de inteiros
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Inicializa a semente para gerar números pseudo-aleatórios
    srand(time(NULL));

    // Preenche o vetor com números pseudo-aleatórios entre 1 e 10
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10 + 1; // Números aleatórios de 1 a 10
    }

    // Imprime o vetor gerado
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Calcula e imprime a média
    float media = calcularMedia(vetor, tamanho);
    printf("Média: %.2f\n", media);

    // Calcula e imprime a mediana
    float mediana = calcularMediana(vetor, tamanho);
    printf("Mediana: %.2f\n", mediana);

    // Calcula e imprime a moda
    int moda = calcularModa(vetor, tamanho);
    printf("Moda: %d\n", moda);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}
