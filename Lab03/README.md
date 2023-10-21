Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201

#####################################################################################
				PROBLEMA IDENTIFICADO
#####################################################################################

O código inicial apresentado tem como objetivo executar a multiplicação matriz-vetor, mas contém alguns erros, fora que não estava completo. 

Foram feitas as correções para que a multiplicação matriz-vetor fosse realizada corretamente além de que uma função main foi adicionada para coletar as entradas do usuário, gerenciar a criação de threads e exibir o resultado.

O código também foi otimizado para distribuir as linhas da matriz entre as threads de forma mais equilibrada, considerando possíveis restos na divisão, neste caso, a distribuição de tarefas para as threads é feita pelo próprio programa, não pelo sistema operacional. 

- A função Pth_mat_vect determina quais linhas da matriz uma thread específica deve processar com base no rank da thread. 

- O cálculo my_first_row e my_last_row define o intervalo de linhas que cada thread deve processar. 

- O sistema operacional é responsável por gerenciar e agendar a execução das threads, mas a lógica de divisão do trabalho é definida pelo programa.

#####################################################################################
				COMPILAÇÃO DO CÓDIGO
#####################################################################################

Para compilar o programa MatrizVetor.c, utilizamos o compilador gcc com as seguintes flags:

gcc -g -Wall -o MatrizVetor MatrizVetor.c -lpthread

Para executar o programa, basta fornecer o número de threads como argumento:

./MatrizVetor (número de threads)


#####################################################################################
	SEGUEM AS PRINTS MOSTRANDO A COMPILAÇÃO/ EXECUÇÃO DO CÓDIGO
#####################################################################################
