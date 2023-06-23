#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

/* Fungsi untuk membuat node baru dan insert ke belakang LinkedList */
void insertNode(int val, LinkedList **head)
{
    // **head merupakan bucket[i]

    // Buat node baru
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->value = val;
    newNode->next = NULL;

    // Jika bucket[i] masih kosong
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    // Jika bucket[i] sudah ada isinya
    {
        LinkedList *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    int i, j, n, data[100], maks;

    /*
    *bucket sebagai head pada Radix Sort
    karena menginginkan sort integer 0-9
    jadi terdapat 10 head alias Array of Linked List
    */
    LinkedList *bucket[10];
    for (i = 0; i < 10; i++)
    {
        bucket[i] = NULL;
    }

    // Input data
    printf("Masukan jumlah data yang akan di sort: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &data[i]);
        if (i == 0 || maks < data[i])
        {
            maks = data[i];
        }
    }

    // Menentukan jumlah iterasi
    int totalIterasi = 0;
    while (maks > 0)
    {
        maks /= 10;
        totalIterasi++;
    }
    printf("\nTotal iterasi yang akan dilakukan adalah: %d\n", totalIterasi);

    int pembagi = 1;

    // Iterasi sebanyak totalIterasi
    for (i = 0; i < totalIterasi; i++)
    {
        // Masukkan data dari array ke bucket yang sesuai
        for (j = 0; j < n; j++)
        {
            int digit = (data[j] / pembagi) % 10;
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        // Output isi sementara bucket
        printf("\n====\nIterasi %d\n", i + 1);
        for (j = 0; j < 10; j++)
        {
            printf("Bucket[%d]: ", j);
            LinkedList *temp = bucket[j];
            while (temp != NULL)
            {
                printf("%d ", temp->value);
                temp = temp->next;
            }
            printf("\n");
        }

        // Pindahkan kembali data dari bucket ke dalam array
        int idx = 0;
        for (j = 0; j < 10; j++)
        {
            LinkedList *temp = bucket[j];
            while (temp != NULL)
            {
                data[idx] = temp->value;
                idx++;
                temp = temp->next;
            }
        }

        // Output isi sementara array
        printf("Isi sementara array\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", data[j]);
        }
        printf("\n");

        // Kosongkan bucket
        for (j = 0; j < 10; j++)
        {
            LinkedList *trash, *temp = bucket[j];
            while (temp != NULL)
            {
                trash = temp;
                temp = temp->next;
                free(trash);
            }
            bucket[j] = NULL;
        }
    }

    // Output hasil sorting
    printf("\nHasil setelah di sort\n");
    for (j = 0; j < n; j++)
    {
        printf("%d ", data[j]);
    }

    return 0;
}