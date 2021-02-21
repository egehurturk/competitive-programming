#include <stdio.h>

int binary_search(int a[], int v, int l, int r) {
	if (r >= l ){
		int mid = l + (r - l)/2; 
		if (a[mid] == v) return mid;
		else if (a[mid] < v) return binary_search(a, v, mid+1, r);
		else return binary_search(a, v, l, mid);
	}
	return -1;
}

int main(void) {
	int a[] = {1,2,3,4,5,6,7};
	printf("%d\n", binary_search(a, 7, 0, 6));

}