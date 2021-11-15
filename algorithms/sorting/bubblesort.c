#include <stdio.h>

void swap(int* f, int* s) {
	int temp = *f;
	*f = *s;
	*s = temp; 
}

void bubblesort(int a[], int n) {
	int is_sorted = 0;

	for (int i = 0; i < n-1 && !is_sorted; i++) {
		for (int j = 0; j < n-i-1; j++) {
			int is_swapped = 0;
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				is_swapped = 1;
			}
			// optimization
			if (!is_swapped)
				is_sorted = 1;
		}
	}
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


int main(void) {
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	bubblesort(arr, n);
	printArray(arr, n);
}	