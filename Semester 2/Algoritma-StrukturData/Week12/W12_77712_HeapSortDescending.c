#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int bil[], int n, int i) {
    int maks = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && bil[l] < bil[maks]) {
        maks = l;
    }
    if (r < n && bil[r] < bil[maks]) {
        maks = r;
    }
    if (maks != i) {
        swap(&bil[i], &bil[maks]);
        heapify(bil, n, maks);
    }
}

void heapSort(int *bil, int n) {
    int i;
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(bil, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&bil[0], &bil[i]);
        heapify(bil, i, 0);
    }
}

int main(){
    int i, n, *bil;

    printf("HEAP SORT DESCENDING\n\n");
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