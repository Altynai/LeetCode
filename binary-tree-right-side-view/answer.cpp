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
    void dfs(TreeNode* root, int depth, vector<int>& answer) {
        if (root == NULL)
            return;
        if (depth >= (int)answer.size())
            answer.push_back(root->val);
        else
            answer[depth] = root->val;
        dfs(root->left, depth + 1, answer);
        dfs(root->right, depth + 1, answer);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        dfs(root, 0, answer);
        return answer;
    }
};