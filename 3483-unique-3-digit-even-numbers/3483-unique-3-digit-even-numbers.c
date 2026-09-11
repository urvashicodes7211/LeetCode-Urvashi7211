int totalNumbers(int* digits, int digitsSize) {
    int count = 0;
    int used[1000] = {0};

    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] == 0)
            continue;

        for (int j = 0; j < digitsSize; j++) {
            if (j == i)
                continue;

            for (int k = 0; k < digitsSize; k++) {
                if (k == i || k == j)
                    continue;

                if (digits[k] % 2 != 0)
                    continue;

                int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                if (used[num] == 0) {
                    used[num] = 1;
                    count++;
                }
            }
        }
    }

    return count;
}