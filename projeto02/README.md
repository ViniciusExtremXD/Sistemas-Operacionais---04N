############################################
	IMPLEMENTAÇÃO DO CÓDIGO
############################################

O código principal (main) começa solicitando ao usuário o número de pessoas (N) que usarão a escada rolante, utilizando a função InteiroValido.

Em seguida, para cada pessoa, o código solicita o momento de chegada (e) e a direção (d) desejada. A direção (d) é lida, mas não afeta o resultado final, pois o tempo para atravessar a escada é o mesmo em ambas as direções.
O código verifica se a entrada para e e d é válida, similar à verificação feita para N.

Por fim, o código então calcula o ultimoMomento, que é o último momento em que a escada rolante está ocupada. Para isso, ele adiciona 10 segundos (tempo para atravessar a escada) ao momento de chegada de cada pessoa. 

A saída retorna para o usuário o último momento que a escada rolante para.

############################################
      COMPILAÇÃO E EXECUÇÃO DO CÓDIGO
############################################

O código foi compilado pelo AWS usando o GCC pelo seguinte comando:

"gcc proj2.c -o proj2"

E o programa pode ser executado do seguinte modo:

"./proj2"






















