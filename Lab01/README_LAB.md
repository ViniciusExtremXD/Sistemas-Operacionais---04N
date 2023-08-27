#################################################
PASSO A PASSO DE COMO CRIAR UM HELLO WORLD EM C +
ENVIANDO PARA O GIT HUB! (Primeiro Commit)
#################################################

## CONEXÃO VIA  SSH AO EC2 ##
- Abra o terminal.
- Digite o seguinte comando para se conectar ao servidor via SSH:

ssh -i ~/.ssh/labsuser.pem ec2-user@(ip instancia ec2)


## CLONANDO UM REPOSITÓRIO VIA SSH E FAZENDO UM COMMIT ##
- Gere uma chave SSH com o comando ssh-keygen
- Exiba a chave pública gerada com o comando cat /home/ec2-user/.ssh/id_rsa.pub. Copie a chave pública exibida.

## INDO PARA O GIT HUB ##
- Vá para o repositório no GitHub, clique em 'Settings', depois em 'Deploy keys' (aba Security), e finalmente em 'Add deploy key'. Cole a chave pública copiada.
- Ainda no GitHub, clique em 'Code', depois em 'clone', e em seguida em 'ssh'. Copie a chave exibida.

## VOTLANDO AO BASH ##
- Volte para o terminal e digite git clone + link do repositório
- Entre no diretório clonado com cd [nome do diretório].

## CRIANDO O CÓDIGO ##
- Crie um arquivo C com vi teste.c e escreva seu código.
- Compile e execute o código com gcc teste.c -o teste e ./teste.

## ENVIANDO PARA O GITHUB ##
- Adicione as alterações ao Git com git add teste.c.
- Faça um commit das alterações com git commit -m "first commit".

