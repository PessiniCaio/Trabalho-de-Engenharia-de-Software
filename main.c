#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Função para definir um tema e uma palavra específica escolhida pelo usuário
void palavra_chave_usu(char *palavra, char *tema) {
   // Define o tema e a palavra
   strcpy(tema, "ComIda");
   strcpy(palavra, "maca");
   printf("\n");
}

// Função para escolher aleatoriamente uma palavra do arquivo e seu respectivo tema
void palavra_chave_pre(char *palavra, char *tema) {
   int num_temas; // Número de temas no arquivo
   char buffer[256]; // Buffer temporário para leitura de strings
   srand(time(NULL)); // Semente para gerar números aleatórios com base no tempo atual

   // Abre o arquivo de palavras
   FILE *arquivo = fopen("palavras.txt", "r");
   if (arquivo == NULL) {
      // Caso haja erro na abertura do arquivo, o programa termina com uma mensagem de erro
      perror("--------------------------------------------------\n\n"
         "Erro ao abrir o arquivo");
      exit(1);
   }

   // Lê a quantidade de temas presentes no arquivo
   fscanf(arquivo, "%d\n", &num_temas);

   // Escolhe um tema aleatório
   int tema_ale = rand() % num_temas;
   int tema_atual = 0; // Variável para controlar o tema atual durante a leitura
   int num_palavras; // Número de palavras de um tema específico

   // Lê o arquivo até encontrar o tema sorteado
   while (fscanf(arquivo, "%d %s\n", &num_palavras, tema) != EOF) {
      if (tema_atual == tema_ale) {
         // Sorteia uma palavra aleatória do tema selecionado
         int palavra_ale = rand() % num_palavras;
         int palavra_atual = 0; // Variável para controlar a palavra atual durante a leitura

         // Lê as palavras do tema até encontrar a sorteada
         while (fgets(buffer, sizeof(buffer), arquivo) != NULL && palavra_atual < num_palavras) {
            if (palavra_atual == palavra_ale) {
               // Remove o '\n' do final da string e copia a palavra sorteada
               buffer[strcspn(buffer, "\n")] = '\0';
               strcpy(palavra, buffer);
               break;
            }
            palavra_atual++; 
         }
         break;
      }

      // Pula as palavras do tema atual se o tema não for o sorteado
      for (int i = 0; i < num_palavras; i++) {
         fgets(buffer, sizeof(buffer), arquivo);
      }

      tema_atual++;
   }

   printf("\n");

   fclose(arquivo); // Fecha o arquivo após a leitura
}

void forca(int erros, char palavra[50]) {
   if (erros == 0)
      printf("_\n"
         "|   |   \n"
         "|       \n"
         "|       \n"
         "|       \n"
         "|_____  \n\n");
   else if (erros == 1)
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|       \n"
         "|       \n"
         "|_____  \n\n");
   else if (erros == 2)
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|  /    \n"
         "|       \n"
         "|_____  \n\n");
   else if (erros == 3)
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|  /|   \n"
         "|       \n"
         "|_____  \n\n");
   else if (erros == 4)
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|  /|\\ \n"
         "|       \n"
         "|_____  \n\n");
   else if (erros == 5)
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|  /|\\ \n"
         "|  /    \n"
         "|_____  \n\n");
   else if (erros >= 6) // Game over
      printf("_\n"
         "|   |   \n"
         "|   O   \n"
         "|  /|\\ \n"
         "|  / \\ \n"
         "|_____  \n\n"
         "Você foi enforcado!\n\n"
         "A palavra correta era: %s\n\n", palavra);
}

