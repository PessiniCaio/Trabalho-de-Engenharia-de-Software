## Introdução
Este projeto implementa um jogo da forca em C, onde o jogador pode escolher entre uma palavra aleatória de um arquivo ou uma palavra escolhida pelo próprio jogador. O jogo utiliza temas e palavras predefinidos e permite que o usuário jogue adivinhando as letras até acertar ou perder.
## Estrutura do Projeto
O projeto é composto pelos seguintes arquivos:
- **main.c**: contém a lógica principal do jogo, incluindo as funções para seleção de palavras, gerenciamento das tentativas, e interação com o usuário.
- **palavras.txt**: arquivo contendo os temas e palavras utilizadas no jogo. As palavras estão categorizadas em diferentes temas.
## Descrição dos Arquivos
### main.c
- Função **palavras_chave_usu**: define um tema e uma palavra pré-determinada escolhida pelo usuário para o jogo.
- Função **palavra_chave_pre**: escolhe aleatoriamente um tema e uma palavra de um arquivo externo **(palavras.txt)**. A escolha é feita através de números aleatórios baseados na quantidade de temas e palavras disponíveis.
- Função **main**: controla o fluxo principal do jogo, apresentando o menu inicial, gerenciando as tentativas, e exibindo o resultado final. As tentativas erradas são visualizadas com uma representação gráfica do enforcado.
### palavras.txt
- A primeira linha contém o número total de temas
- Cada tema é seguido pela quantidade de palavras e a lista das palavras associadas ao tema.
## Funcionalidades Implementadas
- Escolha de palavras aleatórias com base em um tema.
- Interface de usuário para adivinhar letras e ver o progresso da palavra.
- Sistema de tentativas com representação visual de enforcamento.
## Como Executar o Projeto
1. Certifique-se de ter um compilador C instalado (como GCC).
2. Compile o código usando o comando: gcc -o forca main.c
3. Execute o programa com o comando: ./forca
4. Sigas as instruções no terminal para jogar
## Requisitos
- Compilador C: GCC ou equivalente
- Arquivo de palavras: Certifique-se de que o arquivo **palavras.txt** esteja no mesmo diretório que o executável.
## Contribuição e Colaboração
Este projeto foi desenvolvido em colaboração entre Blendhon Pontini Delfino, Caio Pessini Dias e Rafael Pereira Oliveira. O código foi versionado utilizando o GitHub, e as contribuições foram gerenciadas através de issues e pull requests para facilitar a colaboração.
## Considerações Finais
Este trabalho proporcionou uma prática no uso de controle de versão e na documentação de projetos de software, essenciais em ambientes de desenvolvimento colaborativos. Aprendemos a importância de commits frequentes e documentados, bem como a organização do repositório para facilitar a navegação e manutenção do código.
