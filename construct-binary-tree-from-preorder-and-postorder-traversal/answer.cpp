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
    vector<int> pre;
    vector<int> post;
    map<int, int> idx;

    TreeNode* dfs(int i, int j) {
        if (i > j)
            return NULL;
        TreeNode* root = new TreeNode(post[j]);
        if (i == j)
            return root;
        int p = idx[post[j]];
        for (int k = i; k <= j; k++) {
            if (post[k] == pre[p + 1]) {
                root->left = dfs(i, k);
                root->right = dfs(k + 1, j - 1);
                break;
            }
        }
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre = pre;
        this->post = post;
        idx.clear();
        for (int i = 0; i < pre.size(); i++)
            idx[pre[i]] = i;
        return dfs(0, pre.size() - 1);
    }
};
