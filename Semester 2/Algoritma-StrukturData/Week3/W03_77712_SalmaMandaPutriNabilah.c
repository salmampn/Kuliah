#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

struct student
{
  char name[50];
  char major[35];
  char nim[20];
};

struct scores
{
  float tugas, uts, uas, akhir;
  char grade[5];
};

// Function to clear screen
void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

//Function to input new student data
void inputStudent(struct student s[100], int *i, struct scores g[100], FILE *fin, FILE *fout)
{
  printf("\nInsert Student information\n");
  printf("--------------------------\n");
  printf("NIM\t: ");
  scanf("%[^\n]", s[*i].nim);
  fflush(stdin);
  printf("Name\t: ");
  scanf("%[^\n]", s[*i].name);
  fflush(stdin);
  printf("Major\t: ");
  scanf("%[^\n]", s[*i].major);
  fflush(stdin);
  fprintf(fin, "%s#%s#%s\n", s[*i].nim, s[*i].major, s[*i].name);

  // Input student grades
  printf("\nInsert Student Grades\n");
  printf("--------------------------\n");
  printf("Tugas\t: ");
  scanf("%f", &g[*i].tugas);
  fflush(stdin);
  printf("UTS\t: ");
  scanf("%f", &g[*i].uts);
  fflush(stdin);
  printf("UAS\t: ");
  scanf("%f", &g[*i].uas);
  fflush(stdin);
  g[*i].akhir = g[*i].tugas * 0.3 + g[*i].uts * 0.3 + g[*i].uas * 0.4;
  fflush(stdin);

  // Determine which grade student get
  if (g[*i].akhir >= 95)
  {
    strcpy(g[*i].grade, "A+");
  }
  else if (g[*i].akhir >= 85)
  {
    strcpy(g[*i].grade, "A");
  }
  else if (g[*i].akhir >= 80)
  {
    strcpy(g[*i].grade, "A-");
  }
  else if (g[*i].akhir >= 75)
  {
    strcpy(g[*i].grade, "B+");
  }
  else if (g[*i].akhir >= 70)
  {
    strcpy(g[*i].grade, "B");
  }
  else if (g[*i].akhir >= 65)
  {
    strcpy(g[*i].grade, "C");
  }
  else if (g[*i].akhir >= 60)
  {
    strcpy(g[*i].grade, "C-");
  }
  else if (g[*i].akhir >= 55)
  {
    strcpy(g[*i].grade, "D");
  }
  else if (g[*i].akhir >= 0)
  {
    strcpy(g[*i].grade, "E");
  }

  fflush(stdin);

  fprintf(fout, "%.0f#%.0f#%.0f#%.2f#%s\n", g[*i].tugas, g[*i].uts, g[*i].uas, g[*i].akhir, g[*i].grade);
  *i = *i + 1;
}

// Function to print student data
void printStudent(struct student s[100], int *iCounter, struct scores g[100])
{
  printf("                          List of Student Information                           \n");
  printf("------------------------------------------------------------------------------\n");
  printf("|No.|               Name                |        Major       |      NIM      |");
  printf("\n------------------------------------------------------------------------------\n");
  for (int i = 0; i < *iCounter; i++)
  {
    printf("|%-3d|%-35s|%-20s|%-15s|\n", i + 1, s[i].name, s[i].major, s[i].nim);
    printf("------------------------------------------------------------------------------\n");
  }
  printf("\n");
  fflush(stdin);

  printf("                       List of Student Scores                       \n");
  printf("-------------------------------------------------------------------\n");
  printf("|No.|        NIM        | Tugas | UTS | UAS | Nilai Akhir | Grade |");
  printf("\n-------------------------------------------------------------------\n");
  for (int i = 0; i < *iCounter; i++)
  {
    printf("|%-3d|%-19s|%-7.0f|%-5.0f|%-5.0f|%-13.2f|%-7s|\n", i + 1, s[i].nim, g[i].tugas, g[i].uts, g[i].uas, g[i].akhir, g[i].grade);
    printf("-------------------------------------------------------------------\n");
  }
  printf("\n");
  fflush(stdin);
};

int main()
{
  int menu, iCounter = 0;
  struct student stu[100];
  struct scores gra[100];

  FILE *fin = fopen("dataMahasiswa.txt", "w");
  FILE *fout = fopen("nilaiMahasiswa.txt", "w");

menu:
  printf("\nWelcome to simple student database(%d/100)\n1. Input new students \n2. Show all students\n3. Exit\nChoose: ", iCounter);
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    system("cls");
    inputStudent(stu, &iCounter, gra, fin, fout);
    printf("Inserting data...\n");
    sleep(1);
    printf("New student added.\n\n");
    sleep(1);
    clearScreen();
    goto menu;
    break;

  case 2:
    system("cls");
    printStudent(stu, &iCounter, gra);
    printf("\nFinish printing data\n");
    clearScreen();
    goto menu;
    break;

  default:
    printf("\nGoodbye.\nHave a Nice Day!\n");
    fclose(fin);
    fclose(fout);
    sleep(1);
    fflush(stdin);
    break;
  }

  return 0;
}
