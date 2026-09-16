long long power(long long a, long long b){
    long long result = 1;

    while(b > 0){
        if(b % 2 == 1){
            result = (result * a) % 1000000007;
        }

        a = (a * a) % 1000000007;
        b = b / 2;
    }

    return result;
}

long long combination(int n, int r){
    long long MOD = 1000000007;
    long long numerator = 1;
    long long denominator = 1;

    for(int i = 1; i <= r; i++){
        numerator = (numerator * (n - r + i)) % MOD;
        denominator = (denominator * i) % MOD;
    }

    long long inverse = power(denominator, MOD - 2);

    return (numerator * inverse) % MOD;
}

int numberOfSets(int n, int k){
    return combination(n + k - 1, 2 * k);
}