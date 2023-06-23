#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

/*
Nama : Salma Manda Putri Nabilah
NIM : 00000077712
Kelas : HL
Nilai : (kosongkan)
*/

typedef struct Playlist{
    char judul[50];
    char artis[50];
    char album[50];
    int tahun;
}Playlist;

void clearScreen()
{
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void loadData(Playlist lagu[], int *n){
    FILE *fp = fopen("database-musik.txt","r");   
    int i=0;
    while (!feof(fp)){
        fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", lagu[i].judul, lagu[i].artis, lagu[i].album, &lagu[i].tahun);
        i++;
    }
    *n = i;
    fclose(fp);
}

void judulInsertionSort(Playlist lagu[], int *n){
    int i, j;
    Playlist temp;
    for(i=0;i<*n;i++){
        strcpy(temp.judul, lagu[i].judul); 
        strcpy(temp.artis, lagu[i].artis);
        strcpy(temp.album, lagu[i].album);
        temp.tahun = lagu[i].tahun;
        for(j=i-1; j>=0 && strcmp(lagu[j].judul, temp.judul) > 0; j--){
            strcpy(lagu[j+1].judul, lagu[j].judul);
            strcpy(lagu[j+1].artis, lagu[j].artis);
            strcpy(lagu[j+1].album, lagu[j].album);
            lagu[j + 1].tahun = lagu[j].tahun;
        }
        strcpy(lagu[j+1].judul, temp.judul);
        strcpy(lagu[j+1].artis, temp.artis);
        strcpy(lagu[j+1].album, temp.album);
        lagu[j+1].tahun = temp.tahun;
    }
}

void yearInsertionSort(Playlist lagu[], int *n){
    int i, j;
    Playlist temp;
    for(i=0;i<*n;i++){
        strcpy(temp.judul, lagu[i].judul); 
        strcpy(temp.artis, lagu[i].artis);
        strcpy(temp.album, lagu[i].album);
        temp.tahun = lagu[i].tahun;
        for(j=i-1; j >= 0 && lagu[j].tahun > temp.tahun ;j--){
            strcpy(lagu[j+1].judul, lagu[j].judul);
            strcpy(lagu[j+1].artis, lagu[j].artis);
            strcpy(lagu[j+1].album, lagu[j].album);
            lagu[j + 1].tahun = lagu[j].tahun;
        }
        strcpy(lagu[j+1].judul, temp.judul);
        strcpy(lagu[j+1].artis, temp.artis);
        strcpy(lagu[j+1].album, temp.album);
        lagu[j + 1].tahun = temp.tahun;
    }
}

void printPlaylist(Playlist lagu[], int *n){
    int i = 0;
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                          YOUR PLAYLIST                                                           |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|No.|               Song Title                |        Singer       |                    Album                     | Released Year |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<*n; i++){
        
        printf("|%-3d| %-40s| %-20s| %-45s| %-14d|\n", i + 1, lagu[i].judul, lagu[i].artis, lagu[i].album, lagu[i].tahun);
        printf("------------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
    }
}

void searchByKeyword(Playlist lagu[], int n){
    char keyword[30];
    printf("Masukkan judul yang ingin dicari: ");
    scanf("%[^\n]", keyword);
    fflush(stdin);
    // getchar();  // Membersihkan karakter newline (\n) dari buffer

    printf("\nJudul lagu yang cocok dengan kata kunci '%s':\n", keyword);
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|No.|               Song Title                |        Singer       |                    Album                     | Released Year |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");

    int count = 0;
    for(int i = 0; i < n; i++){
        if(strstr(lagu[i].judul, keyword) != NULL){
            printf("|%-3d| %-40s| %-20s| %-45s| %-14d|\n", i + 1, lagu[i].judul, lagu[i].artis, lagu[i].album, lagu[i].tahun);
            printf("------------------------------------------------------------------------------------------------------------------------------------\n");
            fflush(stdin);
            count++;
        }
    }
    if(count == 0){
        printf("Judul lagu tidak ditemukan!\n");
    }
}

void searchByYear(Playlist lagu[], int n){
    int tahun;
    printf("Masukkan tahun rilis yang ingin dicari: ");
    scanf("%d", &tahun);
    fflush(stdin);

    printf("\nLagu - lagu dengan tahun rilis %d:\n", tahun);
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|No.|               Song Title                |        Singer       |                    Album                     | Released Year |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");

    int count = 0;
    for(int i = 0; i < n; i++){
        if( lagu[i].tahun == tahun){
            printf("|%-3d| %-40s| %-20s| %-45s| %-14d|\n", i + 1, lagu[i].judul, lagu[i].artis, lagu[i].album, lagu[i].tahun);
            printf("------------------------------------------------------------------------------------------------------------------------------------\n");
            fflush(stdin);
            count++;
        }
    }
    if(count == 0){
        printf("Tahun rilis lagu tidak ditemukan!\n");
    }
}

int main(){
    Playlist lagu[100];
    int choice = 0, n = 0;
    int found;

    loadData(lagu, &n);
    printPlaylist(lagu, &n);
    judulInsertionSort(lagu, &n);

    menu:
    printf("\nMenu: \n");
    printf("1. Sort\n");
    printf("2. Search\n");
    printf("3. Exit\n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    fflush(stdin);

    switch(choice){
        case 1:
        sortmenu:
            printf("\nPilih sort berdasarkan: \n");
            printf("1. Judul\n");
            printf("2. Tahun Rilis\n\n");
            printf("Pilihan: ");
            scanf("%d", &choice);
            fflush(stdout);
            if (choice == 1)
            {
                judulInsertionSort(lagu, &n);
                printPlaylist(lagu, &n);
                printf("\nPlaylist has been sorted based on the title of the songs.\n");
            }else if (choice == 2){
                yearInsertionSort(lagu, &n);
                printPlaylist(lagu, &n);
                printf("\nPlaylist has been sorted based on the release year of the songs.\n");
            }else{
                printf("Judul lagu tidak ditemukan!\n");
                printf("Input ulang pilihan!\n");
                goto sortmenu;
            }
            sleep(1);
            clearScreen();
            goto menu;
            break;
        case 2: 
            system("cls");
            int size = n;
        searchmenu:
            printf("\nPilih search berdasarkan: \n");
            printf("1. Judul\n");
            printf("2. Tahun Rilis\n\n");
            printf("Pilihan: ");
            scanf("%d", &choice);
            fflush(stdout);
            getchar();
            if (choice == 1){
                searchByKeyword(lagu, size);
            }else if (choice == 2){
                searchByYear(lagu, size);
            }else{
                printf("Pilihan tidak ditemukan!\n");
                printf("Input ulang pilihan!\n");
                goto searchmenu;
            }
            sleep(1);
            clearScreen();
            goto menu;
            break;
        default: 
            printf("\nTerima kasih telah menggunakan aplikasi ini!");
            sleep(1.5); 
            break;
                
    return 0;
    }
}
