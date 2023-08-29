//6. Crie um programa capaz de criar a transposta de uma matriz. A matriz deve ser lida de teclado.

#include <stdio.h>
#define MAX 100

int main() {
    int matriz[MAX][MAX], transposta[MAX][MAX];
    int n, m, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    printf("\nDigite os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz transposta:\n\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

