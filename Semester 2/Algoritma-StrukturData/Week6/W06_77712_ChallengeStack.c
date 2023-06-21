#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

typedef struct Expression
{
  char input;
  struct Expression *next;
} Expression;

// Initialize stack variables
Expression *top, *node;
Expression *top = NULL;

int isMatchingPair(char closing)
{
  // This function run when a closing brackets is inputted:
  // The use of this function is to check whether the brackets are paired or not.
  if (top->input == '(' && closing == ')')
  {
    return 1;
  }
  else if (top->input == '[' && closing == ']')
  {
    return 1;
  }
  else if (top->input == '{' && closing == '}')
  {
    return 1;
  }
  return 0;
}

int checkExpression(char *input)
{
  // Program will only push the open brackets.
  // The closing is not gonna be push to the stack, only to check the inputed expression.
  int parentheses = strlen(input);
  Expression *pop;
  for (int i = 0; i < parentheses; i++)
  {
    // This run when input[i] is open brackets
    // Stacking open brackets
    if (input[i] == '(' || input[i] == '{' || input[i] == '[')
    {
      Expression *node = (Expression *)malloc(sizeof(Expression));
      node->input = input[i];
      node->next = NULL;
      if (top == NULL)
      {
        top = node;
      }
      else
      {
        node->next = top;
        top = node;
      }
    }
    // This run when input[i] is closing brackets
    else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
    {
      // This line of code is used to check whether the input expression is correct or not.
      if (top == NULL || !isMatchingPair(input[i]))
      {
        return 0;
      }
      // If the input expression correct, program will pop the top which is open brackets.
      // The inputed expression will be correct if the stack is empty again.
      else
      {
        pop = top;
        top = top->next;
        free(pop);
      }
    }
    // If the input expression contain any other characters other than brackets, program will return false.
    else
    {
      return 0;
    }
  }
  // If the stack not empty yet, it means that the expression is a false expression
  if (top != NULL)
  {
    return 0;
  }
  return 1;
}

void deleteStack()
{
  Expression *trash;
  while (top != NULL)
  {
    trash = top;
    top = top->next;
    free(trash);
  }
  top = NULL;
}

int main()
{
  char input[100];
  int brackets;

  system("cls");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("|                                     WELCOME TO PARENTHESES CHECKING PROGRAM                                    |\n");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("You'll input parentheses expressions. Here are some rules:\n");
  printf("1. Expressions must be just brackets, no spaces or any other character.\n");
  printf("2. The program will stop if you input '-1'.\n\n");

  do
  {
    printf("Input Parentheses Expression:");
    scanf("%s", input);

    if (strcmp(input, "-1") == 0)
    {
      printf("\nGoodbye!\nHave a nice day\n");
      return 0;
    }

    brackets = checkExpression(input);
    if (brackets == 1)
    {
      puts("Valid Parentheses Expression\n");
    }
    else
    {
      puts("Invalid Parentheses Expression\n");
    }
    // This will delete stack that contains open brackets because of the invalid parenthesis expression.
    deleteStack();
  } while (strcmp(input, "-1") != 0);
}