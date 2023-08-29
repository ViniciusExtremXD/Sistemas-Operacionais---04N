//12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.

#include <stdio.h>
#include <string.h>

int encontrar_caracter(char *str, char c) {
    char *p = strchr(str, c);
    if (p) {
        return p - str + 1;
    } else {
        return -1;
    }
}

int main() {
    char str[100], c;
    int pos;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0'; // remove o '\n' do final

    printf("\nDigite um caracter: ");
    scanf("%c", &c);

    pos = encontrar_caracter(str, c);

    if (pos >= 0) {
        printf("\nO caracter '%c' foi encontrado na posição %d.\n", c, pos);
    } else {
        printf("\nO caracter '%c' não foi encontrado na string.\n", c);
    }

    return 0;
}

