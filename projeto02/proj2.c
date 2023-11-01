#include <stdio.h>

/*############################################
            VERIFICANDO ENTRADA
#############################################*/
int InteiroValido(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            return value;
        } else {
            printf("\nEntrada inválida. Por favor, digite um número inteiro.\n");
            while (getchar() != '\n');
        }
    }
}

/*############################################
            IMPLEMENTANDO O MAIN
#############################################*/
int main() {
    int N, i;
    // Último momento em que a escada rolante está ocupada
    int ultimoMomento = 0;

    // Obtendo o número de pessoas
    N = InteiroValido("Digite o número de pessoas (N): ");

    for(i = 0; i < N; i++) {
        int e, d;
        // Obtendo o momento de chegada e a direção para cada pessoa
        char prompt[100];
        sprintf(prompt, "Digite o momento de chegada (e) e a direção (d) da pessoa %d (separados por espaço): ", i+1);
        while (1) {
            printf("%s", prompt);
            if (scanf("%d %d", &e, &d) == 2) {
                break;
            } else {
                printf("Entrada inválida. Por favor, digite dois números inteiros separados por espaço.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }
        // Adicionando 10 segundos ao momento de chegada (tempo para atravessar a escada)
        ultimoMomento = e + 10;
    }

    // Imprimindo o último momento em que a escada para
    printf("\nO último momento em que a escada para é: %d\n", ultimoMomento);

    return 0;
}

