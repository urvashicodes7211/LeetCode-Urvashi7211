/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

char** maxNumOfSubstrings(char* s, int* returnSize){
    int first[26];
    int last[26];
    int n = strlen(s);

    for (int i = 0; i < 26; i++){
        first[i] = -1;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';

        if (first[c] == -1){
            first[c] = i;
        }

        last[c] = i;
    }

    int start[26];
    int end[26];
    int count = 0;

    for (int i = 0; i < n; i++){

        int c = s[i] - 'a';

        if (first[c] != i){
            continue;
        }

        int l = i;
        int r = last[c];
        int valid = 1;

        for (int j = l; j <= r; j++){

            int x = s[j] - 'a';

            if (first[x] < l){
                valid = 0;
                break;
            }

            if (last[x] > r){
                r = last[x];
            }
        }

        if (valid){
            start[count] = l;
            end[count] = r;
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++){
        for (int j = i + 1; j < count; j++){

            if (end[i] > end[j]){
                int temp = end[i];
                end[i] = end[j];
                end[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    char** ans = (char**)malloc(count * sizeof(char*));

    int lastEnd = -1;
    *returnSize = 0;

    for (int i = 0; i < count; i++){

        if (start[i] > lastEnd){

            int len = end[i] - start[i] + 1;

            ans[*returnSize] = (char*)malloc((len + 1) * sizeof(char));

            strncpy(ans[*returnSize], s + start[i], len);
            ans[*returnSize][len] = '\0';

            (*returnSize)++;

            lastEnd = end[i];
        }
    }

    return ans;
}