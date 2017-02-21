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
    map<int, vector<int>> levels;

    void bfs(TreeNode* root, int level) {
        if (!root)
            return;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop();
            TreeNode* r = front.first;
            int l = front.second;
            levels[l].push_back(r->val);
            if (r->left)
                q.push(make_pair(r->left, l - 1));
            if (r->right)
                q.push(make_pair(r->right, l + 1));
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        levels.clear();
        bfs(root, 0);
        vector<vector<int>> ans;
        for (auto i = levels.begin(); i != levels.end(); ++i)
            ans.push_back(i->second);
        return ans;
    }
};