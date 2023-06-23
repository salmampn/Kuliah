#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct student
{
    char nama[50];
    char major[40];
    int nim;
    int tugas;
    int uts;
    int uas;
    float akhir;
    char grade[3];
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

struct student exe[100];
struct student umn;
int i = 0;

void inputData()
{
    FILE *data;
    FILE *nilai;

    data = fopen("dataMahasiswa.txt", "a");
    nilai = fopen("nilaiMahasiswa.txt", "a");

    printf("\n");
    printf("  Masukkan Data Mahasiswa  \n");
    printf("---------------------------\n");
    printf("Nama\t: ");
    fflush(stdin);
    scanf(" %49[^\n]", umn.nama);
    printf("Major\t: ");
    fflush(stdin);
    scanf(" %39[^\n]", umn.major);
    printf("NIM\t: ");
    fflush(stdin);
    scanf("%d", &umn.nim);
    printf("Tugas: ");
    fflush(stdin);
    scanf("%d", &umn.tugas);
    printf("UTS: ");
    fflush(stdin);
    scanf("%d", &umn.uts);
    printf("UAS: ");
    fflush(stdin);
    scanf("%d", &umn.uas);
    fprintf(data, "%d#%s#%s\n", umn.nim, umn.nama, umn.major);
    umn.akhir = (umn.tugas * 0.3) + (umn.uts * 0.3) + (umn.uas * 0.4);
    if (umn.akhir >= 95)
    {
        strcpy(umn.grade, "A+");
    }
    else if (umn.akhir >= 85)
    {
        strcpy(umn.grade, "A");
    }
    else if (umn.akhir >= 80)
    {
        strcpy(umn.grade, "A-");
    }
    else if (umn.akhir >= 75)
    {
        strcpy(umn.grade, "B+");
    }
    else if (umn.akhir >= 70)
    {
        strcpy(umn.grade, "B");
    }
    else if (umn.akhir >= 65)
    {
        strcpy(umn.grade, "C+");
    }
    else if (umn.akhir >= 60)
    {
        strcpy(umn.grade, "C");
    }
    else if (umn.akhir >= 40)
    {
        strcpy(umn.grade, "D");
    }
    else
    {
        strcpy(umn.grade, "E");
    }

    fprintf(nilai, "%d#%d#%d#%.2f#%s\n", umn.tugas, umn.uts, umn.uas, umn.akhir, umn.grade);
    exe[i] = umn;
    i++;

    fclose(data);
    fclose(nilai);

    printf("Memasukan data....\n");
    printf("Data mahasiswa berhasil ditambahkan\n\n\n");
}

void cetak()
{
    FILE *data;
    FILE *nilai;

    data = fopen("dataMahasiswa.txt", "r");
    nilai = fopen("nilaiMahasiswa.txt", "r");
    if (data == NULL || nilai == NULL)
    {
        printf("file tidak ditemukan\n");
        return;
    }

    printf("Data Mahasiswa:\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| No. |            Nama           |          NIM         |           Major           |  Nilai   | Grade |\n");
    printf("|     |                           |                      |                           |  Akhir   |       |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    int no = 1;
    while (fscanf(data, "%d#%[^#]#%[^\n]%*c\n", &umn.nim, umn.nama, umn.major) != EOF)
    {
        fscanf(nilai, "%d#%d#%d#%f#%s\n", &umn.tugas, &umn.uts, &umn.uas, &umn.akhir, umn.grade);
        printf("|%4d | %-25s | %-20d | %-25s | %7.2f | %-6s |\n", no, umn.nama, umn.nim, umn.major, umn.akhir, umn.grade);
        printf("---------------------------------------------------------------------------------------------------------\n");
        no++;
    }

    printf("\n\n\n");
    fclose(data);
    fclose(nilai);
}

int jumpSearch(int nim)
{
    int start, jump, k;

    start = 0;
    jump = sqrt(i);
    printf("\nAkar kuadrat terdekat dari %d = %d", i, jump);

    while(nim >= exe[jump].nim && jump < i)
    {
        //printf("\ntest\n");
        start = jump;
        jump += sqrt(i);
        //printf("test\n");
        if(jump > i - 1)
        {
            jump = i;
            //printf("test\n");
        }

        for(k = start; k < jump; k++)
        {
            if(nim == exe[k].nim)
            {
                //printf("test\n");
                return k;
            }
        }
    }

    return -1;
}

void shellSort()
{
    int d, j, gap;

    for (gap = i / 2; gap > 0; gap /= 2)
    {
        for (d = gap; d < i; d++)
        {
            struct student temp = exe[d];
            for (j = d; j >= gap && exe[j - gap].nim > temp.nim; j -= gap)
            {
                exe[j] = exe[j - gap];
            }
            exe[j] = temp;
        }
    }
}

int interpolationSearch(int nim)
{
    int low, pos, high;

    low = 0;
    high = i - 1;

    do
    {
        pos = low + ((nim - exe[low].nim) * (high - low) / (exe[high].nim - exe[low].nim));

        if (nim == exe[pos].nim)
        {
            return pos;
        }
        else if (nim < exe[pos].nim)
        {
            high = pos - 1;
        }
        else if (nim > exe[pos].nim)
        {
            low = pos + 1;
        }
    } while (nim >= exe[low].nim && nim <= exe[high].nim);

    return -1;
}

int binarySearch(int nim)
{
    int low, mid, high;

    low = 0;
    high = i - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (exe[mid].nim == nim)
        {
            return mid;
        }
        else if (nim < exe[mid].nim)
        {
            high = mid - 1;
        }
        else if (nim > exe[mid].nim)
        {
            low = mid + 1;
        }
    }

    return -1;
}


void details() {
    FILE *data;
    FILE *nilai;

    data = fopen("dataMahasiswa.txt", "r");
    nilai = fopen("nilaiMahasiswa.txt", "r");
    if (data == NULL || nilai == NULL) {
        printf("File tidak ditemukan\n");
        return;
    }

    while (fscanf(data, "%d#%[^#]#%[^\n]%*c\n", &exe[i].nim, exe[i].nama, exe[i].major) != EOF) {
        fscanf(nilai, "%d#%d#%d#%f#%s\n", &exe[i].tugas, &exe[i].uts, &exe[i].uas, &exe[i].akhir, exe[i].grade);
        i++;
    }

    fclose(data);
    fclose(nilai);

    printf("--------------------\n");
    printf("  Metode Pencarian\n");
    printf("--------------------\n");
    printf("------------------------------------------\n");
    printf("|1.   Binary Search                      |\n");
    printf("|2.   Interpolation Search               |\n");
    printf("|3.   Jump Search                        |\n");
    printf("|4.   Keluar                             |\n");
    printf("------------------------------------------\n");
    int pilihan;
    printf("Pilih: ");
    scanf("%d", &pilihan);
    int nim;
    printf("\nMasukkan NIM: ");
    scanf("%d", &nim);
    system("cls");

    if (pilihan == 1) {
        int found = 0;
        shellSort();
        found = binarySearch(nim);
        if (found != -1) {
            printf("\n");
            printf("--------------------------------------------------------------------------------------------------------\n");
            printf("| No. |            Nama           |          NIM         |           Major           |  Nilai  | Grade |\n");
            printf("|     |                           |                      |                           |  Akhir  |       |\n");
            printf("--------------------------------------------------------------------------------------------------------\n");
            printf("|%4d | %-25s | %-20d | %-25s | %-9.2f | %-6s |\n", found + 1, exe[found].nama, exe[found].nim, exe[found].major, exe[found].akhir, exe[found].grade);
            printf("--------------------------------------------------------------------------------------------------------\n");
            printf("\nNIM %d ditemukan pada index ke-%d\n", nim, found);
        } else {
            printf("NIM %d tidak ditemukan\n", nim);
        }
    } else if (pilihan == 2) {
        int found = 0;
        shellSort();
        found = interpolationSearch(nim);
        if (found != -1) {
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("| No. |            Nama           |          NIM         |           Major           |  Nilai   | Grade |\n");
            printf("|     |                           |                      |                           |  Akhir   |       |\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("|%4d | %-25s | %-20d | %-25s | %7.2f | %-6s |\n", found + 1, exe[found].nama, exe[found].nim, exe[found].major, exe[found].akhir, exe[found].grade);
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("\nNIM %d ditemukan pada index ke-%d\n", nim, found);
        } else {
            printf("NIM %d tidak ditemukan\n", nim);
        }
    } else if (pilihan == 3) {
        int found = 0;
        shellSort();
        found = jumpSearch(nim);
        if (found != -1) {
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("| No. |            Nama           |          NIM         |           Major           |  Nilai   | Grade |\n");
            printf("|     |                           |                      |                           |  Akhir   |       |\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("|%4d | %-25s | %-20d | %-25s | %7.2f  | %-6s |\n", found + 1, exe[found].nama, exe[found].nim, exe[found].major, exe[found].akhir, exe[found].grade);
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("\nNIM %d ditemukan pada index ke-%d\n", nim, found);
        } else {
            printf("NIM %d tidak ditemukan\n", nim);
        }
    } else if (pilihan == 4) {
        exit(0);
    } else {
        printf("\nAnda salah memilih Metode...\n");
    }

    int pilihan_lanjutan;
    printf("\n\n1. Kembali ke Menu Utama\n");
    printf("2. Keluar\n");
    printf("Pilih: ");
    scanf("%d", &pilihan_lanjutan);

    if (pilihan_lanjutan == 1) {
        system("cls");
        details();
    } else if (pilihan_lanjutan == 2) {
        printf("Anda telah keluar dari program ini...\n");
        exit(0);
    } else {
        printf("Anda salah memilih menu...\n");
    }
    system("cls");
}

int main()
{
    FILE *data;
    FILE *nilai;
    data = fopen("dataMahasiswa.txt", "r");
    nilai = fopen("nilaiMahasiswa.txt", "r");
    if (data == NULL || nilai == NULL)
    {
        inputData();
    }

    char line[100];
    while(fscanf(data, "%d#%[^#]#%[^\n]\n", &exe[i].nim, exe[i].nama, exe[i].major) != EOF)
    {
        fscanf(nilai, "%d#%d#%d#%f#%s\n", &exe[i].tugas, &exe[i].uts, &exe[i].uas, &exe[i].akhir, exe[i].grade);
        i++;
    }

    fclose(data);
    fclose(nilai);

    while (1)
    {
        printf("Total Data Mahasiswa (%d/100)\n", i);
        printf("\n------------------------------------------\n");
        printf("\n|1.   Tampilkan Data Mahasiswa           |\n");
        printf("\n|2.   Tambahkan Data                     |\n");
        printf("\n|3.   Show Student Detail                |\n");
        printf("\n|4.   Exit                               |\n");
        printf("\n------------------------------------------\n");

        int menu;
        printf("Pilih Menu: ");
        scanf("%d", &menu);
        int p = menu;
        system("cls");
        if (p == 1)
        {
            cetak();
        }
        else if (p == 2)
        {
            inputData();
        }
        else if (p == 3)
        {
            details();
        }
        else if (p == 4)
        {
            printf("Terimakasih...\n");
            exit(0);
        }
        else
        {
            printf("\nAnda salah memilih menu...\n");
        }
    }

    return 0;
}
