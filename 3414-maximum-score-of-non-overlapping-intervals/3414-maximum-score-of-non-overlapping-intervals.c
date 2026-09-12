/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */

#include <stdlib.h>

struct Interval{
    int l;
    int r;
    long long w;
    int index;
};

struct State{
    long long score;
    int size;
    int index[4];
};

int compareIntervals(const void *a, const void *b){

    struct Interval *x = (struct Interval *)a;
    struct Interval *y = (struct Interval *)b;

    if (x->l < y->l)
        return -1;

    if (x->l > y->l)
        return 1;

    if (x->r < y->r)
        return -1;

    if (x->r > y->r)
        return 1;

    if (x->index < y->index)
        return -1;

    if (x->index > y->index)
        return 1;

    return 0;
}

int isSmaller(struct State *a, struct State *b){

    int i;

    for (i = 0; i < a->size && i < b->size; i++){

        if (a->index[i] < b->index[i])
            return 1;

        if (a->index[i] > b->index[i])
            return 0;
    }

    return a->size < b->size;
}

void addIndex(struct State *result, int value){

    int i;

    i = result->size;

    while (i > 0 && result->index[i - 1] > value){

        result->index[i] = result->index[i - 1];

        i--;
    }

    result->index[i] = value;

    result->size++;
}

int findNext(struct Interval *arr, int n, int i){

    int left = i + 1;
    int right = n;

    while (left < right){

        int mid = left + (right - left) / 2;

        if (arr[mid].l > arr[i].r)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int* maximumWeight(int** intervals,
                   int intervalsSize,
                   int* intervalsColSize,
                   int* returnSize){

    int n = intervalsSize;

    struct Interval *arr;

    arr = malloc(sizeof(struct Interval) * n);

    int i;
    int k;

    for (i = 0; i < n; i++){

        arr[i].l = intervals[i][0];
        arr[i].r = intervals[i][1];
        arr[i].w = intervals[i][2];
        arr[i].index = i;
    }

    qsort(arr, n, sizeof(struct Interval), compareIntervals);

    int *next;

    next = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++){

        next[i] = findNext(arr, n, i);
    }

    struct State *dp;

    dp = malloc(sizeof(struct State) * (n + 1) * 5);

    #define DP(i,k) dp[(i) * 5 + (k)]

    /*
       IMPORTANT:
       Initialize ALL DP states.
    */

    for (i = 0; i <= n; i++){
        for (k = 0; k <= 4; k++){
            DP(i,k).score = 0;
            DP(i,k).size = 0;
        }
    }

    for (i = n - 1; i >= 0; i--){
        for (k = 1; k <= 4; k++){

            struct State skip;

            skip = DP(i + 1, k);

            struct State take;

            take.score = arr[i].w +
                         DP(next[i], k - 1).score;

            take.size = 0;

            addIndex(&take, arr[i].index);

            int j;

            for(j = 0; j < DP(next[i], k - 1).size; j++){
                addIndex(&take,DP(next[i], k - 1).index[j]);
            }

            if(take.score > skip.score){
                DP(i,k) = take;
            }else if(take.score < skip.score){
                DP(i,k) = skip;
            }else{
                if(isSmaller(&take, &skip))
                    DP(i,k) = take;
                else
                    DP(i,k) = skip;
            }
        }
    }

    *returnSize = DP(0,4).size;

    int *answer;

    answer = malloc(sizeof(int) * (*returnSize));

    for (i = 0; i < *returnSize; i++){
        answer[i] = DP(0,4).index[i];
    }

    free(arr);
    free(next);
    free(dp);

    return answer;
}