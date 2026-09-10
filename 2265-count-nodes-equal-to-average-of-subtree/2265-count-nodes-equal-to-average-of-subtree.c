/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;

int dfs(struct TreeNode* root, int* sum, int* nodes){
    if (root == NULL){
        *sum = 0;
        *nodes = 0;
        return 0;
    }

    int leftSum, leftNodes;
    int rightSum, rightNodes;

    dfs(root->left, &leftSum, &leftNodes);
    dfs(root->right, &rightSum, &rightNodes);

    *sum = leftSum + rightSum + root->val;
    *nodes = leftNodes + rightNodes + 1;

    if (root->val == (*sum / *nodes)){
        count++;
    }

    return 0;
}

int averageOfSubtree(struct TreeNode* root){
    count = 0;

    int sum, nodes;
    dfs(root, &sum, &nodes);

    return count;
}