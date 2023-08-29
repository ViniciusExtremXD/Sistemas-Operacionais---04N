//11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.

#include <stdio.h>
#define MAX 100

void somar_linhas(int m, int matriz[MAX][MAX], int l1, int l2) {
    int j;
    for(j = 0; j < m; j++) {
        matriz[l2][j] += matriz[l1][j];
    }
}

void multiplicar_linhas(int m, int matriz[MAX][MAX], int l1, int l2) {
    int j;
    for(j = 0; j < m; j++) {
        matriz[l2][j] *= matriz[l1][j];
    }
}

int main() {
    int matriz[MAX][MAX];
    int n, m, i, j, l1, l2;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDigite as duas linhas que deseja somar: ");
    scanf("%d %d", &l1, &l2);
    l1--; // ajusta o índice para começar de 0
    l2--; // ajusta o índice para começar de 0

    somar_linhas(m, matriz, l1, l2);

    printf("\nDigite as duas linhas que deseja multiplicar: ");
    scanf("%d %d", &l1, &l2);
    l1--; // ajusta o índice para começar de 0
    l2--; // ajusta o índice para começar de 0

    multiplicar_linhas(m, matriz, l1, l2);

    printf("\nMatriz resultante:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}



