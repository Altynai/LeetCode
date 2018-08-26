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
    map<int, vector<TreeNode*>> dp;

public:
    vector<TreeNode*> dfs(int N) {
        if (N < 1)
            return {};
        auto it = dp.find(N);
        if (it != dp.end())
            return it->second;
        if (N == 1)
            return dp[1] = {new TreeNode(0)};
        vector<TreeNode*> ans;
        for (int i = 1; N - 1 - i >= 1; i += 2) {
            for (TreeNode* l : dfs(i)) {
                for (TreeNode* r : dfs(N - 1 - i)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return dp[N] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0)
            return {};
        dp.clear();
        return dfs(N);
    }
};
