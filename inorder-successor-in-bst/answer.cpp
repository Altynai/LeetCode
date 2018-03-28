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
    TreeNode* previous, *ans;

    bool dfs(TreeNode* root, TreeNode* p) {
        if (root == NULL)
            return false;
        if (dfs(root->left, p))
            return true;
        if (previous == p) {
            ans = root;
            return true;
        }
        previous = root;
        return dfs(root->right, p);
    }

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        previous = ans = NULL;
        dfs(root, p);
        return ans;
    }
};