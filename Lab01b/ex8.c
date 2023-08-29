//8. Crie uma função capaz de criar a transposta de uma matriz.

#include <stdio.h>
#define MAX 100

void calcular_transposta(int n, int m, int matriz[MAX][MAX], int transposta[MAX][MAX]) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int matriz[MAX][MAX], transposta[MAX][MAX];
    int n, m, i, j;

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

    calcular_transposta(n, m, matriz, transposta);

    printf("\nMatriz transposta:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

