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
    vector<TreeNode*> ppath, qpath;
    vector<TreeNode*> search;

    void findNode(TreeNode* root, TreeNode* p, TreeNode* q, int depth) {
        if (root == NULL)
            return;
        if (depth < search.size())
            search[depth] = root;
        else
            search.push_back(root);
        if (root == p)
            ppath = vector<TreeNode*>(search.begin(), search.begin() + depth + 1);
        if (root == q)
            qpath = vector<TreeNode*>(search.begin(), search.begin() + depth + 1);
        findNode(root->left, p, q, depth + 1);
        findNode(root->right, p, q, depth + 1);
    }

    void init() {
        ppath.clear();
        qpath.clear();
        search.clear();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        this->init();
        this->findNode(root, p, q, 0);
        int n = ppath.size(), m = qpath.size();
        for (int i = 1; i < std::min(n, m); ++i) {
            if (ppath[i] != qpath[i])
                return ppath[i - 1];
        }
        return n < m ? ppath[n - 1] : qpath[m - 1];
    }
};