#include <stdio.h>
#include <stdlib.h>

void shellSort(int *bil, int n) {
    int i, j, gap;

    // Mulai dari gap besar (n/2), lalu kurangi gapnya (gap /= 2)
    // NOTE: Tidak harus menggunakan angka 2 sebagai pembagi
    // Bisa gunakan angka yang lebih besar untuk perpindahan yang lebih jauh
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Lakukan insertion sort untuk gap size ini
        for (i = gap; i < n; i++) {
            // Simpan bil[i] ke temp
            int temp = bil[i];

            // Pindahkan nilai yang besar ke tempat yang seharusnya
            for (j = i; j >= gap && bil[j - gap] > temp; j -= gap) {
                bil[j] = bil[j - gap];
            }
            // Taruh temp ke lokasi yang benar
            bil[j] = temp;
        }
    }
}

int main() {
    int i, n, *bil;

    printf("SHELL SORT ASCENDING\n\n");
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
    }
    shellSort(bil, n);
    printf("Hasil shell sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", bil[i]);
    }
    free(bil);
    return 0;
}
