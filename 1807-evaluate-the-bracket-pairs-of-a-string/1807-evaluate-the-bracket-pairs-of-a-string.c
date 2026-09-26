int compare(const void *a, const void *b){
    char **x = *(char ***)a;
    char **y = *(char ***)b;

    return strcmp(x[0], y[0]);
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize){

    qsort(knowledge, knowledgeSize, sizeof(char **), compare);

    char *ans = malloc(strlen(s) * 21 + 1);
    int k = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            char key[25];
            int j = 0;

            i++;

            while(s[i] != ')'){
                key[j++] = s[i++];
            }

            key[j] = '\0';

            int left = 0;
            int right = knowledgeSize - 1;
            int found = 0;

            while(left <= right){
                int mid = (left + right) / 2;

                int cmp = strcmp(key, knowledge[mid][0]);

                if(cmp == 0){
                    strcpy(ans + k, knowledge[mid][1]);
                    k += strlen(knowledge[mid][1]);
                    found = 1;
                    break;
                }else if(cmp < 0){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

            if(found == 0){
                ans[k++] = '?';
            }
        }else{
            ans[k++] = s[i];
        }
    }

    ans[k] = '\0';

    return ans;
}