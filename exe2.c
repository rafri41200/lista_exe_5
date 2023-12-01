#include <stdio.h>
#include <stdlib.h>

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

    // Aloca dinamicamente o vetor de inteiros
    int *vetor = (int *)malloc(quantidadeElementos * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1; // Código de retorno indicando erro
    }

    // Preenche o vetor com números aleatórios
    for (int i = 0; i < quantidadeElementos; i++) {
        vetor[i] = rand() % 100; // Números aleatórios de 0 a 99
    }

    // Encontra o menor elemento e seu endereço
    int menorElemento = vetor[0];
    int *enderecoMenorElemento = &vetor[0];

    for (int i = 1; i < quantidadeElementos; i++) {
        if (vetor[i] < menorElemento) {
            menorElemento = vetor[i];
            enderecoMenorElemento = &vetor[i];
        }
    }

    // Imprime o vetor
    printf("Vetor gerado:\n");
    for (int i = 0; i < quantidadeElementos; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Imprime o endereço do menor elemento
    printf("Endereço do menor elemento: %p\n", (void *)enderecoMenorElemento);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0; // Código de retorno indicando sucesso
}
