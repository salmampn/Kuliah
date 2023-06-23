#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

typedef struct Student{
    char nama[50], prodi[20];
    int nilai;
}Student;

void clearScreen()
{
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void loadData(Student mahasiswa[], int *n){
    FILE *fp = fopen("database_nilai.txt","r");   
    int i=0;
    while (!feof(fp)){
        fscanf(fp, "%[^😭]😭%[^😭]😭%d\n", mahasiswa[i].nama, mahasiswa[i].prodi, &mahasiswa[i].nilai);
        i++;
    }
    *n = i;
    fclose(fp);
}

void nameInsertionSort(Student mahasiswa[], int *n){
    int i, j;
    Student temp;
    for(i=0;i<*n;i++){
        strcpy(temp.nama, mahasiswa[i].nama); 
        for(j=i-1; j>=0 && strcmp(mahasiswa[j].nama, temp.nama) > 0; j--){
            strcpy(mahasiswa[j+1].nama, mahasiswa[j].nama);
        }
        strcpy(mahasiswa[j+1].nama, temp.nama);
    }
}

void printMahasiswa(Student mahasiswa[], int *n){
    int i = 0;
    printf("\n                            List of Student Information                              \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("|No.|                  Name                  |        Jurusan        |  Nilai  |");
    printf("\n--------------------------------------------------------------------------------\n");
    for(i=0; i<*n; i++){

        printf("|%-3d|%-40s|%-23s|%-9d|\n", i + 1, mahasiswa[i].nama, mahasiswa[i].prodi, mahasiswa[i].nilai);
        fflush(stdin);
    }
    printf("--------------------------------------------------------------------------------\n\n");
}

int binarySearch(Student mahasiswa[], int left, int right){
    char target[20];
    printf("Masukkan nama yang ingin dicari:\n");
    scanf("%[^\n]", target);

    while (left <= right){
        int mid = left + (right - left) / 2;
        
        int compare = strcmp(mahasiswa[mid].nama, target);
        if (compare == 0){
            return mid; // Found the target student
        }
        else if (compare < 0){
            left = mid + 1; // Search in the right half
        }
        else{
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target student not found
}

int main(){
    Student mahasiswa[100];
    int choice = 0, n = 0;
    int found;

    loadData(mahasiswa, &n);
    nameInsertionSort(mahasiswa, &n);
    
    system("cls");
    menu:
    printf("Manajemen Nilai Mahasiswa\n");
    printf("1. Tampilkan Semua Mahasiswa\n");
    printf("2. Cari Mahasiswa\n");
    printf("3. Keluar Program\n");
    printf("\nMasukkan pilihan Anda: ");
    scanf("%d", &choice);
    fflush(stdin);

    switch(choice){
        case 1:
            printMahasiswa(mahasiswa, &n);
            sleep(1);
            clearScreen();
            goto menu;
            break;
        case 2: 
            system("cls");
            int size = n;
            found = binarySearch(mahasiswa, 0, size);
            if(found != -1){
                printf("\nMahasiswa ditemukan!\n");
                printf("Nama\t: %s\nJurusan\t: %s\nNilai\t: %d\n\n", mahasiswa[found].nama, mahasiswa[found].prodi, mahasiswa[found].nilai);
            }
            else{
                printf("Tidak ditemukan\n");
            }
            sleep(1);
            clearScreen();
            goto menu;
            break;
        default: 
            printf("\nTerima kasih telah menggunakan aplikasi ini!");
            sleep(1.5); 
            break;
                
    }
    return 0;
}