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
public:
    int dfs(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int longest = 0;
        int _left = dfs(root->left, ans);
        int _right = dfs(root->right, ans);
        if (root->left && root->val + 1 == root->left->val)
            longest = max(longest, _left);
        if (root->right && root->val + 1 == root->right->val)
            longest = max(longest, _right);
        ans = max(ans, longest + 1);
        return longest + 1;
    }

    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};