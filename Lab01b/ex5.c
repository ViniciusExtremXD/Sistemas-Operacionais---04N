// 5. Crie um programa  capaz de multiplicar uma linha de uma matriz de inteiros por um dado número. Faça o mesmo para uma coluna. A matriz deve ser lida de teclado.

#include <stdio.h>
#define MAX 100

int main() {
    int matriz[MAX][MAX];
    int n, i, j, linha, coluna, numero;

    printf("\nDigite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    printf("\nDigite os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDigite a linha que deseja multiplicar: ");
    scanf("%d", &linha);
    linha--; // ajusta o índice para começar de 0

    printf("\nDigite o número pelo qual deseja multiplicar a linha: ");
    scanf("%d", &numero);

    for(j = 0; j < n; j++) {
        matriz[linha][j] *= numero;
    }

    printf("\nDigite a coluna que deseja multiplicar: ");
    scanf("%d", &coluna);
    coluna--; // ajusta o índice para começar de 0

    printf("\nDigite o número pelo qual deseja multiplicar a coluna: ");
    scanf("%d", &numero);

    for(i = 0; i < n; i++) {
        matriz[i][coluna] *= numero;
    }

    printf("\nMatriz resultante:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

