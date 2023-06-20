#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

struct student
{
  char name[50];
  char major[35];
  float gpa;
};

// Function to clear screen
void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

// Function to insert student information
void inputStudent(struct student s[20], int *iCounter)
{
  printf("\nInsert Student information\n");
  printf("--------------------------\n");

  printf("Name\t: ");
  scanf("%[^\n]", s[*iCounter].name);
  fflush(stdin);
  printf("Major\t: ");
  scanf("%[^\n]", s[*iCounter].major);
  fflush(stdin);
  printf("GPA\t: ");
  scanf("%f", &s[*iCounter].gpa);
  *iCounter = *iCounter + 1;
  fflush(stdin);
}

// Function to print students information
void printStudent(struct student s[20], int *iCounter)
{
  printf("                                          List of Student Information                                           \n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|No.|                       Name                       |               Major               |       GPA      |");
  printf("\n-------------------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < *iCounter; i++)
  {
    printf("|%-3d|%-50s|%-35s|%-16.2f|\n", i + 1, s[i].name, s[i].major, s[i].gpa);
  }
  printf("-------------------------------------------------------------------------------------------------------------\n\n");
  fflush(stdin);
};

int main()
{
  // Initialize variables
  int menu, iCounter = 0;
  struct student stu[20];

menu:
  printf("Welcome to simple student database(%d/20)\n", iCounter);
  printf("1. Show all students\n2. Input new students\n3. Exit\nChoose: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    printStudent(stu, &iCounter);
    clearScreen();
    goto menu;
    break;

  case 2:
    system("cls");
    inputStudent(stu, &iCounter);
    printf("Inserting data...\n");
    sleep(1);
    printf("New student added.\n\n");
    sleep(1);
    clearScreen();
    goto menu;
    break;

  default:
    printf("\nGoodbye.\nHave a Nice Day!\n");
    sleep(1);
    break;
  }

  return 0;
}
