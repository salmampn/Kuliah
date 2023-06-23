#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int bil[], int n, int i) {
    // int i akan menjadi index root sementara

    int maks = i; // Mengambil index root sebagai index max
    int l = 2 * i + 1; // Rumus untuk mengammbil index array akan kiri
    int r = 2 * i + 2; // Rumus untuk mengammbil index array akan kanan

    // Proses pengecekan, apakah nilai dari anak kiri > max ?
    if (l < n && bil[l] > bil[maks]) {
        maks = l;
    }

    // Proses pengecekan, apakah nilai dari anak kanan > max ?
    if (r < n && bil[r] > bil[maks]) {
        maks = r;
    }

    // Proses pengecekan, apakah max masih sama dengan root 
    if (maks != i) {
        swap(&bil[i], &bil[maks]);

        //Melakukan heapify kembali terhadap sub-tree yang terkena dampak swap
        heapify(bil, n, maks);
    }
}

void heapSort(int *bil, int n) {
    int i;

    // Melakukan heapify dimulai dari parent yang berada pada index terbesar
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(bil, n, i);
    }

    // Menukarkan elemen pada index[0] dengan index [(n--) - 1]
    // Satu persatu menghilangkan elemen dari heap
    // Sehingga tidak lagi terlibat dalam proses heapify
    for (int i = n - 1; i >= 0; i--) {
        // Menukarkan  elemen pada index[0] ke index [(n--) - 1]
        swap(&bil[0], &bil[i]);

        // Melakukan proses heapify
        heapify(bil, i, 0);
    }
}

int main(){
    int i, n, *bil;

    printf("HEAP SORT ASCENDING\n\n");
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }
    heapSort(bil,n);
    printf("Hasil heap sort:\n");
    for(i=0;i<n;i++){
        printf("%d ", bil[i]);
    }
    free(bil);
    return 0;
}