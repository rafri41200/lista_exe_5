#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 4) {
        printf("Uso: %s <valor1> <valor2> <codigo_operacao>\n", argv[0]);
        return 1; // Código de retorno indicando erro
    }

    // Converte os argumentos para valores numéricos
    double valor1 = atof(argv[1]);
    double valor2 = atof(argv[2]);
    char codigoOperacao = argv[3][0]; // Assume que o código de operação é um caractere

    // Executa a operação com base no código fornecido
    double resultado;
    switch (codigoOperacao) {
        case 's':
            resultado = valor1 + valor2;
            printf("Resultado da soma: %.2lf\n", resultado);
            break;
        case 'm':
            resultado = valor1 * valor2;
            printf("Resultado da multiplicacao: %.2lf\n", resultado);
            break;
        default:
            printf("Código de operação inválido. Use 's' para soma ou 'm' para multiplicação.\n");
            return 1; // Código de retorno indicando erro
    }

    return 0; // Código de retorno indicando sucesso
}

