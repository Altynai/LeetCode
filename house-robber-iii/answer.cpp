/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

class Solution {
private:
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL)
            return make_pair(0, 0);
        if (root->left == NULL && root->right == NULL)
            return make_pair(root->val, 0);
        int rob = root->val, norob = 0;
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        rob += left.second + right.second;
        norob = std::max(left.first, left.second) + std::max(right.first, right.second);
        return make_pair(rob, norob);
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ret = this->dfs(root);
        return std::max(ret.first, ret.second);
    }
};