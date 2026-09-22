/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int prod;
    int count[5];
} Node;

int k_global;

Node merge(Node left, Node right){
    Node result;

    result.prod = (left.prod * right.prod) % k_global;

    for (int i = 0; i < k_global; i++){
        result.count[i] = left.count[i];
    }

    for (int i = 0; i < k_global; i++){
        int r = (i * left.prod) % k_global;
        result.count[r] += right.count[i];
    }

    return result;
}

Node tree[400005];

void build(int index, int left, int right, int nums[]){
    if (left == right){
        int value = nums[left] % k_global;

        tree[index].prod = value;

        for (int i = 0; i < k_global; i++){
            tree[index].count[i] = 0;
        }

        tree[index].count[value] = 1;

        return;
    }

    int mid = (left + right) / 2;

    build(index * 2, left, mid, nums);
    build(index * 2 + 1, mid + 1, right, nums);

    tree[index] = merge(tree[index * 2],tree[index * 2 + 1]);
}

void update(int index, int left, int right,int position, int value){

    if (left == right){

        value = value % k_global;

        tree[index].prod = value;

        for (int i = 0; i < k_global; i++){
            tree[index].count[i] = 0;
        }

        tree[index].count[value] = 1;

        return;
    }

    int mid = (left + right) / 2;

    if(position <= mid){
        update(index * 2,left,mid,position,value);
    }else{
        update(index * 2 + 1,mid + 1,right,position,value);
    }

    tree[index] = merge(tree[index * 2],tree[index * 2 + 1]);
}

Node query(int index, int left, int right,int ql, int qr){

    if (ql <= left && right <= qr){
        return tree[index];
    }

    int mid = (left + right) / 2;

    if (qr <= mid){
        return query(index * 2,left,mid,ql,qr);
    }

    if (ql > mid) {
        return query(index * 2 + 1,mid + 1,right,ql,qr);
    }

    Node leftNode = query(index * 2,left,mid,ql,qr);

    Node rightNode = query(index * 2 + 1,mid + 1,right,ql,qr);

    return merge(leftNode, rightNode);
}

int* resultArray(int* nums, int numsSize, int k,int** queries, int queriesSize,int* queriesColSize, int* returnSize) {

    k_global = k;

    *returnSize = queriesSize;

    int* answer = malloc(sizeof(int) * queriesSize);

    build(1, 0, numsSize - 1, nums);

    for (int i = 0; i < queriesSize; i++){

        int index = queries[i][0];
        int value = queries[i][1];
        int start = queries[i][2];
        int x = queries[i][3];

        update(1, 0, numsSize - 1,index, value);

        Node result = query(1, 0, numsSize - 1,start, numsSize - 1);

        answer[i] = result.count[x];
    }

    return answer;
}