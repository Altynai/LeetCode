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
    TreeNode* dfs(vector<int>& p, int i, int j) {
        if (i > j)
            return nullptr;
        if (i == j)
            return new TreeNode(p[i]);

        TreeNode* ans = new TreeNode(p[i]);
        int k = i + 1;
        while (k <= j && p[k] < p[i])
            k++;
        ans->left = dfs(p, i + 1, k - 1);
        ans->right = dfs(p, k, j);
        return ans;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
};
