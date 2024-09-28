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
- Função **forca**: atualiza a interface do jogo a cada erro de letra que o usuário comete.
- Função **main**: controla o fluxo principal do jogo, apresentando o menu inicial, gerenciando as tentativas, e exibindo o resultado final. As tentativas erradas são visualizadas com uma representação gráfica do enforcado.
### palavras.txt
- A primeira linha contém o número total de temas
- Cada tema é seguido pela quantidade de palavras e a lista das palavras associadas ao tema.
## Requisitos de Software
### Funcionalidades Implementadas
- Escolha de palavras aleatórias com base em um tema.
- Interface de usuário para adivinhar letras e ver o progresso da palavra.
- Sistema de tentativas com representação visual de enforcamento.
### Requisitos funcionais
- O sistema deve permitir que o usuário escolha entre uma palavra aleatória e uma palavra específica.
- O jogador deve ver o progresso de suas tentativas e as letras já digitadas.
- O enforcado deve ser exibido após erros, indicando o número de tentativas restantes.
### Requisitos não funcionais
- O jogo deve ser eficiente e rodar sem travamentos.
- O código deve ser portável, compilável em diferentes sistemas operacionais que suportem a linguagem de programação C.
- A interface deve ser simples e intuitiva para garantir uma boa experiência de usuário.
### Requisitos técnicos
- Linguagem: C
### Bibliotecas Padrões
- stdio.h: Para entrada e saída de dados.
- stdlib.h: Para funções auxiliares, como geração de números aleatórios e alocação de memória.
- string.h: Para manipulação de strings.
- ctype.h: Para manipulação de caracteres (como converter para maiúsculas).
- time.h: Para manipular o tempo, como gerar uma semente para números aleatórios baseada no tempo atual.
### Ambiente de Desenvolvimento
- Versão do compilador: gcc ou equivalente.
### Sistema de Execução
- O projeto é compatível com os sistemas operacionais Linux ou Windows.
### Análise e Design de Software
- O design do sistema foi realizado de forma modular, separando funções como a escolha da palavra e o gerenciamento de tentativas, o que facilita a manutenção e a extensão do código.
- O projeto utiliza uma abordagem estruturada, onde cada função tem responsabilidades claras, garantindo que o fluxo do jogo seja fácil de seguir e testar.
### Teste de Software
- Foram realizados **testes de unidade** nas funções principais para garantir que a escolha de palavras e o controle das tentativas funcionem corretamente.
- Testes de integração foram feitos para validar o fluxo completo do jogo, desde a escolha da palavra até a visualização do boneco enforcado e o resultado final.
- O sistema foi validado através de testes de caixa preta, onde o foco foi verificar se o jogo atende aos requisitos funcionais sem observar o código.
## Como Executar o Projeto
1. Certifique-se de ter um compilador C instalado (como GCC).
2. Compile o código usando o comando: gcc -o forca main.c
3. Execute o programa com o comando: ./forca
4. Sigas as instruções no terminal para jogar
## Requisitos técnicos
- Compilador C: GCC ou equivalente
- Arquivo de palavras: Certifique-se de que o arquivo **palavras.txt** esteja no mesmo diretório que o executável.
## Contribuição e Colaboração
Este projeto foi desenvolvido em colaboração entre Blendhon Pontini Delfino, Caio Pessini Dias e Rafael Pereira Oliveira. O código foi versionado utilizando o GitHub, e as contribuições foram gerenciadas através de commits e pull requests para facilitar a colaboração.
## Considerações Finais
Este trabalho proporcionou uma prática no uso de controle de versão e na documentação de projetos de software, essenciais em ambientes de desenvolvimento colaborativos. Aprendemos a importância de commits frequentes e documentados, bem como a organização do repositório para facilitar a navegação e manutenção do código.
