/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int sum = nums[0];
    for(int i = 1 ; i < numsSize ; i++){
        sum = sum + nums[i];
        nums[i] = sum;
    }
    *returnSize = numsSize;
    return nums;
}