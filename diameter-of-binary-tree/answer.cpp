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
    int ans;

    // returns longest path starts with node root
    int dfs(TreeNode* root, int depth) {
        // leaf node
        if (root == NULL) {
            return 0;
        }
        int left = root->left ? dfs(root->left, depth + 1) + 1: 0;
        int right = root->right ? dfs(root->right, depth + 1) + 1 : 0;
        ans = max(left + right, ans);
        ans = max(max(left, right) + depth, ans);
        return max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};