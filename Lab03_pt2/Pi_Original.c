/*###########################################################
			CÓDIGO ORIGINAL
		      IMPLEMENTANDO O MAIN
#############################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double sum = 0.0; // Soma global da função

typedef struct {
    long rank;
    long long n;
    int num_threads;
} ThreadData;

void *Thread_sum(void *arg) {
    ThreadData* data = (ThreadData*) arg;
    double my_sum = 0.0;
    double factor;
    long rank = data->rank;
    long long n = data->n;
    long long chunk_size = n / data->num_threads;
    long long my_first_i = rank * chunk_size;
    long long my_last_i = (rank + 1) * chunk_size;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (long long i = my_first_i; i < my_last_i; i++, factor = -factor)
        my_sum += factor / (2 * i + 1);

    sum += my_sum; // Sem mutex, pode ocorrer condição de corrida

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Uso: %s <numero de threads> <numero de termos>\n", argv[0]);
        exit(1);
    }

    int num_threads = atoi(argv[1]);
    long long n = atoll(argv[2]);
    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    ThreadData* thread_data = malloc(num_threads * sizeof(ThreadData));

    for (long i = 0; i < num_threads; i++) {
        thread_data[i].rank = i;
        thread_data[i].n = n;
        thread_data[i].num_threads = num_threads;
        pthread_create(&threads[i], NULL, Thread_sum, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nQuantidade de threads: %d\n", num_threads);
    printf("Valor de pi calculado: %f\n", 4.0 * sum);

    free(threads);
    free(thread_data);
    return 0;
}

