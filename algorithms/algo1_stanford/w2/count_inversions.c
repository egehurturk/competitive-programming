/*

Counting inversions: an algorithm to find similarity measure of two arrays, or, to find how close an array is to be sorted. 

The definition of an inversion in a 1D array is that:

    ∀ i, j such that 0 < i < j <= n:
        A[i] > A[j] defines a pair of integers, called an "inversion", (A[i], A[j]).

We can find the total number of inversions in a given array with brute force. However, this will result in O(n^2) running time:

for i = 1 to n:
    for j = i + 1 to n:
        if a[i] > a[j] counter++

The running time is (n - 1) + (n - 2) + (n - 3) + ... + (n - (n - 1)) + (n - n) 
                    = ∑(n - i) 
                    = n^2 - ∑i 
                    = n^2 - (n * (n+1) / 2) = n^2 - ((n^2 + n) / 2) = (2n^2 - n) / 2 = O(n^2)

To improve the running time, we will use Divide and conquer to calculate the inversions. 
To simplify things, we will call an inversion (i, j):
    * left inversion <=> i < j <= n/2
    * right inversion <=> n/2 < i < j
    * split inversion <=> i <= n/2 < j

We will use the merge sort idea to calculate left and right inversions, and another method to calculate the split inversions. The pseudocode will look like:

```
procedure count_inv(array a, length n) 
    if n = 1
        return 0
    
    X = count_inv(1st half of a, n/2)
    Y = count_inv(2nd half of a, n / 2)
    Z = count_split_inv(a, n)
    return X + Y + Z
```

Since we are dividing the array into 2 at each recursive step, and if we find out an algorithm to compute the number of split inversions in O(n) time, the
running time of this procedure will be O(n log n). 

The question is, how to find an algorithm that will find split inversions in O(n) time?

We will use the merge-sort idea. 

To give intuition, think about an array that has no split-inversions. What is the relation between the first sorted subarray and the second sorted subarray of the array?
If we call B := 1st subarray, C := 2nd subarray, then all elements of B has to be less than C. This is because if we think the opposite, then there is at least 1 split inversions. 

What about the merge procedure?

If we merge B and C (in the previous question), then it could be seen that the algorithm will first copy all the elements of B to the target array, then concatenate C. This is because
every element of B is less than C, which is the case of not having any split inversions.

If we have any split inversions, which means that there is at least 1 element in B that is greater than any element of C, the algorithm will bounce back and forth between B, C.

To illustrate, if we have 1 split inversion, then the merge procedure will copy B to the target array until there is an element of B that is greater than an element in C. We can
calculate the number of inversions by adding the left elements in B. We will do this step whenever an element in B is greater than an element in C.

Thus, this will give the number of split inversions in O(n) time, and we will have a total of O(n log n) running time to calculate the number of inversions in an array.
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 100000


uint64_t count_inversions(uint64_t arr[], uint64_t n);
uint64_t merge_sort(uint64_t arr[], uint64_t temp[], uint64_t l, uint64_t r);
uint64_t merge(uint64_t a[], uint64_t temp[], uint64_t l, uint64_t m, uint64_t r);

uint64_t count_inversions(uint64_t arr[], uint64_t n) {
    uint64_t temp[n];
    return merge_sort(arr, temp, 0, n - 1);
}

uint64_t merge_sort(uint64_t arr[], uint64_t temp[], uint64_t l, uint64_t r) {
    if (l < r) {    
        uint64_t middle = (r + l ) / 2;
        uint64_t x =  merge_sort(arr, temp, l, middle);
        uint64_t y =  merge_sort(arr, temp, middle + 1, r);
        uint64_t z =  merge(arr, temp, l, middle + 1, r);
        return x + y + z;
    }

    return 0;
}

uint64_t merge(uint64_t a[], uint64_t temp[], uint64_t l, uint64_t m, uint64_t r) {

    int i, j, k;
    int n_inv = 0;
    i = l; 
    j = m; 
    k = l; 

    // count inversions
    while ((i <= m - 1) && (j <= r)) {
      if (a[i] <= a[j]){ 
      temp[k++] = a[i++];
      } else {
         temp[k++] = a[j++];
         n_inv += m - i; 
      }
    }
    while (i <= m - 1) 
      temp[k++] = a[i++];
    while (j <= r) 
      temp[k++] = a[j++];
    for (i=l; i <= r; i++)
      a[i] = temp[i]; 
    return n_inv;
}

uint64_t brute_force(uint64_t arr[], int n) {
    uint64_t counter = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                counter++;
    return counter;
}

int main(void) {

    

    // Read "\n" seperated values uint64_to array
    FILE *file = fopen("ints.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Something bad happened with file");
        return 1;
    }

    uint64_t A[SIZE];
    uint64_t i;

    for (i = 0; i < SIZE; i++) 
        fscanf(file, "%lldd\n", &A[i]);
    

    // Count inversions
    uint64_t n = sizeof(A) / sizeof(A[0]);
    uint64_t inversions = count_inversions(A, n);
    printf("No. of inversions: %lld \n", inversions);
    // Resource clean-up
    fclose(file);

    return 0;

}   







