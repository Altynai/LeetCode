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
    void dfs(TreeNode* root, TreeNode* p, TreeNode* gp, int& ans) {
        if (root == nullptr)
            return;
        if (gp != nullptr && gp->val % 2 == 0)
            ans += root->val;
        dfs(root->left, root, p, ans);
        dfs(root->right, root, p, ans);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root, nullptr, nullptr, ans);
        return ans;
    }
};
