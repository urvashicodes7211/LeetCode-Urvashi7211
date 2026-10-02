/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char **ans, int *returnSize, char *str,int n, int open, int close, int pos){
    if (open == n && close == n){
        str[pos] = '\0';

        ans[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(ans[*returnSize], str);

        (*returnSize)++;
        return;
    }

    if (open < n){
        str[pos] = '(';

        backtrack(ans, returnSize, str,n, open + 1, close, pos + 1);
    }

    if (close < open){
        str[pos] = ')';

        backtrack(ans, returnSize, str,n, open, close + 1, pos + 1);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    int max = 5000;

    char **ans = malloc(max * sizeof(char*));
    char *str = malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    backtrack(ans, returnSize, str,n, 0, 0, 0);

    free(str);

    return ans;
}