//7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura.

#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    float peso;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoas[3];
    int i;

    for(i = 0; i < 3; i++) {
        printf("\nDigite o nome da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].nome);

        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].idade);

        printf("Digite o peso da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].peso);

        printf("Digite a altura da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].altura);
    }

    for(i = 0; i < 3; i++) {
        printf("\nDados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n", pessoas[i].altura);
    }

    return 0;
}

