int findNumbers(int* nums, int numsSize) {
    int even=0;
    for(int i=0;i<numsSize;i++){
        int temp = nums[i];
        int c = 0;
        while(temp > 0){
            temp = temp /10;
            c++;
        }
        if(c%2 == 0){
            even++;
        }
    }
    return even;
}