//14. Faça uma rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.

#include <stdio.h>
#include <string.h>

void inserir_caracter(char *str, int pos, char c) {
    int len = strlen(str);
    for(int i = len; i >= pos; i--) {
        str[i+1] = str[i];
    }
    str[pos] = c;
}

int main() {
    char str[100], c;
    int pos;

    printf("\nDigite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0'; // remove o '\n' do final

    printf("\nDigite a posição onde deseja inserir o caracter:\n(considere a primeira posição como 1.) ");
    scanf("%d", &pos);
    pos--; // ajusta o índice para começar de 0

    printf("\nDigite o caracter que deseja inserir: ");
    scanf(" %c", &c); // espaço antes de %c para ignorar o '\n' anterior

    if(pos >= 0 && pos <= strlen(str)) {
        inserir_caracter(str, pos, c);
        printf("\nString após a inserção do caracter: %s\n", str);
    } else {
        printf("\nPosição inválida.\n");
    }

    return 0;
}


