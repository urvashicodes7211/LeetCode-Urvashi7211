int search(int* nums, int numsSize, int target) {
    int res;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == target){
            res = i;
            break;
        }else{
            res = -1;
        }
    }
    return res;
}