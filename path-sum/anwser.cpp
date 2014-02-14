/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool depthFirstSearch(TreeNode *root, int current, int sum) {
        if (root == NULL)
            return false;
        current += root->val;
        if (isLeaf(root))
            return current == sum;
        return depthFirstSearch(root->left, current, sum) || depthFirstSearch(root->right, current, sum);
    }

    bool isLeaf(TreeNode *root) {
        return root->left == NULL && root->right == NULL;
    }

public:
    bool hasPathSum(TreeNode *root, int sum) {
        return depthFirstSearch(root, 0, sum);
    }
};