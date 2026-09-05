int firstStableIndex(int* nums, int numsSize, int k) {
    int right[numsSize];

    right[numsSize - 1] = nums[numsSize - 1];

    for (int i = numsSize - 2; i >= 0; i--){
        if (nums[i] < right[i + 1])
            right[i] = nums[i];
        else
            right[i] = right[i + 1];
    }

    int left = 0;

    for (int i = 0; i < numsSize; i++){

        if (nums[i] > left)
            left = nums[i];

        if (left - right[i] <= k)
            return i;
    }

    return -1;
}