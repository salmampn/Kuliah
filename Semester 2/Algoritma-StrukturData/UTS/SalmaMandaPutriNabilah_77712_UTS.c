#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <unistd.h>

/*
Nama    : Salma Manda Putri Nabilah
NIM     : 00000077712
Kelas   : IF232 - HL
Nilai   :
*/

//Initialize node data structure
typedef struct Buku
{
  char judul[100];
  char penulis[50];
  char penerbit[50];
  char tahun[5];
  char genre[20];
  struct Buku *next, *prev;
} Buku;

//Function to clear screen
void clearScreen()
{
  printf("\nPress any key to continue...");
  getch();
  system("cls");
}

// Start of Case 1
void printList(Buku **head, int j)
{
  Buku *temp = (*head);
  int i = 1;
  int menu;
  int endReached = 0;
  int startReached = 0;

  while (temp != NULL)
  {
    printf("\nBuku ke-%d dari %d\n", i, j);
    printf("======================================================================\n");
    printf("Judul Buku\t: %s\n", temp->judul);
    printf("Penulis Buku\t: %s\n", temp->penulis);
    printf("Tahun Terbit\t: %s\n", temp->tahun);
    printf("Penerbit\t: %s\n", temp->penerbit);
    printf("Genre\t\t: %s\n", temp->genre);
    printf("======================================================================\n");

    if (temp->next == NULL)
    {
      printf("1. Buku Selanjutnya\n2. Buku Sebelumnya\n3. Kembali ke Menu Utama\n\nPilihan Anda: ");
      scanf("%d", &menu);

      if (menu == 1)
      {
        if (temp->next != NULL)
        {
          temp = temp->next;
          i++;
        }
        else{
          endReached = 1;
        }
      }
      else if (menu == 2)
      {
        temp = temp->prev;
        i--;
        if (temp == NULL)
        {
          temp = (*head);
          startReached = 1;
        }
      }
      else if (menu == 3)
      {
        return;
      }
      else
      {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        sleep(1);
      }
    }
    else if (temp->prev == NULL)
    {
      printf("1. Buku Selanjutnya\n2. Buku Sebelumnya\n3. Kembali ke Menu Utama\n\nPilihan Anda: ");
      scanf("%d", &menu);

      if (menu == 1)
      {
        temp = temp->next;
        i++;
        if (temp == NULL)
        {
          endReached = 1;
        }
      }
      else if (menu == 2)
      {
        if (temp->prev != NULL)
        {
          temp = temp->prev;
          i--;
        }
        else
        {
          temp = (*head);
          startReached = 1;
        }
      }
      else if (menu == 3)
      {
        return;
      }
      else
      {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
      }
    }
    else
    {
      printf("1. Buku Selanjutnya\n2. Buku Sebelumnya\n3. Kembali ke Menu Utama\n\nPilihan Anda: ");
      scanf("%d", &menu);

      if (menu == 1)
      {
        temp = temp->next;
        i++;
        if (temp == NULL)
        {
          endReached = 1;
        }
      }
      else if (menu == 2)
      {
        if (temp->prev != NULL)
        {
          temp = temp->prev;
          i--;
        }
        else
        {
          temp = (*head);
          startReached = 1;
        }
      }
      else if (menu == 3)
      {
        return;
      }
      else
      {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
      }
    }

    if (endReached)
    {
      printf("Anda telah mencapai akhir daftar buku.\n");
      sleep(1);
      endReached = 0;
    }
    else if (startReached)
    {
      printf("Anda telah mencapai awal daftar buku.\n");
      sleep(1);
      startReached = 0;
    }
  }
}
// End of Case 1

// Start of Case 2
void addBook(char judul[100], char penulis[50], char penerbit[50], char tahun[5], char genre[20])
{
  FILE *fout = fopen("data_buku.txt", "a");
  printf("\nMasukkan judul buku\t: ");
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
  if ((*head) == NULL)
  {
    printf("Tidak ada buku yang dapat dihapus lagi\nBuku diperpustakaan kosong\n");
  }
  else
  {
    fflush(stdin);
    printf("\nThis will delete the first book on the list.\n");
    printf("You sure you want to continue? (1 = Yes, 0 = No): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
      (*head) = (*head)->next;
      if ((*head) != NULL)
      {
        (*head)->prev = NULL;
      }
      printf("\nDeleteing the first book on the list...\n");
      sleep(1);
      printf("Data buku dengan judul '%s' berhasil dihapus...\n", trash->judul);
      fflush(stdin);
      free(trash);
    }
    else
    {
      printf("Book deletion canceled.\n");
      sleep(1);
    }
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
  printf("\nCounting total books in the database...\n");
  sleep(1);
  printf("Terdapat %d buku di dalam database perpustakaan\n", i);
  sleep(1);
}
// End of Case 4

// Start of Case 5
void searchBook(Buku **head, Buku **node, Buku **tail, char judul[100])
{
  Buku *temp;
  temp = (*head);
  int found = 0; // Variabel untuk menandakan apakah buku ditemukan
  printf("\nPerhatikan penggunaan huruf kapital dari judul buku.\n");
  printf("Masukkan keyword judul buku yang dicari: ");
  fflush(stdin);
  scanf(" %[^\n]", judul); // Menambahkan spasi sebelum format specifier %[^\n] agar karakter newline tidak terbaca pada iterasi selanjutnya

  printf("\nFinding books in the database...\n");
  sleep(1);

  while (temp != NULL)
  {
    if (strstr(temp->judul, judul) != NULL) // Menggunakan fungsi strstr() untuk mencari keyword judul dalam judul buku
    {
      found = 1;
      printf("\nBooks found in the system!\n\n");
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
    }
    temp = temp->next;
  }

  if (!found)
  {
    printf("Books not found.\n");
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
  //Read books from the database
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

  printf("1. Tampilkan Semua Buku\n2. Tambah Buku\n3. Hapus Buku\n4. Total Buku\n5. Cari Buku\n6. Keluar\nPilihan Anda: ");
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
    printList(&head, j);
    printf("\nFinish printing book database.");
    sleep(1);
    clearScreen();
    goto menu;
    break;

  case 2:
    addBook(judul, penulis, penerbit, tahun, genre);
    node = createNewNode(judul, penulis, penerbit, tahun, genre);
    linkNode(&head, &node, &tail);
    printf("\nInserting new book...\n");
    sleep(1);
    printf("New book added to the list.\n");
    sleep(1);
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

  default:
    printf("\nTerima kasih telah menggunakan sistem manajemen perpustakaan.\n");
    sleep(1);
    break;
  }
  return 0;
}
