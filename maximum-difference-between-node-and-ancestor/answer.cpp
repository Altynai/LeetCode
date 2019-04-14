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
    multiset<int> seen;
    int ans;

    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        if (!seen.empty()) {
            int mn = *seen.begin(), mx = *seen.rbegin();
            ans = max(ans, abs(root->val - mn));
            ans = max(ans, abs(root->val - mx));
        }
        seen.insert(root->val);
        dfs(root->left);
        dfs(root->right);
        seen.erase(root->val);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        seen.clear();
        ans = -1;
        dfs(root);
        return ans;
    }
};
