#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

/*
Nama    : Salma Manda Putri Nabilah
NIM     `: 00000077712
Kelas   : IF232 - HL
Nilai   :
*/

typedef struct Buku
{
  char judul[100];
  char penulis[50];
  char penerbit[50];
  char tahun[5];
  char genre[20];
  struct Buku *next, *prev;
} Buku;

void clearScreen()
{
  printf("\nPress any key to continue...");
  getch();
  system("cls");
}

// Start of Case 1
void printList(Buku **tail, int j)
{
  Buku *temp = (Buku *)malloc(sizeof(Buku));
  temp = (*tail);
  int i = 1;

  while (temp != NULL)
  {
    printf("\nBuku ke-%d dari %d\n", i, j);
    printf("======================================================================\n");
    printf("Judul Buku\t: %s\n", temp->judul);
    fflush(stdin);
    printf("Penulis Buku\t: %s\n", temp->penulis);
    fflush(stdin);
    printf("Tahun Terbit\t: %s\n", temp->tahun);
    fflush(stdin);
    printf("Penerbit\t: %s\n", temp->penerbit);
    fflush(stdin);
    printf("Genre\t\t: %s\n", temp->genre);
    fflush(stdin);
    printf("======================================================================\n");
    i++;
    temp = temp->prev;
    fflush(stdin);
  }
}
// End of Case 1

// Start of Case 2
void addBook(char judul[100], char penulis[50], char penerbit[50], char tahun[5], char genre[20])
{
  FILE *fout = fopen("data_buku.txt", "a");
  printf("Masukkan judul buku\t: ");
  fflush(stdin);
  scanf("%[^\n]", judul);
  fflush(stdin);
  printf("Masukkan penulis buku\t: ");
  fflush(stdin);
  scanf("%[^\n]", penulis);
  fflush(stdin);
  printf("Masukkan tahun terbit\t: ");
  fflush(stdin);
  scanf("%[^\n]", tahun);
  fflush(stdin);
  printf("Masukkan penerbit\t: ");
  fflush(stdin);
  scanf("%[^\n]", penerbit);
  fflush(stdin);
  printf("Masukkan genre\t\t: ");
  fflush(stdin);
  scanf("%[^\n]", genre);
  fflush(stdin);
  fprintf(fout, "%s#%s#%s#%s#%s\n", judul, penulis, penerbit, tahun, genre);
  fflush(stdin);
  fclose(fout);
}

Buku *createNewNode(char judul[100], char penulis[50], char penerbit[50], char tahun[5], char genre[20])
{
  Buku *newNode = (Buku *)malloc(sizeof(Buku));
  strcpy(newNode->judul, judul);
  strcpy(newNode->penulis, penulis);
  strcpy(newNode->penerbit, penerbit);
  strcpy(newNode->tahun, tahun);
  strcpy(newNode->genre, genre);
  newNode->next = newNode->prev = NULL;
  fflush(stdin);
  return newNode;
}

void linkNode(Buku **head, Buku **node, Buku **tail)
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
// End of Case 2

// Start of Case 3
void deleteBook(Buku **head)
{
  Buku *trash;
  trash = (*head);
  if ((*head == NULL))
  {
    printf("Tidak ada buku yang dapat dihapus lagi\nBuku diperpustakaan kosong\n");
  }
  else
  {
    (*head) = (*head)->next;
    (*head)->prev = NULL;
    fflush(stdin);
    printf("Data buku dengan judul '%s' berhasil dihapus...\n\n", trash->judul);
    fflush(stdin);
    free(trash);
  }
}

void reWrite(Buku **head)
{
  Buku *temp;
  temp = (*head);
  FILE *fout = fopen("data_buku.txt", "w");
  while (temp != NULL)
  {
    fprintf(fout, "%s#%s#%s#%s#%s\n", temp->judul, temp->penulis, temp->penerbit, temp->tahun, temp->genre);
    temp = temp->next;
  }
  fclose(fout);
}
// End of Case 3

// Start of Case 4
void totalBuku(Buku **head)
{
  Buku *temp;
  temp = (*head);
  int i = 0;
  while (temp != NULL)
  {
    i++;
    temp = temp->next;
  }
  printf("Terdapat %d buku di dalam database perpustakaan\n", i);
}
// End of Case 4

// Start of Case 5
void searchBook(Buku **head, Buku **node, Buku **tail, char judul[100])
{
  Buku *temp;
  temp = (*head);
  int cek;
  printf("Masukkan judul buku yang dicari: ");
  fflush(stdin);
  scanf("%[^\n]", judul);
  cek = strcmp(temp->judul, judul);
  while (cek != 0)
  {
    temp = temp->next;
    cek = strcmp(temp->judul, judul);
    continue;
  }

  if (cek == 0)
  {
    printf("Data ditemukan di dalam sistem.\n\n");
    printf("Judul Buku\t: %s\n", temp->judul);
    fflush(stdin);
    printf("Penulis Buku\t: %s\n", temp->penulis);
    fflush(stdin);
    printf("Tahun Terbit\t: %s\n", temp->tahun);
    fflush(stdin);
    printf("Penerbit\t: %s\n", temp->penerbit);
    fflush(stdin);
    printf("Genre\t\t: %s\n", temp->genre);
    fflush(stdin);
  }
  else
  {
    printf("Data tidak ditemukan\n");
  }
}
// End of Case 5

int main()
{
  int menu;
  Buku *head, *tail;
  head = tail = NULL;

  Buku *node = (Buku *)malloc(sizeof(Buku));
  char judul[100];
  char penulis[50];
  char penerbit[50];
  char tahun[5];
  char genre[20];

  FILE *fin = fopen("data_buku.txt", "r");
  while (!feof(fin))
  {
    fscanf(fin, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", judul, penulis, penerbit, tahun, genre);
    node = createNewNode(judul, penulis, penerbit, tahun, genre);
    linkNode(&head, &node, &tail);
  }
  fclose(fin);

menu:
  system("cls");
  printf("============================================\n");
  printf("        Sistem Manajemen Perpustakaan        \n");
  printf("============================================\n\n");

  printf("1. Tampilkan Semua Buku\n2. Tambah Buku\n3. Hapus Buku\n4. Total Buku\n5. Cari Buku\n6. Keluar\n\nPilihan Anda: ");
  scanf("%d", &menu);

  switch (menu)
  {
  case 1:
    Buku *temp;
    temp = head;
    int j = 0;
    while (temp != NULL)
    {
      j++;
      temp = temp->next;
      continue;
    }
    printList(&tail, j);
    printf("\nFinish printing book database.");
    clearScreen();
    goto menu;
    break;

  case 2:
    addBook(judul, penulis, penerbit, tahun, genre);
    node = createNewNode(judul, penulis, penerbit, tahun, genre);
    linkNode(&head, &node, &tail);
    clearScreen();
    goto menu;
    break;

  case 3:
    deleteBook(&head);
    reWrite(&head);
    clearScreen();
    goto menu;
    break;

  case 4:
    totalBuku(&head);
    clearScreen();
    goto menu;
    break;

  case 5:
    searchBook(&head, &node, &tail, judul);
    clearScreen();
    goto menu;
    break;

  case 6:
    printf("\nTerima kasih telah menggunakan sistem manajemen perpustakaan.\n");
    break;
  }
  return 0;
}
