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
   int num_temas;
   char buffer[256];
   srand(time(NULL));

   // Abre o arquivo de palavras
   FILE *arquivo = fopen("palavras.txt", "r");
   if (arquivo == NULL) {
      perror("--------------------------------------------------\n\n"
         "Erro ao abrir o arquivo");
      exit(1);
   }

   // Lê a quantidade de temas presentes no arquivo
   fscanf(arquivo, "%d\n", &num_temas);

   // Escolhe um tema aleatório
   int tema_ale = rand() % num_temas;
   int tema_atual = 0;
   int num_palavras;

   // Lê o arquivo até encontrar o tema sorteado
   while (fscanf(arquivo, "%d %s\n", &num_palavras, tema) != EOF) {
      if (tema_atual == tema_ale) {
         // Sorteia uma palavra aleatória do tema selecionado
         int palavra_ale = rand() % num_palavras;
         int palavra_atual = 0;

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
         fgets(tema, sizeof(buffer), arquivo);
      }

      tema_atual++;
   }

   printf("\n");
   
   fclose(arquivo);
}

int main() { 
   char palavra[50], resposta[50], letras[50] = "", tema[50];
   char letra;
   int i = 0, found, tentativas = 0;

   while (1) {
      // Menu inicial para o jogador escolher entre palavra aleatória, palavra definida ou sair
      do {
         printf("-------------------------------------------------\n\n"
            "Digite 1 para jogar com a palavra chave aleatoria\n"
            "Digite 2 para jogar com a palavra escolhida\n"
            "Digite 3 para sair\nOpc: ");
         scanf("%d", &i);
         if (i == 1) {
            palavra_chave_pre(palavra, tema);
            break;
         }
         else if (i == 2) {
            palavra_chave_usu(palavra, tema);
            break;
         }
         else if (i == 3) {
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
            resposta[i] = ' ';
         } else {
            resposta[i] = '_';
         }
         palavra[i] = toupper(palavra[i]);
      }
      resposta[palavra_length] = '\0';

      // Coloca o tema em maiúsculas
      for (i = 0; i < strlen(tema); i++) {
         tema[i] = toupper(tema[i]);
      }

      // Inicializa a string de letras digitadas como vazia
      strcpy(letras, "");
   
      // Loop do jogo até que o jogador adivinhe a palavra
      while (strcmp(palavra, resposta) != 0) {
         printf("TEMA: %s\n\n"
               "Letras digitadas: %s\n\n"
               "Palavra: ", tema, letras);
         for (i = 0; i < palavra_length; i++) {
            printf(" %c", resposta[i]);
         }
         printf("\n\nDigite uma letra: ");
         scanf(" %c", &letra);
         letra = toupper(letra);
         strncat(letras, &letra, 1);
   
         found = 0;
         for (i = 0; i < palavra_length; i++) {
            if (toupper(palavra[i]) == letra) {
               resposta[i] = letra;
               found = 1;
            }
         }
   
         if (!found) {
            printf("\nLetra incorreta!\n");
            tentativas++;
   
            // Exibe a evolução do boneco na forca a cada erro
            if (tentativas == 1)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|       \n"
                  "|       \n"
                  "|_____  \n");
            else if (tentativas == 2)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /    \n"
                  "|       \n"
                  "|_____  \n");
            else if (tentativas == 3)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|   \n"
                  "|       \n"
                  "|_____  \n");
            else if (tentativas == 4)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|\\ \n"
                  "|       \n"
                  "|_____  \n");
            else if (tentativas == 5)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|\\ \n"
                  "|  /    \n"
                  "|_____  \n");
            else {
               // Perdeu o jogo após 6 erros
               printf("\nVoce perdeu!\n"
                  "_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|\\ \n"
                  "|  / \\ \n"
                  "|_____  \n");
               return 0;
            }
            printf("Tentativas restantes: %d\n", 6 - tentativas);
         }
         printf("\n\n");      
      }
   
      printf("Parabens! Voce acertou a palavra: %s\n", palavra);
      printf("\n"
         "   \\O/ \n"
         "    |   \n"
         "   / \\ \n"
         " -------\n");
   }
   return 0;
}
