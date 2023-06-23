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

void merge(int *bil, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = bil[l+i];
    for(j = 0; j < n2; j++)
        R[j] = bil[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]>R[j]){
            bil[k] = L[i];
            i++;
        }
        else{
            bil[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        bil[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        bil[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *bil, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(bil,l,m);
        mergeSort(bil,m+1,r);
        merge(bil,l,m,r);
    }
}

int partition(int *bil, int l, int r){
    int pivot = bil[r];
    int i = l-1;
    for(int j = l; j<=r-1 ; j++){
        if(bil[j]>pivot){
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i+1], &bil[r]);
    return (i+1);
}

void quickSort(int *bil, int l, int r){
    if(l<r){
        int pi = partition(bil, l, r);
        quickSort(bil, l, pi-1);
        quickSort(bil, pi+1, r);
    }
}

void shellSort(int *bil, int n) {
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            int temp = bil[i];
            for (j = i; j >= gap && bil[j - gap] < temp; j -= gap) {
                bil[j] = bil[j - gap];
            }
            bil[j] = temp;
        }
    }
}

int main(){
    int i, n, *bil;
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }
    heapSort(bil,n);
    printf("\nHasil heap sort:\n");
    for(i=0;i<n;i++){
        printf("%d ", bil[i]);
    }
    mergeSort(bil,0,n-1);
    printf("\n\nHasil merge sort:\n");
    for(i=0;i<n;i++){
        printf("%d ", bil[i]);
    }
    quickSort(bil, 0, n-1);
    printf("\n\nHasil quick sort:\n");
    for(i=0;i<n;i++){
        printf("%d ", bil[i]);
    }
    shellSort(bil, n);
    printf("\n\nHasil shell sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", bil[i]);
    }
    free(bil);
    return 0;
}
