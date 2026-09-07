int distinctSubseqII(char* s) {
    long long dp[26] = {0};
    long long total = 0;
    long long MOD = 1000000007;

    for (int i = 0; s[i] != '\0'; i++){
        int c = s[i] - 'a';

        long long newSub = (total + 1) % MOD;

        total = (total + newSub - dp[c] + MOD) % MOD;

        dp[c] = newSub;
    }

    return (int)total;
}