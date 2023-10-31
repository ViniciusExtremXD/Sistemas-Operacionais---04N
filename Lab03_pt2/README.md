#######################################################
		     PROBLEMA ORIGINAL
#######################################################

Além do possível problema de corrida do código original, outros pequenos problemas como a falta de inicialização de variávies, como "my_first_i" foram corrigidos.

#######################################################
	  CÓDIGO CORRIGIDO E IMPLEMENTAÇÕES 
#######################################################

No código corrigido foi implementado o Mutex justamente para sanar a condição de corrida que o código possivelmente pode apresentar, podendo ser encontrado nas variávies pthread_mutex_t e sum_mutex.

Dando sequência, para a sincronização, as funções pthread_mutex_lock e pthread_mutex_unlock são utilizadas para bloquear e desbloquear o mutex, protegendo a seção crítica do código.

Por fim, tanto no código original foi implementado um log retornando a quantidade de threads que o código executou assim como o valor obtido pela função.

#######################################################
	DIFERENÇA ENTRE OS VALORES ANTINGIDOS
#######################################################

O principal motivo pelo qual houve divergência de valores entre os dois códigos é justamente a condição de corrida que pode ocorrer no código original, assim que acontece em alguma das threads, o resultado final é diretamente afetado representando inconstância e instabilidade do mesmo.

**Observação:
Dependendo da quantidade de termos colocado para executar na função o resultado também pode ser variado entre as funções, e no caso da divergência de resultados de acordo com o número de termos do código corrigido se deve pelo fato da precisão da função Thread_sum, não sendo necessariamente um erro.

#######################################################
	  COMPILAÇÃO E EXECUÇÃO DOS CÓDIGOS
#######################################################

- Ambos os códigos foram compilados pelo GCC do seguinte modo:
gcc -o <nome do programa> <nome do arquivo .c> -lpthread

- Ambos os códigos podem ser executados da seguinte forma:
./<nome do programa> <n° de threads> <n° de termos>

por exemplo:
./Pi_Original 5 10000

SEGUEM PRINTS DE COMPILAÇÃO E EXECUÇÃO NO AWS.


























