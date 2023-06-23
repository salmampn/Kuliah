#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct MinHeap{
    int *hArr;
    int capacity;
    int heapSize;
}MinHeap;

// Function to create a new heap
MinHeap createHeap(int cap){
    MinHeap newHeap;
    newHeap.heapSize = 0;
    newHeap.capacity = cap;
    newHeap.hArr = malloc(sizeof(int)*cap);
    int i;
    for(i = 0; i < cap; i++){
        newHeap.hArr[i] = 0;
    }
    return newHeap;
}

// Function to find the index of the parent
int parent(int i){
    return (i-1)/2;
}

// Funtion to find the index of the left child
int left(int i){
    return (2*i +1);
}

// Funtion to find the index of the right child
int right(int i){
    return (2*i + 2);
}

// Function to swap 2 numbers
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to insert new nummber to heap
void insertKey(MinHeap *mHeap, int k){
    printf("Current Heap Size = %d\n\n", mHeap->heapSize);
    printf("Inserting %d to heap\n", k);
    if(mHeap->heapSize == mHeap->capacity){
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    //First, insert the new number to the last index of the heap
    mHeap->heapSize++;
    int i = mHeap->heapSize - 1;
    mHeap->hArr[i] = k;

    // Fix the property from the min heap
    // If the new number doesn't fit the min heap criteria
    while(i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i]){
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

int getMin(MinHeap *mHeap){
    return mHeap->hArr[0];
}

void printHeap(MinHeap mHeap){
    printf("Current heap : ");
    for(int i = 0;i<mHeap.heapSize;i++){
        printf("%d ", mHeap.hArr[i]);
    }
    printf("\n");
}

int main(){
    MinHeap mHeap;
    mHeap = createHeap(11);

    printHeap(mHeap);
    insertKey(&mHeap, 3);
    printHeap(mHeap);
    insertKey(&mHeap, 2);
    printHeap(mHeap);
    insertKey(&mHeap, 1);
    printHeap(mHeap);
    insertKey(&mHeap, 15);
    printHeap(mHeap);
    insertKey(&mHeap, 5);
    printHeap(mHeap);
    insertKey(&mHeap, 4);
    printHeap(mHeap);
    insertKey(&mHeap, 45);
    printHeap(mHeap);
    printf("Min Value in Heap: %d \n", getMin(&mHeap));

    return 0;

}