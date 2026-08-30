int minimumDeletions(int* nums, int numsSize) {
    
    int min = nums[0];
    int max = nums[0];

    int minIndex = 0;
    int maxIndex = 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] < min) {
            min = nums[i];
            minIndex = i;
        }
        if(nums[i] > max) {
            max = nums[i];
            maxIndex = i;
        }
    }

    int left = minIndex < maxIndex ? minIndex : maxIndex;
    int right = minIndex > maxIndex ? minIndex : maxIndex;

    int option1 = right + 1;

    int option2 = numsSize - left;

    int option3 = (left + 1) + (numsSize - right);

    int answer = option1;

    if(option2 < answer)
        answer = option2;

    if(option3 < answer)
        answer = option3;

    return answer;
}