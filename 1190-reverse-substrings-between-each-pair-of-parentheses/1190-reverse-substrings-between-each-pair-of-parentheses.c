char* reverseParentheses(char* s) {
    int n = strlen(s);

    char *stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for(int i = 0; i < n; i++) {

        if(s[i] != ')'){
            stack[++top] = s[i];
        }
        else{
            char temp[2000];
            int k = 0;

            while(top >= 0 && stack[top] != '('){
                temp[k++] = stack[top--];
            }

            top--;

            for(int j = 0; j < k; j++){
                stack[++top] = temp[j];
            }
        }
    }char *ans = (char*)malloc((top + 2) * sizeof(char));
    int idx = 0;

    for(int i = 0; i <= top; i++){
        if(stack[i] != '(')
            ans[idx++] = stack[i];
    }

    ans[idx] = '\0';

    free(stack);
    return ans;
}
