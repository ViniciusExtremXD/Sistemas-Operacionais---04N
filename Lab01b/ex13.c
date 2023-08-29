//13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

#include <stdio.h>
#include <string.h>

void remover_caracter(char *str, int pos) {
    int i;
    for(i = pos; i < strlen(str); i++) {
        str[i] = str[i+1];
    }
}

int main() {
    char str[100];
    int pos;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // remove o '\n' do final

    printf("Digite a posição do caracter que deseja remover: \n(Considere a posição inicial como 1) ");
    scanf("%d", &pos);
    pos--; // ajusta o índice para começar de 0

    if(pos >= 0 && pos < strlen(str)) {
        remover_caracter(str, pos);
        printf("\nString após a remoção do caracter: %s\n", str);
    } else {
        printf("\nPosição inválida.\n");
    }

    return 0;
}


