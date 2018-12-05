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
    bool same(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        return r1 && r2 && r1->val == r2->val;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!same(root1, root2))
            return false;

        if (root1 == nullptr)
            return true;

        if (same(root1->left, root2->left) &&
                same(root1->right, root2->right) &&
                flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right))
            return true;

        if (same(root1->left, root2->right) &&
                same(root1->right, root2->left) &&
                flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left))
            return true;

        return false;
    }
};
