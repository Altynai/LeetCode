
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
private:
    bool recursive(TreeNode *lh, TreeNode *rh) {
        if (!lh && !rh)
            return true;
        else if (!lh && rh)
            return false;
        else if (lh && !rh)
            return false;
        else if (lh->val != rh->val)
            return false;
        else if (!recursive(lh->left, rh->right))
            return false;
        else if (!recursive(lh->right, rh->left))
            return false;
        else
            return true;
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        else
            return recursive(root->left, root->right);
    }
};