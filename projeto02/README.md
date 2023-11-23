Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201

############################################
	IMPLEMENTAÇÃO DO CÓDIGO
############################################

O código fornece para o usuário um meu permitindo a realização do cálculo a partir de um arquivo ou de forma iterativa. Para sair do menu, deve inserir a opção 3, sair.

Em seguida, para cada pessoa, o código solicita o momento de chegada (e) e a direção (d) desejada. A direção (d) é lida, mas não afeta o resultado final, pois o tempo para atravessar a escada é o mesmo em ambas as direções.
O código verifica se a entrada para e e d é válida, similar à verificação feita para N.

Por fim, o código então calcula o ultimoMomento, que é o último momento em que a escada rolante está ocupada. Para isso, ele adiciona 10 segundos (tempo para atravessar a escada) ao momento de chegada de cada pessoa. 

A saída retorna para o usuário o último momento que a escada rolante para.

############################################
      COMPILAÇÃO E EXECUÇÃO DO CÓDIGO
############################################

O código foi compilado pelo AWS usando o GCC pelo seguinte comando:

"gcc proj2.c -o proj2" - (está demonstrado na print)

E o programa pode ser executado do seguinte modo:

"./proj2"

PARA A OPÇÃO 2, A ENTRADA DO ARQUIVO PODE SER FEITA DA SEGUINTE FORMA:

"input/<nome arquivo>" - (não precisa necessáriamente da extensão)

Exemplo:
input/E_1

#################################
	LÓGICA DO CÓDIGO
#################################

O código-fonte é dividido em três partes principais:

- VERIFICANDO A ENTRADA: 
A função InteiroValido é usada para garantir que as entradas sejam números inteiros válidos.

- PROCESSANDO A ENTRADA ITERATIVA: 
A função ProcessarEntradaInterativa permite ao usuário inserir os detalhes das pessoas interativamente e calcula o último momento em que a escada para.

- PROCESSANDO A ENTRADA PELO ARQUIVO: 
A função ProcessarEntradaArquivo lê as informações de um arquivo de texto e calcula o último momento em que a escada para.

#################################
	LÓGICA DO CÁLCULO
#################################

Foi discutido em grupo e elaborada a seguinte solução:

- A escada rolante leva 10 segundos para transportar uma pessoa de uma extremidade à outra.
- Se uma pessoa entrar na escada no momento T, ela sairá no momento T + 10.
- Nenhuma pessoa chega exatamente quando a escada está prestes a parar.

Logo, recebe-se o número de pessoas (N) e as informações de chegada e direção de cada pessoa.

Para cada pessoa, o código calcula o momento em que a escada para com base no momento de chegada da pessoa (t_i).

O momento em que a escada para, é calculado adicionando 10 segundos ao momento de chegada da pessoa. 
(O código mantém o controle do maior momento de parada encontrado até agora)

O resultado é o último momento em que a escada para, que é o maior momento de parada encontrado durante o processamento das informações das pessoas.

Finalmente, o resultado é impresso, mostrando o último momento em que a escada para.

#################################
            CONCLUSÃO
#################################

Mesmo colocando no papel, revendo o enunciado diversas vezes, buscando soluções com diversas ferramentas, nem todos os resultados
puderam ser obtidos.

Alguns resultados do programa não são coerentes com o output fornecido para testes. Analisamos diversas abordagens, formas de acompanhar o estado da escada rolante, a abordagem adotada foi a que tivemos melhor resultado.


