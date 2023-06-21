#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <unistd.h>

typedef struct Playlist
{
  char singer[50];
  char title[50];
  char album[50];
  int year;
  struct Playlist *next, *prev;
} Playlist;

// Function to clear screen
void clearScreen()
{
  printf("Press any key to continue...");
  getch();
  system("cls");
}

// Start Function Case 1
void printPlaylist(Playlist **head)
{
  Playlist *temp;
  temp = (*head);
  int i = 1;

  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("|                                                 YOUR PLAYLIST                                                  |\n");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  printf("|No.|          Singer          |         Song Title         |               Album                | Released Year |\n");
  printf("------------------------------------------------------------------------------------------------------------------\n");
  while (temp != NULL)
  {
    printf("|%-3d| %-25s| %-27s| %-35s| %-14d|\n", i, temp->singer, temp->title, temp->album, temp->year);
    printf("------------------------------------------------------------------------------------------------------------------\n");
    temp = temp->next;
    i++;
  }
  printf("\nYour Current Playlist!\n\n");
  clearScreen();
  fflush(stdin);
}
// End Function Case 1

// Start Function Case 2
void addPlaylist(char singer[50], char album[50], char title[50], int *year)
{
  FILE *fp = fopen("playlist.txt", "a");
  printf("Singer\t\t: ");
  fflush(stdin);
  scanf("%[^\n]", singer);
  fflush(stdin);
  printf("Song Title\t: ");
  scanf("%[^\n]", title);
  fflush(stdin);
  printf("Album\t\t: ");
  scanf("%[^\n]", album);
  printf("Released Year\t: ");
  scanf("%d", &(*year));
  fprintf(fp, "%s*%s*%s*%d\n", singer, album, title, (*year));
  fclose(fp);
}

Playlist *createNode(char singer[50], char album[50], char title[50], int year)
{
  Playlist *newNode = (Playlist *)malloc(sizeof(Playlist));
  strcpy(newNode->singer, singer);
  fflush(stdin);
  strcpy(newNode->album, album);
  fflush(stdin);
  strcpy(newNode->title, title);
  fflush(stdin);
  newNode->year = year;
  fflush(stdin);
  newNode->next = newNode->prev = NULL;
  fflush(stdin);
  return newNode;
}

void linkNode(Playlist **head, Playlist **node, Playlist **tail)
{
  if ((*head) == NULL)
  {
    (*node)->next = (*node)->prev = NULL;
    (*head) = (*tail) = (*node);
  }
  else
  {
    (*node)->prev = (*tail);
    (*tail)->next = (*node);
    (*tail) = (*node);
    (*node)->next = NULL;
  }
}
// End Function Case 2

// Start Function Case 3
void deleteLast(Playlist **head, Playlist **node, Playlist **tail)
{
  Playlist *trash;
  trash = (*tail);
  (*tail) = (*tail)->prev;
  (*tail)->next = NULL;
  printf("Lagu [%s - %s]\nBerhasil Dihapus...\n\n", trash->title, trash->singer);
  clearScreen();
  fflush(stdin);
  free(trash);
  fflush(stdin);
}

void reWrite(Playlist **head)
{
  Playlist *temp;
  temp = (*head);
  FILE *fout = fopen("playlist.txt", "w");
  while (temp != NULL)
  {
    fprintf(fout, "%s*%s*%s*%d\n", temp->singer, temp->album, temp->title, temp->year);
    temp = temp->next;
  }
  fclose(fout);
}
// End Function Case 3

int main()
{
  Playlist *head, *node, *tail;
  int menu, year;
  head = tail = NULL;
  char singer[50], title[50], album[50];
  FILE *fin = fopen("playlist.txt", "r");
  while (!feof(fin))
  {
    fscanf(fin, "%[^*]*%[^*]*%[^*]*%d\n", singer, album, title, &year);
    node = createNode(singer, album, title, year);
    linkNode(&head, &node, &tail);
  }
  fclose(fin);

menu:
  printf("--------------------------------------\n");
  printf("| -- WELCOME TO PLAYLIST DATABASE -- |\n");
  printf("--------------------------------------\n");
  printf("1. Show My Playlist\n2. Add Song To Playlist\n3. Erase Recent Added Song\n4. Exit\nChoice: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    system("cls");
    printPlaylist(&head);
    goto menu;
    break;

  case 2:
    system("cls");
    addPlaylist(singer, album, title, &year);
    node = createNode(singer, album, title, year);
    linkNode(&head, &node, &tail);
    printf("\nLagu [%s - %s]\nBerhasil ditambahkan ke dalam playlist\n\n", title, singer);
    clearScreen();
    fflush(stdin);
    goto menu;
    break;

  case 3:
    system("cls");
    deleteLast(&head, &node, &tail);
    reWrite(&head);
    goto menu;
    break;

  default:
    printf("\nGoodbye.\nHave a Nice Day!\n");
    fflush(stdin);
    free(head);
    sleep(1);
    break;
  }
  return 0;
}
