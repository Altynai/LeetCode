
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
    TreeNode *dfs(TreeNode *root) {
        if (!root)
            return NULL;
        TreeNode *left_tail = dfs(root->left);
        TreeNode *right_tail = dfs(root->right);
        if (!left_tail)
            return right_tail ? right_tail : root;
        else {
            left_tail->right = root->right;
            root->right = root->left;
        	root->left = NULL; // where the trick is
            return right_tail ? right_tail : left_tail;
        }
    }

public:
    void flatten(TreeNode *root) {
        dfs(root);
    }
};
