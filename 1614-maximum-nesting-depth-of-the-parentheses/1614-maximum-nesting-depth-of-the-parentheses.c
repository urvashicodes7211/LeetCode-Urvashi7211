int maxDepth(char* s) {
    int count = 0;
    int max = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            count++;
            if(count > max)
                max = count;
        }
        else if(s[i] == ')'){
            count--;
        }
    }

    return max;
}