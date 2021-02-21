#include <stdio.h>

void insertionSort(int arr[], int n) {
	for (int j = 1; j < n; j++) {

		int key = arr[j];
		int i = j-1;

		while (i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i--;
		}

		arr[i+1] = key;
	}

}

void printArray(int arr[], int n) { 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main(void) {
	int arr[5] = { 30, 25, 20, 15, 10 };
	printArray(arr, 5);
	insertionSort(arr, 5);
	printArray(arr, 5);

}