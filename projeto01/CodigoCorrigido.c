#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h> // Inclusão da biblioteca pthread

// 64kB stack
#define FIBER_STACK 1024*64

struct c {
    int saldo;
};

typedef struct c conta;

conta from, to;
int valor;

// Variável para controlar o acesso concorrente
pthread_mutex_t transfer_mutex; // Declaração do mutex

// The child thread will execute this function
int transferencia(void *arg) {
    // Bloco de código que adquire o mutex para acessar a seção crítica
    pthread_mutex_lock(&transfer_mutex); // Aquisição do mutex
    
    // Seção crítica: transferência de fundos entre as contas
    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
    }
    
    printf("Transferência concluída com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);

    // Liberação do mutex para permitir que outras threads possam acessar a seção crítica
    pthread_mutex_unlock(&transfer_mutex); // Liberação do mutex

    return 0;
}

int main() {
    void* stack;
    pid_t pid;
    int i;

    // Inicialização do mutex
    pthread_mutex_init(&transfer_mutex, NULL);

    stack = malloc(FIBER_STACK);
    if (stack == 0) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    from.saldo = 100;
    to.saldo = 100;
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < 10; i++) {
        pid = clone(&transferencia, (char*)stack + FIBER_STACK,
                    SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
        if (pid == -1) {
            perror("clone");
            exit(2);
        }
    }

    for (i = 0; i < 10; i++) {
        wait(NULL);  // Espera todos os processos filhos terminarem
    }

    // Destruição do mutex
    pthread_mutex_destroy(&transfer_mutex);

    // Free the stack
    free(stack);
    printf("Transferências concluídas e memória liberada.\n");

    return 0;
}

