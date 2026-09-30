/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = strlen(seq);
    int* ans = malloc(n * sizeof(int));

    int depth = 0;

    *returnSize = n;

    for(int i = 0; i < n; i++){
        if(seq[i] == '('){
            depth++;
            ans[i] = depth % 2;
        }else{
            ans[i] = depth % 2;
            depth--;
        }
    }
    return ans;
}