#include <stdio.h>

int main(){
	int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
	int size = sizeof(numbers) / 4; // Size dari array numbers.
	int searchKey; // Key yang akan dicari
	int found = 0;
	int i;
	
// printf("Sizeof numbers = %d\n", size);
	printf("Masukkan angka yang ingin dicari: "); scanf("%d", &searchKey);
	
	// Linear Search
	for(i=0; i<size; i++){
    if(searchKey == numbers[i]){
      found = 1;
      break;  
    }
    }
    
    // Print hasil
    if(found){
      printf("Angka %d ditemukan pada index %d", searchKey, i);
    } else{
      printf("Angka %d tidak ditemukan pada array numbers", searchKey);
    }
    
    return 0;
}

