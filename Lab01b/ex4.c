//4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++

#include <stdio.h>
#include <string.h>

int main() {
    char nome1[100], nome2[100];

    printf("Digite o primeiro nome: ");
    fgets(nome1, sizeof(nome1), stdin);

    printf("Digite o segundo nome: ");
    fgets(nome2, sizeof(nome2), stdin);

    if(strcmp(nome1, nome2) < 0) {
        printf("%s%s", nome1, nome2);
    } else {
        printf("%s%s", nome2, nome1);
    }

    return 0;
}

