/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        if (!isSameNodeWithoutChildren(p, q))
            return false;
        else if (!isSameTree(p->left, q->left))
            return false;
        else
            return isSameTree(p->right, q->right);
    }

private:
    bool isSameNodeWithoutChildren(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        else if (p != NULL && q != NULL)
            return p->val == q->val;
        else
            return false;
    }
};