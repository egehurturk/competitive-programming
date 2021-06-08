#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int n, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[i] = arr[m + 1 + j];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void __merge_sort(int arr[], int n, int l, int r) {
    if (l < r) {
        int middle = l + (r - l) / 2;
        
        __merge_sort(arr, n, l, middle);
        __merge_sort(arr, n, middle + 1, r);

        merge(arr, n, l, middle, r);
    }
}

void merge_sort(int arr[], int n) {
    __merge_sort(arr, n, 0, n - 1);
}



void p_a(int a[], int n) {
    for (int i = 0; i < n; ++i) 
        printf("%d ", a[i]);
    printf("\n");
}


int main(void) {
    int arr[] = {9,8,7,6,5,4,3,2,1};

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("original: "), p_a(arr, n);
    merge_sort(arr, n);
    printf("sorted: "), p_a(arr, n);
}
