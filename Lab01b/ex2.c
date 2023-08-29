// 2.Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito de acordo com a tabela:
//maior ou igual a 9	A
//maior ou igual a 7.5 e menor que 9	B
//maior ou igual a 6 e menor que 7.5	C
//maior ou igual a 4 e menor que 6	D
//menor que 4	E

#include <stdio.h>

int main() {
    float n1, n2, n3, me, ma;

    printf("Digite as três notas do aluno: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    printf("Digite a média dos exercícios: ");
    scanf("%f", &me);

    ma = (n1 + n2*2 + n3*3 + me) / 7;

    printf("Média de aproveitamento: %.2f\n", ma);
    printf("Conceito: ");

    if(ma >= 9) {
        printf("A\n");
    } else if(ma >= 7.5) {
        printf("B\n");
    } else if(ma >= 6) {
        printf("C\n");
    } else if(ma >= 4) {
        printf("D\n");
    } else {
        printf("E\n");
    }

    return 0;
}

