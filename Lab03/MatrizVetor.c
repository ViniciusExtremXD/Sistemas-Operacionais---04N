/*
Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/*#####################################################################
                    DECLARAÇÃO DE VARIÁVEIS GLOBAIS
#####################################################################*/
int m, n, thread_count;
double **A, *x, *y;

/*#####################################################################
                    FUNÇÃO DE MULTIPLICAÇÃO MATRIZ-VETOR
#####################################################################*/
void* Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = m/thread_count;
    int remainder = m % thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = my_first_row + local_m;

    if (my_rank < remainder) {
        my_first_row += my_rank;
        my_last_row += my_rank + 1;
    } else {
        my_first_row += remainder;
        my_last_row += remainder;
    }

    for(i = my_first_row; i < my_last_row; i++) {
        y[i] = 0.0;
        for(j = 0; j < n; j++)
            y[i] += A[i][j] * x[j];
    }
    return NULL;
}
/*#####################################################################
                    FUNÇÃO PRINCIPAL (MAIN)
#####################################################################*/
int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;

/*#####################################################################
                VERIFICAÇÃO DE ARGUMENTOS E LEITURA DE THREADS
#####################################################################*/
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <número de threads>\n", argv[0]);
        exit(1);
    }
    thread_count = strtol(argv[1], NULL, 10);

/*#####################################################################
                 LEITURA DE DIMENSÕES DA MATRIZ E VETOR
#####################################################################*/ 
    printf("\nDigite o número de linhas m: ");
    scanf("%d", &m);
    printf("\nDigite o número de colunas n: ");
    scanf("%d", &n);

/*#####################################################################
               ALOCAÇÃO E LEITURA DA MATRIZ E VETOR
#####################################################################*/ 
    A = malloc(m * sizeof(double *));
    for(int i = 0; i < m; i++) {
        A[i] = malloc(n * sizeof(double));
        printf("\nDigite os %d valores da linha %d da matriz A: ", n, i+1);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    x = malloc(n * sizeof(double));
    printf("\nDigite os %d valores do vetor x: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    y = malloc(m * sizeof(double));
    thread_handles = malloc(thread_count * sizeof(pthread_t));

/*#####################################################################
                 CRIAÇÃO E SINCRONIZAÇÃO DAS THREADS
#####################################################################*/ 
    for(thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    for(thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    printf("\nResultado do produto matriz-vetor:\n");
    for(int i = 0; i < m; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

/*#####################################################################
                  LIBERAÇÃO DE MEMÓRIA ALOCADA
#####################################################################*/ 
    for(int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(y);
    free(thread_handles);

    return 0;
}

