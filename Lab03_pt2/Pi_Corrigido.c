#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*###################################################################
			DEFININDO O MUTEX E VARIÁVEIS 	
####################################################################*/
double sum = 0.0; // Soma global da função
pthread_mutex_t sum_mutex; // Mutex para proteger a soma global

typedef struct {
    long rank;
    long long n;
    int num_threads;
} ThreadData;

/*###################################################################
		   IMPLEMENTANDO O MUTEX NA FUNÇÃO	
####################################################################*/
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

    pthread_mutex_lock(&sum_mutex); // Mutex na parte crítica
    sum += my_sum;
    pthread_mutex_unlock(&sum_mutex);

    return NULL;
}

/*###################################################################
		    EXECUTANDO O MUTEX NO MAIN	
####################################################################*/
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Uso: %s <numero de threads> <numero de termos>\n", argv[0]);
        exit(1);
    }

    int num_threads = atoi(argv[1]);
    long long n = atoll(argv[2]);
    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    ThreadData* thread_data = malloc(num_threads * sizeof(ThreadData));

    pthread_mutex_init(&sum_mutex, NULL); // Aplicando o Mutex antes de executar a parte crítica

    for (long i = 0; i < num_threads; i++) { // Criando as threads
        thread_data[i].rank = i; // Atribuindo um identificador único (rank) para cada thread
        thread_data[i].n = n; // Passando o número total de termos da série
        thread_data[i].num_threads = num_threads; // Passando número total de threads
        pthread_create(&threads[i], NULL, Thread_sum, &thread_data[i]); // Criando a thread
    }

    for (int i = 0; i < num_threads; i++) { // Aguardando a conclusão das threads
        pthread_join(threads[i], NULL);
    }

    printf("\nQuantidade de threads: %d\n", num_threads);
    printf("Valor de pi calculado: %f\n", 4.0 * sum);

    free(threads); // Liberando as threads
    free(thread_data); // Liberando dados das threads
    pthread_mutex_destroy(&sum_mutex); // Destruindo o mutex
    return 0;
}

