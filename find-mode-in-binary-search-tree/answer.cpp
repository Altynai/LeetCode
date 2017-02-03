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
    map<int, int> counter;

    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        counter[root->val] += 1;
        dfs(root->left);
        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        counter.clear();
        dfs(root);
        int max_count = 0;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            if (it->second > max_count)
                max_count = it->second;
        }
        vector<int> modes;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            if (it->second == max_count)
                modes.push_back(it->first);
        }
        return modes;
    }
};