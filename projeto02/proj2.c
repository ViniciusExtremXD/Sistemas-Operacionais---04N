/*
Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201
*/

#include <stdio.h>
#include <string.h>

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

/*##################################################
    PROCESSANDO A ENTRADA FORNECIDA PELO USUÁRIO
####################################################*/
void ProcessarEntradaInterativa() {
    int N, i;
    int ultimoMomento = 0;
    N = InteiroValido("Digite o número de pessoas (N): ");

    for(i = 0; i < N; i++) {
        int e, d;
        printf("Digite o momento de chegada (e) e a direção (d) da pessoa %d (separados por espaço): ", i+1);
        scanf("%d %d", &e, &d);
        if (e + 10 > ultimoMomento) {
            ultimoMomento = e + 10;
        }
    }

    printf("O último momento em que a escada para é: %d\n", ultimoMomento);
}

/*#########################################################
      PROCESSANDO A ENTRADA A PARTIR DE UM ARQUIVO.TXT
###########################################################*/
void ProcessarEntradaArquivo(const char *nomeArquivo) {
    FILE *file;
    int N, i;
    int ultimoMomento = 0;

    file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(file, "%d", &N);

    for(i = 0; i < N; i++) {
        int e, d;
        fscanf(file, "%d %d", &e, &d);
        if (e + 10 > ultimoMomento) {
            ultimoMomento = e + 10;
        }
    }

    fclose(file);

    printf("O último momento em que a escada para é: %d\n", ultimoMomento);
}

/*############################################
            IMPLEMENTANDO O MAIN
#############################################*/
int main() {
    int escolha;
    char nomeArquivo[100];

    while (1) {
        printf("\nEscolha o método de entrada:\n");
        printf("\n1. Entrada interativa\n");
        printf("2. Ler de um arquivo\n");
        printf("3. Sair do programa\n");
        printf("\nDigite sua escolha (1, 2 ou 3): ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                ProcessarEntradaInterativa();
                break;
            case 2:
                printf("Digite o nome do arquivo: ");
                scanf("%s", nomeArquivo);
                ProcessarEntradaArquivo(nomeArquivo);
                break;
            case 3:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

