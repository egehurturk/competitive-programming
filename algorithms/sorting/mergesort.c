#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e8

void merge(int[], int, int, int);
void sort(int[], int, int);
void printArray(int[], int);

int main(void) {
	int arr[] = { 3,41,52,26,38,57,9,48};
	int arr_size = sizeof(arr) / sizeof(arr[0]); 
	printArray(arr, arr_size);

	sort(arr, 0, arr_size - 1);
	printArray(arr, arr_size);
	return 0;
}

void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1], R[n2 + 1];

	for (int i = 1; i <= n1; i++) 
		L[i] = A[p+i-1];
	for (int j = 1; j <= n2; j++)
		R[j] = A[q+j];
	L[n1 + 1] = INF;
	R[n2 + 1] = INF;

	int i = 1;
	int j = 1;

	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}

}

void sort(int A[], int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;
		sort(A, p, q);
		sort(A, q+1, r);
		merge(A, p, q, r);
	}
}


void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

