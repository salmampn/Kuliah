#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Function to clear screen
void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

// Function to input sentences
void inputSentence(char sentence[])
{
  printf("\nInput sentences: ");
  scanf("%[^\n]", sentence);
}

// Function to print sentences
void printSentence(char sentence[])
{
  printf("\t\t%s\n\n", sentence);
}

// Function to change Lowercase characters to Uppercase
void Uppercase(char *sentence)
{
  for (int i = 0; i < strlen(sentence); i++)
  {
    if (sentence[i] >= 'a' && sentence[i] <= 'z')
      sentence[i] -= ('a' - 'A');
  }
}

// Function to change Uppercase characters to Lowercase
void Lowercase(char *sentence)
{
  int i;
  for (i = 0; i < strlen(sentence); i++)
  {
    if (sentence[i] >= 'A' && sentence[i] <= 'Z')
      sentence[i] += ('a' - 'A');
  }
}

// Function to switch characters
void Switching(char *sentence)
{
  int i;
  for (i = 0; i < strlen(sentence); i++)
  {
    if (sentence[i] >= 'a' && sentence[i] <= 'z')
    {
      sentence[i] -= ('a' - 'A');
    }
    else if (sentence[i] >= 'A' && sentence[i] <= 'Z')
    {
      sentence[i] += ('a' - 'A');
    }
  }
}

int main()
{
  // Initialize variables
  int menu;
  char sentence[100];

menu:
  printf("Welcome to simple character program!\n");
  printf("1. Uppercase\n2. Lowercase\n3. Switching\n4. Exit\nChoice: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    inputSentence(sentence);
    Uppercase(sentence);
    printSentence(sentence);
    clearScreen();
    goto menu;
    break;
  case 2:
    inputSentence(sentence);
    Lowercase(sentence);
    printSentence(sentence);
    clearScreen();
    goto menu;
    break;
  case 3:
    inputSentence(sentence);
    Switching(sentence);
    printSentence(sentence);
    clearScreen();
    goto menu;
    break;
  default:
    printf("\nGoodbye.\nHave a Nice Day!!");
    sleep(1);
    break;
  }
  return 0;
}