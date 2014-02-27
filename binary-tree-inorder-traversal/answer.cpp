
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
    void dfs(vector<int> &result, TreeNode *root) {
        if (!root)
            return;
        dfs(result, root->left);
        result.push_back(root->val);
        dfs(result, root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        dfs(result, root);
        return result;
    }
};