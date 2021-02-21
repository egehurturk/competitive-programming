#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

int dup[7] = {0};
int dp[7][7] = {0};


int duplicate(int arr[], int n) {
   // sort O(n log n) scan O(n)
   std::sort(arr, arr+n);
   for (int i = 1; i < n; i++) {
       if (arr[i] == arr[i-1]) {
           return 1;
       }
       else {
           continue;
       }
   }
   return -1;
}

int findSum(int arr[], int v, int n) {
    // O(n log n) merge sort, O(n log n) search
    // If array already sorted, O(n log n) whole algorithm

    std::sort(arr, arr+n); // O(n log n)
    
    // O(n log n)
    for (int i = 0; i < n; i++) {
        if (std::binary_search(arr, arr+n, v - arr[i])) 
            return 1;
        else 
            continue;
    }
    return -1;

}

void printInt(int arr[], int a, int b, int n) {
    // O(n log n) merge sort, 
    std::sort(arr, arr+n); // O(n log n)
    
    // if there exists a value x in arr s.t. x is the closest value greater than a, get the index of x
    // if there exists a value y in arr s.t. y is the closest value lesser than b, get the index of y
    

}

int median(int arr[], int n) {
    return arr[(n / 2) + 1];
}

int main(void) {
    int arr[7] = {1, 5, 6, 9, 3, 4, 8}; // 1 3 4 5 6 8 9
    printf("%d\n", duplicate(arr, 7));
    printf("%d\n", median(arr, 7)); 
    printf("%d\n", findSum(arr, 89, 7));
}   
