#include <stdio.h>

// Function to return the only odd occuring element
int findOdd(int arr[], int n) 
{
    int res = 0, i;
    for (i=0; i<n; i++) {
        res ^= arr[i]; // XOR
    }
    return res;
}

int main(void) 
{
    int arr[] = { 12, 12, 14, 90 ,14, 14, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Odd reccuring no is %d\n", findOdd(arr, n));
    return 0;

}

// CONCLUSION 1: A ^ 0 = A
// CONCLUSION 2: A ^ A = 0
// CONCLUSION 3: A ^ B ^ A ^ A = B
// CONCLUSION 4: assume A1 ^ A2 ^ A3 ^ ... ^ AN = a, assume A1 ^ A2 ^ A3 ^ ... ^ AN - 1 = b, then a ^ b = AN
// CONCLUSION 5: A ^ B = B ^ A
// CONCLUSION 6: (A ^ B) ^ C = A ^ (B ^ C)
