//9 Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.

#include <stdio.h>
#include <stdlib.h> // para a função abs
#define MAX 100

void modulo(int n, int m, int matriz[MAX][MAX]) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] < 0) {
                matriz[i][j] = abs(matriz[i][j]);
            }
        }
    }
}

int main() {
    int matriz[MAX][MAX];
    int n, m, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    printf("Digite os elementos da matriz:\n\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    modulo(n, m, matriz);

    printf("\nMatriz após substituir números negativos por seus módulos:\n\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

