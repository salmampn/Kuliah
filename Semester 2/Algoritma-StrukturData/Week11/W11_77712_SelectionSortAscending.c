#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *bil, int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        // Menetapkan elemen di index ke-i sebagai nilai minimum
        temp = i;

        // Cek nilai minimum terhadap elemen selanjutnya
        for (j = i + 1; j < n; j++)
        {
            if (bil[j] < bil[temp])
            {
                temp = j;
            }
        }

        // Tukar nilai
        if (temp != i)
        {
            swap(&bil[temp], &bil[i]);
        }
    }
}

int main()
{
    int i, n, *bil;

    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
    }

    selectionSort(bil, n);

    printf("Hasil selection sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }

    free(bil);

    return 0;
}