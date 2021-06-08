#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint64_t find_max_helper(uint64_t unimodal_arr[], uint64_t l, uint64_t r) {

        if (l >= r) 
            return 0;
        
        uint64_t m = l + (r - l) / 2;
        if (unimodal_arr[m] > unimodal_arr[m-1] && unimodal_arr[m] > unimodal_arr[m+1]) 
            return unimodal_arr[m];
        if (unimodal_arr[m] > unimodal_arr[m-1])   
            return find_max_helper(unimodal_arr, m + 1, r);
        else                                       
            return find_max_helper(unimodal_arr, l, m - 1);
    
}

uint64_t find_max(uint64_t unimodal_arr[], uint64_t n) {
    return find_max_helper(unimodal_arr, 0, n - 1);
}


int main(void) {
    uint64_t arr[] = { 1,2,3,4,5, 33, 2};
    uint64_t n = sizeof(arr) / sizeof(arr[0]);
    uint64_t max = find_max(arr, n);
    printf("max: %llu\n", max);
}

