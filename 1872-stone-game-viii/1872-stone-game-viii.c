int stoneGameVIII(int* stones, int stonesSize) {
    long long prefix[stonesSize];

    prefix[0] = stones[0];

    for (int i = 1; i < stonesSize; i++) {
        prefix[i] = prefix[i - 1] + stones[i];
    }

    long long dp = prefix[stonesSize - 1];

    for (int i = stonesSize - 2; i >= 1; i--) {
        long long take = prefix[i] - dp;

        if (take > dp) {
            dp = take;
        }
    }

    return dp;
}