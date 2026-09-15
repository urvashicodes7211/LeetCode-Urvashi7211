#include <stdlib.h>
#include <string.h>

int maxPalindromes(char* s, int k){

    int n = strlen(s);

    char *dp = calloc(n * n, sizeof(char));

    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (s[i] == s[j] && (j - i <= 1 || dp[(i + 1) * n + (j - 1)])){
                dp[i * n + j] = 1;
            }
        }
    }

    int count = 0;
    int lastEnd = -1;

    for (int end = 0; end < n; end++){
        for (int start = lastEnd + 1; start <= end - k + 1; start++){
            if (dp[start * n + end] == 1){

                count++;
                lastEnd = end;

                break;
            }
        }
    }

    free(dp);

    return count;
}