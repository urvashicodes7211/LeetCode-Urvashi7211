int firstStableIndex(int* nums, int numsSize, int k) {
    int suffixMin[numsSize];

    suffixMin[numsSize - 1] = nums[numsSize - 1];

    for (int i = numsSize - 2; i >= 0; i--){
        if (nums[i] < suffixMin[i + 1])
            suffixMin[i] = nums[i];
        else
            suffixMin[i] = suffixMin[i + 1];
    }

    int prefixMax = nums[0];

    for (int i = 0; i < numsSize; i++){

        if (nums[i] > prefixMax)
            prefixMax = nums[i];

        int instability = prefixMax - suffixMin[i];

        if (instability <= k)
            return i;
    }

    return -1;
}