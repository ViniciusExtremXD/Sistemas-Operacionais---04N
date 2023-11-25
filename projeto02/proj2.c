/*
Davi Rodrigues - 32266960 
Matheus Mendes - 32261527 
Vinícius Magno - 32223201
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int tempoChegada;
  int direcao;
} Usuario;

/*##################################################
      CALCULO PRINCIPAL PARA O USO DA ESCADA
##################################################*/
void processarUsoEscada(int qtdUsuarios, Usuario usuarios[]) {
  // Inicialização das variáveis
  int tempoFinal = usuarios[0].tempoChegada + 10, flagEspera = 0, direcaoAtual = usuarios[0].direcao;

  // Loop principal para processar o uso da escada
  for (int i = 1; i < qtdUsuarios; i++) {
    if (usuarios[i].tempoChegada <= tempoFinal) {
      if (usuarios[i].direcao == direcaoAtual) {
        tempoFinal = usuarios[i].tempoChegada + 10;
      } else {
        flagEspera = 1;
      }

      // Usuário conseguiu usar a escada imediatamente
    } else {
      if (flagEspera) {
        tempoFinal += 10;
        direcaoAtual = !direcaoAtual;
        i--;

        // Houve espera e a direção da escada mudou
      } else {
        tempoFinal = usuarios[i].tempoChegada + 10;
        direcaoAtual = usuarios[i].direcao;
      }
      flagEspera = 0;
    }
  }

  // Tratamento final para garantir que a escada esteja livre
  if (flagEspera) {
    tempoFinal += 10;
  }

  // Retornando para o usuário o último momento da escada
  printf("\nÚltimo momento da escada: %d\n", tempoFinal);
}

/*##################################################
      PROCESSANDO A ENTRADA DE FORMA ITERATIVA
##################################################*/
void entradaInterativa() {
  // Obtém o número de usuários
  int numUsuarios;
  printf("Digite o número de usuários: ");
  if (scanf("%d", &numUsuarios) != 1) {
    printf("Insira um valor válido.\n");

    // Limpa o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return;
  }

  // Verifica se o número de usuários é válido
  if (numUsuarios <= 0) {
    printf("Insira um valor válido.\n");
    return;
  }

  Usuario usuarios[numUsuarios];

  // Coleta os dados dos usuários
  for (int i = 0; i < numUsuarios; i++) {
    printf("Digite o tempo de chegada e a direção para o usuário %d: ", i + 1);
    if (scanf("%d %d", &usuarios[i].tempoChegada, &usuarios[i].direcao) != 2) {
      printf("Entrada inválida. Voltando para o menu principal.\n");

      // Limpa o buffer de entrada
      int c;
      while ((c = getchar()) != '\n' && c != EOF);

      return;
    }
  }

  // Chama a função de processamento da escada
  processarUsoEscada(numUsuarios, usuarios);
}

/*##################################################
     MÉTODO PARA PROCESSAR A PARTIR DO ARQUIVO    
##################################################*/
void entradaArquivo() {
  char nomeArquivo[100];
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);

  // Abre o arquivo especificado
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (!arquivo) {
    perror("Arquivo não encontrado!\n");
    return;
  }

  // Lê o número de usuários e seus dados do arquivo
  int numUsuarios;
  fscanf(arquivo, "%d", &numUsuarios);
  Usuario usuarios[numUsuarios];

  for (int i = 0; i < numUsuarios; i++) {
    fscanf(arquivo, "%d %d", &usuarios[i].tempoChegada, &usuarios[i].direcao);
  }
  fclose(arquivo);

  // Chama a função de processamento da escada
  processarUsoEscada(numUsuarios, usuarios);
}

/*##################################################
         IMPLEMENTANDO O MAIN + MENU
##################################################*/
int main() {
  int escolha = 0;
  while (1) {
    // Menu de seleção
    printf("\n##############################\nSelecione o método de entrada:\n1. Interativo\n2. Arquivo\n3. Sair\n##############################\n\nSua escolha: ");
    scanf("%d", &escolha);

    // Executa a ação com base na escolha do usuário
    if (escolha == 1) {
      entradaInterativa();
    } else if (escolha == 2) {
      entradaArquivo();
    } else if (escolha == 3) {
      printf("Encerrando o programa.\n");
      break;
    } else {
      printf("Opção inválida. Tente novamente.\n");

      // Limpa o buffer de entrada
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
    }
  }
  return 0;
}

