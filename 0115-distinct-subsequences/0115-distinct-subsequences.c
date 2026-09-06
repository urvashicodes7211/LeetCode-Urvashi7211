#include <string.h>
#include <limits.h>

int numDistinct(char* s, char* t){
    int m = strlen(s);
    int n = strlen(t);

    __int128 dp[n + 1];

    for (int j = 0; j <= n; j++){
        dp[j] = 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= m; i++){
        for (int j = n; j >= 1; j--){

            if (s[i - 1] == t[j - 1]){
                dp[j] = dp[j] + dp[j - 1];

                if (dp[j] > INT_MAX){
                    dp[j] = INT_MAX;
                }
            }
        }
    }

    return (int)dp[n];
}