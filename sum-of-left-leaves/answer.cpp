/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int sum;
    void dfs(TreeNode* root, bool is_left_leave) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL && is_left_leave) {
            sum += root->val;
            return;
        }
        dfs(root->left, true);
        dfs(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root, false);
        return sum;
    }
};