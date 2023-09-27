#####################################################################
	    		DECLARAÇÕES INICIAIS	
#####################################################################

Considere este arquivo como o documento oficial referente ao trabalho proposto.
Contém todas as informações necessárias referente ao problema, solução e procedimentos.

- INTEGRANTES DO GRUPO:

Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201

- SUMÁRIO E CONTRIBUIÇÕES:
	- PROBLEMA IDENTIFICADO
	(Davi Rodrigues - Matheus Mendes - Vinícius Magno)

	- APRESENTAÇÃO DA SOLUÇÃO
	(Davi Rodrigues - Matheus Mendes - Vinícius Magno)

	- IMPLANTAÇÃO DA SOLUÇÃO
	(Davi Rodrigues + Vinícius Magno)

	- COMPILAÇÃO DO CÓDIGO PELO GCC
	(Matheus Mendes - Vinícius Magno)

	- PRINTS DE EXECUÇÃO + ENVIO
	(Davi Rodrigues - Matheus Mendes)

#####################################################################
	    PROBLEMA IDENTIFICADO - CORRIDA/CONCORRÊNCIA
#####################################################################

A execução simultânea de um processo por múltiplas threads que compartilham os mesmos recursos pode ocasionar na condição de corrida, resultando em inconsistências e possíveis falhas do programa. 

Para resolver esses problemas, é necessário coordenar/direcionar as threads e utilizar mecanismos de sincronização. Além disso, é crucial identificar e proteger as seções de operações críticas do código. Esses desafios não se limitam a programas com múltiplas threads, mas também podem ocorrer em ambientes distribuídos ou paralelos.

- IDENTIFICAÇÃO DO PROBLEMA:

Foi identificado no código original que multiplas threads podiam acessar e fazer modificações simultâneas nas contas, gerando inconsistência nos resultados quando o código era executado, ocasionando em diferentes possibilidades de saídas que na maioria, são incorretas.

No caso, quando executado no AWS, os resultados foram dentro do esperado, entretanto o programa precisou ser encerrado de forma manual, pois devido a condição de corrida logo após a realização da transferência, houve um problema na liberação de memória da stack.

Quando executado em outros compiladores, notou-se divergência nos resultados assim como a liberação de memória foi variada forçando a também encerrar o programa de forma manual.

#####################################################################
			APRESENTAÇÃO DA SOLUÇÃO
#####################################################################

- SOLUÇÃO PROPOSTA:
 
Considerando as aulas, conceitos de processos, threads e escalonadores, a melhor solução identificada pelo grupo foi a de adição do MUTEX, uma técnica de sincronização que garante a exclusão mútua de acesso à recursos compartilhados em um cenário com multiplas threads.

Foram feitas alterações no código original a fim de adicionar este método, tais como a adição da biblioteca <ptrehad.h>, prosseguindo com adições de variáveis tais como "transfer_mutex", garantindo que apenas uma thread execute a transferência, excluindo qualquer outra thread que esteja tentando acessar simultâneamente essa operação gerando a condição de corrida.

#####################################################################
			IMPLANTAÇÃO DA SOLUÇÃO:
#####################################################################

- Primeiramente, é adicionado no código a biblioteca <pthread.h>

- Antes da realização de qualquer operação, o mutex é inicializado:
"pthread_mutex_init(&transfer_mutex, NULL)"

- Durante o procedimento de tranferência, o mutex tenta ser adiquirido, se estiver disponível, prossegue com a operação crítica, caso contrário, a thread aguarda até que esteja liberado.
"pthread_mutex_lock(&transfer_mutex)"

- Após a aquisição do mutex, a thread prossegue completando a transferência (tarefa crítica) entre as contas from e to de uma maneira segura, pois apenas uma thread está em execução.

- Quando concluída a operação, mutex é liberado e então outra thread que estava em espera consegue acesso ao mutex para prosseguir com a execução do código.

#####################################################################
	    		COMPILAÇÃO DO CÓDIGO PELO GCC
#####################################################################

A compilação dos códigos foram feitas pelo GCC, primeiramente criando um arquivo .c e posteriormente fazendo a compilação usando o comando "gcc (nome do arquivo.c) -o (nome do arquivo executável)".

Para executar o programa no AWS, segue o seguinte comando:
	- ./(nome do arquivo executável) -> pressione enter

#####################################################################
	    		PRINTS DE EXECUÇÃO + ENVIO
#####################################################################

No repositório contém:
	- Prints de execução do código original 
	(Mostrando o problema e resultados incorretos)
	
	- Prints de execução do código solucionado 
	(Mostrando o código retornando com resultados corretos)
	
	- Programas compilados 
	(Código original, código com a solução aplicada)
	
	- Códigos fonte de programas 
	(arquivos .c)















