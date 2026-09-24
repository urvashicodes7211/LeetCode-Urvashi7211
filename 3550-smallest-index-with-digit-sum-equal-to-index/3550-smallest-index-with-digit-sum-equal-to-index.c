int smallestIndex(int* nums, int numsSize) {
    int res = -1;
    for(int i=0;i<numsSize;i++){
        int sum = 0;
        int n = nums[i];
        while(n > 0){
            int j = n % 10;
            n = n / 10;
            sum += j;
        }
        if(sum == i && res == -1){
            res = i;
        }
    }
    return res;
}