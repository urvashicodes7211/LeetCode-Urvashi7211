/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

long long* resultArray(int* nums, int numsSize, int k, int* returnSize){

    long long *result = (long long*)calloc(k, sizeof(long long));
    long long *prev = (long long*)calloc(k, sizeof(long long));
    long long *curr = (long long*)calloc(k, sizeof(long long));

    for (int i = 0; i < numsSize; i++){
        for (int j = 0; j < k; j++){
            curr[j] = 0;
        }

        int rem = nums[i] % k;

        curr[rem]++;

        for (int j = 0; j < k; j++){
            if (prev[j] > 0){

                int newRem = (j * rem) % k;

                curr[newRem] += prev[j];
            }
        }

        for (int j = 0; j < k; j++){
            result[j] += curr[j];
            prev[j] = curr[j];
        }
    }

    free(prev);
    free(curr);

    *returnSize = k;

    return result;
}