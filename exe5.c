#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float somarElementos(float *vetor, int tamanho) {
    float soma = 0.0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return soma;
}

int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2) {
        printf("Uso: %s <quantidade_elementos>\n", argv[0]);
        return 1; // Código de retorno indicando erro
    }

    // Converte o argumento para um número inteiro
    int quantidadeElementos = atoi(argv[1]);

    // Verifica se a conversão foi bem-sucedida
    if (quantidadeElementos <= 0) {
        printf("Por favor, forneça um número válido de elementos.\n");
        return 1; // Código de retorno indicando erro
    }

    // Aloca dinamicamente o vetor de float
    float *vetor = (float *)malloc(quantidadeElementos * sizeof(float));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1; // Código de retorno indicando erro
    }

    // Semente para gerar números pseudo-aleatórios
    srand(time(NULL));

    // Preenche o vetor com valores pseudo-aleatórios
    for (int i = 0; i < quantidadeElementos; i++) {
        vetor[i] = (float)rand() / RAND_MAX; // Números pseudo-aleatórios entre 0 e 1
    }

    // Imprime o vetor
    printf("Vetor gerado:\n");
    for (int i = 0; i < quantidadeElementos; i++) {
        printf("%.2f ", vetor[i]);
    }
    printf("\n");

    // Calcula e imprime a soma dos elementos
    float soma = somarElementos(vetor, quantidadeElementos);
    printf("Soma dos elementos: %.2f\n", soma);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0; // Código de retorno indicando sucesso
}
