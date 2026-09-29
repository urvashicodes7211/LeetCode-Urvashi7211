bool isValid(char* s) {
    char stack[10000];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if (top == -1)
        return '\0';
    return stack[top--];
}
    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            char temp = pop();

            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '[')){
                printf("0");
                return 0;
            }
        }
    }
   if(top == -1){
    return true;
   }else{
    return false;
   }
}
