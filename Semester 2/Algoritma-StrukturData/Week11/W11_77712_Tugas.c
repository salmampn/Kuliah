#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble Sort
void bubbleSort(int *bil, int n){
    int i, j;
    for(i = 1; i<n; i++){
        for(j=n-1; j>=1; j--){
            if(bil[j] > bil[j-1]){
                swap(&bil[j], &bil[j-1]);
            }
        }
    }
}

//Selection Sort
void selectionSort(int *bil, int n){
    int i,j, temp;
    for(i = 0; i<n; i++){
        temp = i;
        for(j = i+1; j<n; j++){
            if(bil[j] > bil[temp]){
                temp = j;
            }
        }
        if(temp != i){
            swap(&bil[temp], &bil[i]);
        }
    }
}

//Insertion Sort
void insertionSort(int *bil, int n){
    int i, j, temp;
    for(i=0;i<n;i++){
        temp = bil[i];
        for(j=i-1; j>=0 && bil[j] < temp;j--){
            bil[j+1] = bil[j];
        }
        bil[j+1] = temp;
    }
}

//Radix Sort
typedef struct LinkedList{
    int value;
    struct LinkedList *next;
} LinkedList;

void insertNode(int val, LinkedList **head){
    LinkedList *newNode = (LinkedList *) malloc(sizeof(LinkedList));
    newNode->value = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        LinkedList *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main(){
    int i, n, menu, *bil;

    system("cls");
menu:
    printf("\nWelcome to simple sorting program\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Radix Sort\n5. Exit\nChoice: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        // Bubble Sort
        printf("\nBanyak bilangan: ");
        scanf("%d", &n);
        bil = malloc(sizeof(n));
            for(i = 0; i < n ;i++){
            printf("Input bilangan ke-%d: ", i+1);
            scanf("%d", &bil[i]);
        }
        printf("\n");

        bubbleSort(bil, n);
        printf("Hasil bubble sort:");
        for(i = 0; i<n; i++){
            printf("%d ", bil[i]);
        }
        printf("\n");
        goto menu;
        break;

    case 2:
        //Selection Sort
        printf("\nBanyak bilangan: ");
        scanf("%d", &n);
        bil = malloc(sizeof(n));
            for(i = 0; i < n ;i++){
            printf("Input bilangan ke-%d: ", i+1);
            scanf("%d", &bil[i]);
        }
        printf("\n");

        selectionSort(bil,n);
        printf("Hasil selection sort:");
        for(i=0;i<n;i++){
            printf("%d ", bil[i]);
        }
        printf("\n");
        goto menu;
        break;
    
    case 3:
        //Insertion Sort
        printf("\nBanyak bilangan: ");
        scanf("%d", &n);
        bil = malloc(sizeof(n));
            for(i = 0; i < n ;i++){
            printf("Input bilangan ke-%d: ", i+1);
            scanf("%d", &bil[i]);
        }
        printf("\n");

        insertionSort(bil,n);
        printf("Hasil insertion sort:");
        for(i=0;i<n;i++){
            printf("%d ", bil[i]);
        }
        printf("\n");
        goto menu;
        break;

    case 4:
        //Radix Sort
        int j, data[100], maks;
        LinkedList *bucket[10];
        for(i = 0;i<10;i++){
            bucket[i] = NULL;
        }
        printf("\nMasukkan jumlah data yang akan disort: ");
        scanf("%d", &n);
        for(i=0;i<n;i++){
            printf("Input bilangan ke-%d: ", i+1);
            scanf("%d", &data[i]);
            if(i == 0 || maks < data[i]){
                maks = data[i];
            }
        }
        int totalIterasi = 0;
        while(maks > 0){
            maks /= 10;
            totalIterasi++;
        }
        printf("\nTotal iterasi yang akan dilakukan adalah: %d\n", totalIterasi);
        int pembagi = 1;
        for(i = 0; i<totalIterasi; i++){
            for(j = 0;j<n;j++){
                int digit = (data[j]/pembagi) % 10;
                insertNode(data[j], &bucket[digit]);
            }
            pembagi *= 10;
            printf("\n====\nIterasi %d\n", i+1);
            for(j=0;j<10;j++){
                printf("Bucket[%d]: ",j);
                LinkedList *temp = bucket[j];
                while(temp != NULL){
                    printf("%d ", temp->value);
                    temp = temp->next;
                }
                printf("\n");
            }
            int idx = 0;
            for(j = 0;j<10;j++){
                LinkedList *temp = bucket[j];
                while(temp != NULL){
                    data[idx] = temp->value;
                    idx++;
                    temp = temp->next;
                }
            }
            printf("Isi sementara array\n");
            for(j=1;j<n+1;j++){
                printf("%d ", data[n-j]);
            }
            printf("\n");
            for(j = 0;j<10;j++){
                LinkedList *trash, *temp = bucket[i];
                while(temp != NULL){
                    trash = temp;
                    temp = temp->next;
                    free(trash);
                }
                bucket[j] = NULL;
            }
            
        }
        printf("\nHasil setelah disort\n");
        for(j=1;j<n+1;j++){
            printf("%d ", data[n-j]);
        }
        printf("\n");
        goto menu;
        break;

    default:
        break;
    }
    
    free(bil);
    return 0;
}