#include <stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int *arr, int n) {
	for (int i = 0; i < n-1; i++) {
		int local_pos = i;
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[local_pos]) {
				local_pos = j;
			}
		}
		swap(arr + local_pos, arr + i);
	}
}

void print(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	int arr[5] = { 30, 25, 20, 15, 10 };
	print(arr, 5);
	sort(arr, 5);
	print(arr, 5);


}