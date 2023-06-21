#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <unistd.h>

struct student
{
  char nama[35];
  char major[20];
  int nim;
  struct student *next;
};

// Function to clear screen
void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

//Function to create new node
struct student *createNewNode()
{
  char nama[35], major[20];
  int nim;
  struct student *newNode;
  newNode = (struct student *)malloc(sizeof(struct student));

  printf("\nNIM\t: ");
  scanf("%d", &nim);
  fflush(stdin);
  printf("Nama\t: ");
  scanf("%[^\n]", nama);
  fflush(stdin);
  printf("Jurusan\t: ");
  scanf("%[^\n]", major);
  fflush(stdin);

  newNode->nim = nim;
  fflush(stdin);
  strcpy(newNode->nama, nama);
  fflush(stdin);
  strcpy(newNode->major, major);
  fflush(stdin);
  newNode->next = NULL;

  return newNode;
}

// Function to print linked list
void printNode(struct student **head)
{
  struct student *temp;
  temp = (*head);
  int i = 1;

  printf("                          List of Student Information                           \n");
  printf("------------------------------------------------------------------------------\n");
  printf("|No.|               Name                |        Major       |      NIM      |");
  printf("\n------------------------------------------------------------------------------\n");

  while (temp != NULL)
  {
    printf("|%-3d|%-35s|%-20s|%-15d|\n", i, temp->nama, temp->major, temp->nim);
    printf("------------------------------------------------------------------------------\n");
    fflush(stdin);
    temp = temp->next;
    i++;
    fflush(stdin);
  }
  printf("\n");
}

// Function to delete linked list
void deleteAll(struct student **head, struct student *node)
{
  node = (*head);
  while ((*head) != NULL)
  {
    node = (*head);
    (*head) = (*head)->next;
    free(node);
  }
}

// Function to delete first node
void deleteFirst(struct student **head)
{
  struct student *trash;
  trash = (*head);
  (*head) = (*head)->next;
  free(trash);
}

int main()
{
  struct student *head, *node, *tail;
  int menu;
  head = NULL;
  tail = NULL;
  node = (struct student *)malloc(sizeof(struct student));

menu:
  printf("\nWelcome to linked list students database\n");
  printf("1. Input new students \n2. Print all students\n3. Delete all data\n4. Delete first data\n5. Delete data by NIM\n6. Exit\nChoose: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    node = createNewNode();
    if (head == NULL)
    {
      head = node;
      tail = node;
    }
    else
    {
      tail->next = node;
      tail = node;
      node->next = NULL;
      fflush(stdin);
    }
    printf("Inserting data...\n");
    sleep(1);
    printf("New student added.\n\n");
    sleep(1);
    clearScreen();
    fflush(stdin);
    goto menu;
    break;

  case 2:
    if (head == NULL)
    {
      printf("\n\n-- DATA KOSONG --\n\n");
    }
    else
    {
      printNode(&head);
    }
    printf("\nFinish printing data\n");
    clearScreen();
    fflush(stdin);
    goto menu;
    break;

  case 3:
    deleteAll(&head, node);
    head = NULL;
    tail = NULL;
    printf("\nFinish deleting all data\n");
    clearScreen();
    fflush(stdin);
    goto menu;

  case 4:
    deleteFirst(&head);
    printf("\nFinish deleting first data\n");
    clearScreen();
    fflush(stdin);
    goto menu;
    break;

  case 5:
    // Delete data by NIM
    struct student *temp, *trash;
    int nim;

    if (head == NULL)
    {
      printf("\n\n-- DATA KOSONG --\n\n");
      clearScreen();
      fflush(stdin);
      goto menu;
    }

    printf("\nNIM: ");
    scanf("%d", &nim);
    temp = head;
    trash = head;

    do
    {
      // If head is target, skip loop.
      if (head->nim == nim)
      {
        continue;
      }
      else if (trash->next == NULL || (head->next == NULL && nim != head->nim))
      {
        printf("NIM not found.");
        getch();
        system("cls");
        goto menu;
      }

      // After first loop iteration, move temp.
      if (trash != head)
      {
        temp = temp->next;
      }
      trash = trash->next;
    }

    while (trash->nim != nim && trash != NULL);

    // If head is target and there exists next node, move head to next node.
    if (trash == head && head->next != NULL)
    {
      head = head->next;
      // If head is target, BUT there is no next node, then head returns to NULL.
    }
    else if (trash == head)
    {
      head = NULL;
      tail = NULL;
      // If there exists a node after trash, then connect node before trash and node after trash.
    }
    else if (trash->next != NULL)
    {
      temp->next = trash->next;
      // If target is tail, node before trash has no link and move tail.
      // Note to self: tail = temp; is only local to function, but something like tail = temp->next; affects main().
      // Because one is a struct equals another struct, while the other a struct equals a data in a struct.
    }
    else if (trash->next == NULL)
    {
      tail = temp;
      temp->next = NULL;
    }
    trash->next = NULL;
    free(trash);
    printf("\nFinish deleting data\n");
    clearScreen();
    fflush(stdin);
    goto menu;
    break;

  default:
    printf("\nGoodbye.\nHave a Nice Day!\n");
    fflush(stdin);
    sleep(1);
    break;
  }

  return 0;
}
