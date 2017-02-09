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
    TreeNode* findLe(TreeNode* root, double target) {
        if (root == NULL)
            return NULL;
        if (root->val > target)
            return findLe(root->left, target);
        // root->val <= target
        TreeNode* nearest = findLe(root->right, target);
        if (nearest == NULL)
            return root;
        return root->val >= nearest->val ? root : nearest;
    }

    TreeNode* findGe(TreeNode* root, double target) {
        if (root == NULL)
            return NULL;
        if (root->val < target)
            return findGe(root->right, target);
        // root->val >= target
        TreeNode* nearest = findGe(root->left, target);
        if (nearest == NULL)
            return root;
        return root->val < nearest->val ? root : nearest;
    }

    int closestValue(TreeNode* root, double target) {
        TreeNode* le = findLe(root, target);
        TreeNode* ge = findGe(root, target);
        if (le == NULL)
            return ge->val;
        else if (ge == NULL)
            return le->val;
        else {
            double dl = fabs(target - le->val);
            double dg = fabs(target - ge->val);
            return dl <= dg ? le->val : ge->val;
        }
    }
};