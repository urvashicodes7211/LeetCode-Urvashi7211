int divide(int dividend, int divisor) {

    long long a = dividend;
    long long b = divisor;

    int negative = 0;

    if (a < 0) {
        a = -a;
        negative = 1;
    }

    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    long long sum = 0;
    long long c = 0;

    while (a >= b) {
        long long temp = b;
        long long count = 1;

        while (a >= temp + temp) {
            temp += temp;
            count += count;
        }

        a -= temp;
        c += count;
    }

    if (negative)
        return -c;

    if (c > 2147483647)
        return 2147483647;

    return c;
}