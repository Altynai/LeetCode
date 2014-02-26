
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeLinkNode *father, TreeLinkNode *son) {
        if (!father->left)
            return;
        // is left son
        if (father->left == son)
            son->next = father->right;
        // is right son
        else {
            if (father->next)
                son->next = father->next->left;
        }
        dfs(son, son->left);
        dfs(son, son->right);
    }

public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        dfs(root, root->left);
        dfs(root, root->right);
    }
};