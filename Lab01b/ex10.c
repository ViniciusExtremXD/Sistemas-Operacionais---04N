//10. Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número. Faça o mesmo para uma coluna.

#include <stdio.h>
#define MAX 100

void multiplicar_linha(int n, int m, int matriz[MAX][MAX], int linha, int numero) {
    int j;
    for(j = 0; j < m; j++) {
        matriz[linha][j] *= numero;
    }
}

void multiplicar_coluna(int n, int m, int matriz[MAX][MAX], int coluna, int numero) {
    int i;
    for(i = 0; i < n; i++) {
        matriz[i][coluna] *= numero;
    }
}

int main() {
    int matriz[MAX][MAX];
    int n, m, i, j, linha, coluna, numero;

    printf("\nDigite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("\nDigite o número de colunas da matriz: ");
    scanf("%d", &m);

    printf("\nDigite os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDigite a linha que deseja multiplicar: ");
    scanf("%d", &linha);
    linha--; // ajusta o índice para começar de 0

    printf("\nDigite o número pelo qual deseja multiplicar a linha: ");
    scanf("%d", &numero);

    multiplicar_linha(n, m, matriz, linha, numero);

    printf("\nDigite a coluna que deseja multiplicar: ");
    scanf("%d", &coluna);
    coluna--; // ajusta o índice para começar de 0

    printf("\nDigite o número pelo qual deseja multiplicar a coluna: ");
    scanf("%d", &numero);

    multiplicar_coluna(n, m, matriz, coluna, numero);

    printf("\nMatriz resultante:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

