int minSumOfLengths(int* arr, int arrSize, int target){

    int left = 0;
    int sum = 0;
    int ans = 1000000;
    int best = 1000000;

    int *dp = malloc(sizeof(int) * arrSize);

    for (int i = 0; i < arrSize; i++){
        dp[i] = 1000000;
    }

    for (int right = 0; right < arrSize; right++){
        sum = sum + arr[right];
        while (sum > target && left <= right){
            sum = sum - arr[left];
            left++;
        }

        if (sum == target){
            int len = right - left + 1;
            if (left > 0 && dp[left - 1] != 1000000){
                int total = len + dp[left - 1];
                if (total < ans){
                    ans = total;
                }
            }
            if (len < best){
                best = len;
            }
        }

        dp[right] = best;
    }

    free(dp);

    if (ans == 1000000) {
        return -1;
    }

    return ans;
}