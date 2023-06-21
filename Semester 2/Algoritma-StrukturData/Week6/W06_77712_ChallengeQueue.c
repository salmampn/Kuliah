#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <unistd.h>

typedef struct Antrian
{
  int num;
  struct Antrian *next;
} Antrian;

void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

int isEmpty(Antrian *front)
{
  if (front == NULL)
  {
    return 1;
  }
  return 0;
}

void enqueue(Antrian **front, Antrian **rear, int num)
{
  Antrian *newNode = (Antrian *)malloc(sizeof(Antrian));
  newNode->num = num;
  newNode->next = NULL;
  if ((*front) == NULL)
  {
    (*front) = newNode;
  }
  else
  {
    (*rear)->next = newNode;
  }
  (*rear) = newNode;
}

void dequeue(Antrian **front)
{
  Antrian *trash;
  if (isEmpty(*front))
  {
    return;
  }
  trash = (*front);
  (*front) = (*front)->next;
  trash->next = NULL;
  free(trash);
}

void inputNumber(Antrian **front, Antrian **rear)
{
  int num;
  printf("Input a number: ");
  fflush(stdin);
  scanf("%d", &num);
  printf("\n");
  fflush(stdin);

  if (num <= 0)
  {
    printf("Enter a valid number!\nNumber must be greater than zero\n");
    return;
  }

  // if queue is empty
  if ((*front) == NULL)
  {
    for (int i = 0; i < num; i++)
    {
      enqueue(front, rear, num);
    }
    printf("Enqueueing number %d, %dx times.\n", num, num);
  }
  // if queue not empty
  else
  {
    if (num < (*front)->num)
    {
      for (int i = 1; i <= num; i++)
      {
        if (!isEmpty(*front))
        {
          dequeue(front);
          if (i == 1)
          {
            printf("%dst dequeueing.\n", i);
            sleep(1);
            continue;
          }
          else if (i == 2)
          {
            printf("%dnd dequeueing.\n", i);
            sleep(1);
            continue;
          }
          else if (i == 3)
          {
            printf("%drd dequeueing.\n", i);
            sleep(1);
            continue;
          }
          else
          {
            printf("%dth dequeueing.\n", i);
            sleep(1);
            continue;
          }
        }
        else
        {
          printf("Stop dequeueing. Queue is empty.\n");
          break;
        }
      }
      if (!isEmpty(*front))
      {
        printf("\nFinished dequeueing queue %d times.\n", num);
      }
      else
      {
        printf("\nFinished dequeueing queue.\n");
      }
    }
    else
    {
      for (int i = 0; i < num; i++)
      {
        enqueue(front, rear, num);
      }
      printf("Enqueueing number %d, %dx times.\n", num, num);
    }
  }
}

void viewQueue(Antrian **front)
{
  if (isEmpty(*front))
    return;
  Antrian *temp;
  temp = (*front);
  printf("\n\t");
  while (temp != NULL)
  {
    printf("%d ", temp->num);
    if (temp->next != NULL)
    {
      printf("<- ");
    }
    temp = temp->next;
  }
}

void clearQueue(Antrian **front)
{
  Antrian *trash;
  while ((*front) != NULL)
  {
    trash = (*front);
    (*front) = (*front)->next;
    trash->next = NULL;
    free(trash);
  }
}

int main()
{
  int menu;
  Antrian *front, *rear;
  front = rear = NULL;

menu:
  system("cls");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("|                                         WELCOME TO SIMPLE QUEUE PROGRAM                                         |\n");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("You'll input a number (n). Here are some rules:\n");
  printf("1. When queue is empty. Program will enqueue the input number (n), n times.\n");
  printf("2. When queue not empty. If n < front, program will dequeue n times. If n >= front, program will do first rules.\n");
  printf("3. Number must be greater than 0.\n");

  if (front != NULL)
  {
    viewQueue(&front);
    printf("\n\t FRONT => %d\n", front->num);
  }

  printf("\n******************************************************************************************************************\n");
  printf("1. Input number\n2. Clear queue\n3. Exit\nChoice: ");
  scanf("%d", &menu);

  switch (menu)
  {
  case 1:
    inputNumber(&front, &rear);
    clearScreen();
    goto menu;
    break;

  case 2:
    clearQueue(&front);
    printf("\nClearing queue...\n");
    sleep(1);
    printf("Finish clearing queue\n\n");
    clearScreen();
    goto menu;
    break;

  default:
    clearQueue(&front);
    printf("\nGoodbye.\nHave a Nice Day!\n");
    fflush(stdin);
    sleep(1);
    break;
  }

  return 0;
}
