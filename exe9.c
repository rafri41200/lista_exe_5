#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para verificar se um número é par
int ehPar(int numero)
{
  return numero % 2 == 0;
}

// Função para calcular a soma da diagonal principal
int calcularSomaDiagonalPrincipal(int **matriz, int tamanho)
{
  int soma = 0;
  for (int i = 0; i < tamanho; i++)
  {
    soma += matriz[i][i];
  }
  return soma;
}

// Função para imprimir a matriz
void imprimirMatriz(int **matriz, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  // Definir o tamanho da matriz
  int tamanho;

  printf("Digite o tamanho da matriz (N x N): ");
  scanf("%d", &tamanho);

  // Alocar dinamicamente a matriz
  int **matriz = (int **)malloc(tamanho * sizeof(int *));
  for (int i = 0; i < tamanho; i++)
  {
    matriz[i] = (int *)malloc(tamanho * sizeof(int));
  }

  // Inicializar a semente para gerar números pseudo-aleatórios
  srand(time(NULL));

  // Preencher a matriz com valores pseudo-aleatórios entre 0 e 10
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      matriz[i][j] = rand() % 11; // Números aleatórios de 0 a 10
    }
  }

  // Imprimir a matriz gerada
  printf("Matriz gerada:\n");
  imprimirMatriz(matriz, tamanho);

  // Calcular e imprimir a soma da diagonal principal
  int somaDiagonalPrincipal = calcularSomaDiagonalPrincipal(matriz, tamanho);
  printf("Soma da diagonal principal: %d\n", somaDiagonalPrincipal);

  // Verificar se a soma é par ou ímpar e imprimir o resultado
  if (ehPar(somaDiagonalPrincipal))
  {
    printf("A soma da diagonal principal é par.\n");
  }
  else
  {
    printf("A soma da diagonal principal é ímpar.\n");
  }

  // Liberar a memória alocada para a matriz
  for (int i = 0; i < tamanho; i++)
  {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
