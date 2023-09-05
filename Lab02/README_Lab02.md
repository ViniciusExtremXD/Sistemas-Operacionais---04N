###########################################################
		     RELATÓRIO DO LAB 02 
###########################################################

Instruções de Uso:
(Contém Prints de execução)
- Programas disponíveis:
	- processos_stderr
	- processos_print

- Podem ser executados a partir de "./(programa)"
exemplo: ./processos_stderr


#############################################
	ENUNCIADOS DOS EXS + RESPOSTA
#############################################

1) Rode o programa anterior para valores grandes de n. As
mensagens sempre estarão ordenadas pelo valor de i?

R: Não necessariamente, pois pode variar de uma execução para outra tendo em vista que os processos são executados de forma assíncrona e o Sistema Operacional por sua vez pode alternar entre eles a qualquer instante, fazendo com que mesmo que os valores de "n" sejam grandes, não sejam exatamente ordenadas pelo valor de i.
Contudo, nos testes feitos não foram verificados "saltos" na hora de exibir os processos (pelo menos no terminal do AWS).

2) O que acontece se o programa anterior escreve-se as mensagens
para sys.stdout, usando print, ao invés de para sys.stderr?

R: A funcionalidade do programa continua sendo a mesma, imprimindo os processos de acordo com o gerenciamento do SO. A única diferença é o local onde as mensagens são impressas.

################################
	   OBSERVAÇÕES
################################

- Foi feita uma alteração no código para que não precisasse ser compilado varias vezes sem necessidade.
A alteração consiste que o valor de "n" seja fornecido pelo usuário e não alterado no parâmetro do código fonte.








