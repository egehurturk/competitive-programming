#include <stdio.h>

// #define DEBUG

#define SIZE 10000

int n_comp = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array(int arr[]) {
    for (int i = 0; i < 82; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int l, int r) {
    int p = arr[l];
    int i = l + 1;
    for (int j = l + 1; j <= r; j++) 
        if (arr[j] < p) 
            swap(&arr[i++], &arr[j]);
    swap(&arr[i-1], &arr[l]);
    return i-1;
}


void qsort_helper(int arr[], int l, int r) {
    if (r - l + 1 <= 1)
        return;
    n_comp += r - l + 1 - 1;
    int p_pos = partition(arr, l, r);
    qsort_helper(arr, l, p_pos - 1);
    qsort_helper(arr, p_pos + 1, r);
}

void qsort(int arr[]) {
    qsort_helper(arr, 0, SIZE - 1);
}

int check_if_sorted(int arr[]) {
    for (int i = 1; i < SIZE; i++)
        if (arr[i] < arr[i-1])
            return 1;
    return 0;
}


int main(void) {
    FILE *file;
    #ifdef DEBUG
        file = fopen("ints1.txt", "r");
    #else
        file = fopen("ints.txt", "r");
    #endif

    if (file == NULL) {
        fprintf(stderr, "Something bad happened with file");
        return 1;
    }

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        fscanf(file, "%d\n", &arr[i]);

    qsort(arr);
    printf("Is array sorted? %s\n", check_if_sorted(arr) ? "No" : "Yes");
    printf("Number of comparisons: %d\n", n_comp);
}

