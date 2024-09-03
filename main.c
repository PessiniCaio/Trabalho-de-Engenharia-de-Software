#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void palavra_chave_usu(char *palavra, char *tema) {
   strcpy(tema, "ComIda");
   strcpy(palavra, "maca");
   printf("\n");
}

void palavra_chave_pre(char *palavra, char *tema) {
   int num_temas;
   char buffer[256];
   srand(time(NULL));

   FILE *arquivo = fopen("palavras.txt", "r");
   if (arquivo == NULL) {
      perror("--------------------------------------------------\n\n"
         "Erro ao abrir o arquivo");
      exit(1);
   }

   fscanf(arquivo, "%d\n", &num_temas);

   int tema_ale = rand() % num_temas;
   int tema_atual = 0;
   int num_palavras;

   while (fscanf(arquivo, "%d %s\n", &num_palavras, tema) != EOF) {
      if (tema_atual == tema_ale) {
         int palavra_ale = rand() % num_palavras;
         int palavra_atual = 0;

         while (fgets(buffer, sizeof(buffer), arquivo) != NULL && palavra_atual < num_palavras) {
            if (palavra_atual == palavra_ale) {
               buffer[strcspn(buffer, "\n")] = '\0';
               strcpy(palavra, buffer);
               break;
            }
            palavra_atual++;
         }
         break;
      }

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
         if (i == 2) {
            palavra_chave_usu(palavra, tema);
            break;
         }
         if (i == 3) {
            exit(1);
         }
         else
            printf("Opção inválida\n\n");
      } while (i != 1 && i != 2 && i != 3);

      int palavra_length = strlen(palavra);
   
      for (i = 0; i < palavra_length; i++) {
         if (palavra[i] == ' ') {
            resposta[i] = ' ';
         } else {
            resposta[i] = '_';
         }
         palavra[i] = toupper(palavra[i]);
      }
      resposta[palavra_length] = '\0';
   
      for (i = 0; i < strlen(tema); i++) {
         tema[i] = toupper(tema[i]);
      }

      strcpy(letras, "");
   
      while (strcmp(palavra, resposta) != 0) {
         printf("TEMA: %s\n\n", tema);
         printf("Letras digitadas: %s\n\n", letras);
         printf("Palavra: ");
         for (i = 0; i < palavra_length; i++) {
            printf(" %c", resposta[i]);
         }
         printf("\n\n");
         printf("Digite uma letra: ");
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
   
            if (tentativas == 1)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|       \n"
                  "|       \n"
                  "|_____  \n");
            if (tentativas == 2)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /    \n"
                  "|       \n"
                  "|_____  \n");
            if (tentativas == 3)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|   \n"
                  "|       \n"
                  "|_____  \n");
            if (tentativas == 4)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|\\ \n"
                  "|       \n"
                  "|_____  \n");
            if (tentativas == 5)
               printf("_____\n"
                  "|   |   \n"
                  "|   O   \n"
                  "|  /|\\ \n"
                  "|  /    \n"
                  "|_____  \n");
            if (tentativas >= 6) {
               printf("\nVoce perdeu!\n");
               printf("_____\n"
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