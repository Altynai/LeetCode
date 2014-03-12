
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
    void dfs(vector<vector<int> > &result, TreeNode *root, int deep) {
        if (root == NULL)
            return;
        if (result.size() < deep + 1)
            result.push_back(vector<int>());
        result[deep].push_back(root->val);
        dfs(result, root->left, deep + 1);
        dfs(result, root->right, deep + 1);
    }

public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        dfs(result, root, 0);
        for (int i = 1; i < (int)result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
};