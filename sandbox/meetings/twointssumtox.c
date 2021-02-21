#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e8

int binary_search(int a[], int v, int l, int r) {
	if (r >= l ){
		int mid = l + (r - l)/2; 
		if (a[mid] == v) return mid;
		else if (a[mid] < v) return binary_search(a, v, mid+1, r);
		else return binary_search(a, v, l, mid);
	}
	return -1;
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


int solve(int s[], int n, int x) {
	sort(s, 0, n-1);

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		printf("%d\n", s[i]);
		int other = x - s[i];
		printf("%d\n", other);
		int search = binary_search(s, other, i+1, n-1);
		printf("%d\n", search);
		if (search > 0) {
			ans = 1;
			break;
		}
	}
	return ans;
} 



int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);
	int s[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	int arr_size = sizeof(s) / sizeof(s[0]);
	int ans = solve(s, arr_size, x);
	if (ans)
		printf("Yes\n");
	else
		printf("No\n");

}



