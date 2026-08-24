int reverse(int x) {
    long long res = 0;
    while (x != 0) {
        int m = x % 10;
        res = res * 10 + m;
        x = x / 10;
    }

    if (res > 2147483647 || res < -2147483648) {
        return 0;
    }

    return res;
}