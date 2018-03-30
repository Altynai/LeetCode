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
    vector<double> sum;
    vector<int> count;

    void dfs(TreeNode* root, int depth) {
        if (root == NULL)
            return;
        if (depth >= sum.size())
            sum.push_back(root->val), count.push_back(1);
        else
            sum[depth] += root->val, count[depth] += 1;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        sum.clear(), count.clear();
        dfs(root, 0);
        for (int i = 0; i < sum.size(); i++)
            sum[i] /= count[i];
        return sum;
    }
};