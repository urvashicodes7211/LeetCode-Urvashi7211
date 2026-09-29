bool hasValidPath(char** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int len = m + n - 1;

    if (len % 2 != 0)
        return false;

    if (grid[0][0] != '(')
        return false;

    if (grid[m - 1][n - 1] != ')')
        return false;

    bool dp[m][n][len + 1];

    memset(dp, false, sizeof(dp));

    dp[0][0][1] = true;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            if (i == 0 && j == 0)
                continue;

            for (int bal = 0; bal <= len; bal++){

                if (grid[i][j] == '('){

                    if (bal > 0){
                        if (i > 0 && dp[i - 1][j][bal - 1])
                            dp[i][j][bal] = true;

                        if (j > 0 && dp[i][j - 1][bal - 1])
                            dp[i][j][bal] = true;
                    }
                }else{
                    if (bal + 1 <= len){

                        if (i > 0 && dp[i - 1][j][bal + 1])
                            dp[i][j][bal] = true;

                        if (j > 0 && dp[i][j - 1][bal + 1])
                            dp[i][j][bal] = true;
                    }
                }
            }
        }
    }
    return dp[m - 1][n - 1][0];
}