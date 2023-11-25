Davi Rodrigues - 32266960
Matheus Mendes - 32261527
Vinícius Magno - 32223201

############################################
        IMPLEMENTAÇÃO DO CÓDIGO
############################################

Este código implementa um programa que permite ao usuário calcular 
o último momento em que uma escada rolante estará ocupada. O programa 
oferece duas opções de entrada: iterativa e por arquivo. Para sair do menu, 
o usuário pode inserir a opção 3, "Sair".

ENTRADA DE DADOS: 
Os usuários podem inserir dados manualmente (modo iterativo) ou carregar de um arquivo. 
Cada entrada consiste no tempo de chegada (tempoChegada) e na direção desejada (direcao) do usuário da escada rolante. 
Notavelmente, a direção é registrada mas não influencia o cálculo, já que o tempo de travessia é idêntico em ambas as direções.

VERIFICAÇÃO DE VALDADE: 
O programa assegura que tanto o tempo de chegada quanto a direção sejam entradas válidas, 
seguindo o mesmo princípio de verificação aplicado ao número de usuários (N).

TEMPO FINAL DE USO: 
A lógica central do programa envolve adicionar 10 segundos ao tempo de chegada de cada usuário. 
A partir disso, o programa verifica as condições de uso da escada, determinando os momentos em que estará ocupada ou livre.

SAÍDA DO PROGRAMA: 
Após o processamento dos dados, o programa exibe o último momento em que a escada rolante estará ocupada.


#################################
        LÓGICA DO CÓDIGO
#################################

O código está organizado pelas seguintes partes: 

PROCESSAMENTO DA ESCADA - processarUsoEscada:
Ela recebe a quantidade de usuários e um array de estruturas Usuario, cada uma contendo o tempo de chegada e a direção do usuário. 
A função calcula o último momento em que a escada está ocupada, considerando seu tempo de uso e as mudanças de direção.

ENTRADA DE DADOS - entradaInterativa e entradaArquivo:
- Entrada Interativa: Permite que o usuário insira os tempos de chegada e as direções dos usuários de forma interativa. 
Faz a validação das entradas e, chama a função processarUsoEscada para calcular o tempo final de ocupação da escada.

- Entrada por Arquivo: Lê  o N° de pessoas, os tempos de chegada e as direções dos usuários a partir de um arquivo de texto. 
Posteriormente, também invoca a função processarUsoEscada para determinar o tempo final de ocupação da escada.


#################################
        LÓGICA DO CÁLCULO
#################################

A lógica do cálculo é baseada nas seguintes premissas:
Tempo de Travessia: A escada rolante leva 10 segundos para transportar uma pessoa de um lado ao outro.
Cálculo de Saída: Quando uma pessoa entra na escada no momentoT, ela completará a travessia no momento T+10 segundos.

CONTROLE DE FLUXO: 
- É considerado que novos usuários não chegam exatamente no momento em que a escada está prestes a ficar livre.
- A escada consegue acolher inúmeros usuários ("largura ilimitada", está descrito no usuário)

PROCESSAMENTO DE CADA USUÁRIO:
- Tempo de Ocupação: Para cada usuário, o programa adiciona 10 segundos ao tempo de chegada 
(tempoChegada) para calcular quando a escada estará ocupada.

GERENCIAMENTO DE DIREÇÕES: 
O código também gerencia a mudança de direção da escada e possíveis esperas, caso usuários com direções 
diferentes cheguem enquanto a escada ainda está ocupada.

CONTROLE DE ULTIMO MOMENTO: 
O código rastreia e atualiza o último momento em que a escada estará ocupada, considerando todos os usuários e as mudanças realizadas na direção da escada.

RESULTADO
Baseando-se no maior tempo de ocupação registrado durante o processamento de todos os usuários, é retornado para o usuário
o o último momento ocupado da escada rolante.


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
            CONCLUSÃO
#################################

Aplicando a lógica correta do gerenciamento das pessoas na escada rolante, 
foi possível atingir os resultados esperados.



