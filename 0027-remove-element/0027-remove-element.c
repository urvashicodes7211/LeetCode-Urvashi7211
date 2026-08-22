int removeElement(int* nums, int numsSize, int val) {
    for(int i=0;i<numsSize;i++){
        if(nums[i] == val){
            for(int j=i;j<numsSize-1;j++){
                nums[j] = nums[j+1];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}