// 1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros. Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.

#include <stdio.h>
#define MAX 100

int main() {
    int matriz[MAX][MAX];
    int n, i, j, min = 0, linha = 0;

    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if(i == 0 && j == 0) {
                min = matriz[i][j];
            }
            if(matriz[i][j] < min) {
                min = matriz[i][j];
                linha = i;
            }
        }
    }

    printf("A linha com o menor número (%d) é: %d\n", min, linha+1);

    return 0;
	}

