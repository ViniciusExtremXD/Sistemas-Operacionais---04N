#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100000

typedef struct {
    int arrivalTime;
    int direction;
} Person;

// Função para simular a escada rolante
int simulateEscalator(Person persons[], int n) {
    int leftExitTime = 0;
    int rightExitTime = 0;

    for (int i = 0; i < n; i++) {
        if (persons[i].direction == 0) {
            // Pessoa quer ir da esquerda para a direita
            if (persons[i].arrivalTime >= leftExitTime) {
                leftExitTime = persons[i].arrivalTime + 10;
            } else {
                leftExitTime += 10;
            }
        } else {
            // Pessoa quer ir da direita para a esquerda
            if (persons[i].arrivalTime >= rightExitTime) {
                rightExitTime = persons[i].arrivalTime + 10;
            } else {
                rightExitTime += 10;
            }
        }
    }

    // O tempo final será o máximo entre as saídas das duas direções
    return leftExitTime > rightExitTime ? leftExitTime : rightExitTime;
}

int main() {
    int n;
    Person persons[MAX_USERS];

    printf("Digite o número de usuários (1-100000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_USERS) {
        printf("Número inválido de usuários. Por favor, insira um número entre 1 e 100000.\n");
        return EXIT_FAILURE;
    }

    printf("Digite os tempos de chegada e direções (0 para esquerda, 1 para direita) para cada usuário:\n");
    for (int i = 0; i < n; i++) {
        printf("Usuário %d: ", i + 1);
        if (scanf("%d %d", &persons[i].arrivalTime, &persons[i].direction) != 2 ||
            persons[i].arrivalTime < 1 || persons[i].direction < 0 || persons[i].direction > 1) {
            printf("Entrada inválida. Por favor, insira um tempo positivo e 0 ou 1 para a direção.\n");
            return EXIT_FAILURE;
        }
    }

    int lastTime = simulateEscalator(persons, n);
    printf("A última pessoa sairá da escada rolante no tempo: %d\n", lastTime);

    return EXIT_SUCCESS;
}