int main() { 
   char palavra[50], resposta[50], letras[50] = "", tema[50]; // Variáveis para armazenar a palavra, resposta, letras digitadas e o tema
   char letra; // Letra digitada pelo jogador
   int i = 0, found, tentativas = 0; // Variáveis para controle do jogo: índice, controle de acerto e tentativas

   while (1) {
      // Menu inicial para o jogador escolher entre palavra aleatória, palavra definida ou sair
      do {
         printf("-------------------------------------------------\n\n"
            "Digite 1 para jogar com a palavra chave aleatoria\n"
            "Digite 2 para jogar com a palavra escolhida\n"
            "Digite 3 para sair\nOpc: ");
         scanf("%d", &i);
         if (i == 1) {
            // Palavra aleatória do arquivo
            palavra_chave_pre(palavra, tema);
            break;
         }
         else if (i == 2) {
            // Palavra definida pelo usuário
            palavra_chave_usu(palavra, tema);
            break;
         }
         else if (i == 3) {
            // Sair do jogo
            exit(1);
         }
         else
            printf("Opção inválida\n\n");
      } while (i != 1 && i != 2 && i != 3);

      // Define o tamanho da palavra escolhida
      int palavra_length = strlen(palavra);

      // Inicializa a variável resposta com '_' para cada letra da palavra
      for (i = 0; i < palavra_length; i++) {
         if (palavra[i] == ' ') {
            resposta[i] = ' '; // Mantém espaços em branco
         } else {
            resposta[i] = ''; // Substitui letras por ''
         }
         // Coloca todas as letras da palavra em maiúsculas
         palavra[i] = toupper(palavra[i]);
      }
      resposta[palavra_length] = '\0'; // Termina a string resposta

      // Coloca o tema em maiúsculas
      for (i = 0; i < strlen(tema); i++) {
         tema[i] = toupper(tema[i]);
      }

      // Inicializa a string de letras digitadas como vazia
      strcpy(letras, "");

      // Loop do jogo até que o jogador adivinhe a palavra
      while (strcmp(palavra, resposta) != 0) {
         // Mostra o tema, letras já digitadas e a palavra (com os caracteres adivinhados)
         printf("TEMA: %s\n\n"
               "Letras digitadas: %s\n\n"
               "Palavra: ", tema, letras);
         for (i = 0; i < palavra_length; i++) {
            printf(" %c", resposta[i]);
         }
         printf("\n\nDigite uma letra: ");
         scanf(" %c", &letra);
         letra = toupper(letra); // Converte a letra para maiúscula

         // Verifica se a letra já foi digitada
         if (strchr(letras, letra) != NULL) {
            printf("\nVocê já digitou a letra %c. Tente outra.\n\n"
               "-------------------------------------------------\n\n", letra);
            forca(tentativas, palavra);
            continue; // Se a letra já foi digitada, solicita nova entrada
         }
                  
         strncat(letras, &letra, 1); // Adiciona a letra à lista de letras digitadas
         strncat(letras, " ", 1); // Adiciona um espaço para separar as letras digitadas
         printf("\n");
         
         found = 0; // Reseta a variável found para verificar se a letra foi encontrada na palavra
         for (i = 0; i < palavra_length; i++) {
            if (toupper(palavra[i]) == letra) {
               resposta[i] = letra; // Atualiza a resposta com a letra correta
               found = 1; // Marca que a letra foi encontrada
            }
         }

         if (!found) {
            // Letra incorreta, aumenta o número de tentativas e desenha o boneco
            printf("-------------------------------------------------\n\n"
               "Letra incorreta!\n");
            tentativas++;
         }

         // Exibe a evolução do boneco na forca a cada erro
         forca(tentativas, palavra);
         
         // Verifica se o jogador perdeu o jogo
         if (tentativas >= 6)
            break;
      }

      if (strcmp(palavra, resposta) == 0) {
         printf("-------------------------------------------------\n\n");
         printf("Parabéns, você acertou a palavra: %s\n\n", palavra);
         printf("   \\O/ \n"
          "    |   \n"
          "   / \\ \n"
          " -------\n");
      }

      // Reseta as tentativas para o próximo jogo
      tentativas = 0;
   }

   return 0;
}
