//3. Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). Este número deve ser sempre ímpar.

//1 2 3 4 5 6 7 8 9
//   2 3 4 5 6 7 8
//      3 4 5 6 7
//         4 5 6
//            5   

#include <stdio.h>

int main() {
    int n, i, j, k;

    do {
        printf("Digite um número ímpar: ");
        scanf("%d", &n);
    } while(n % 2 == 0);

    for(i = 1; i <= n; i+=2) {
        for(j = 1; j < i; j++) {
            printf("  ");
        }
        for(k = i; k <= n; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}

