int reverseDegree(char* s) {
    int sum = 0;
    int i = 0;

    while (s[i] != '\0'){
        int value = 'z' - s[i] + 1;
        int position = i + 1;
        sum = sum + value * position;
        i++;
    }

    return sum;
}