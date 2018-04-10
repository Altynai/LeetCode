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
    bool dfs(TreeNode* root) {
        if (root == NULL)
            return true;
        bool fl = dfs(root->left);
        bool fr = dfs(root->right);
        if (fl)
            root->left = NULL;
        if (fr)
            root->right = NULL;
        if (root->val == 1)
            return false;
        else
            return (!fl || !fr) ? false : true;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        if (dfs(root))
            return NULL;
        return root;
    }
};