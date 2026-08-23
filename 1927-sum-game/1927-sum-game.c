bool sumGame(char* num) {

    int n = strlen(num);
    int mid = n / 2;

    int leftSum = 0;
    int rightSum = 0;

    int leftQ = 0;
    int rightQ = 0;

    for(int i = 0; i < mid; i++) {
        if(num[i] == '?') {
            leftQ++;
        } 
        else {
            leftSum += num[i] - '0';
        }
    }

    for(int i = mid; i < n; i++) {
        if(num[i] == '?') {
            rightQ++;
        } 
        else {
            rightSum += num[i] - '0';
        }
    }

    int difference = (leftSum - rightSum) * 2;

    difference += (leftQ - rightQ) * 9;

    if(difference == 0) {
        return false;   
    }

    return true;      
}