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
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL)
            return true;
        else if (s != NULL && t == NULL)
            return false;
        else if (s == NULL && t != NULL)
            return false;
        else if (s->val != t->val)
            return false;
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL)
            return t == NULL;
        if (t == NULL)
            return false;
        if (s->val == t->val && sameTree(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};