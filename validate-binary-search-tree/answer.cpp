
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
    static const int MAX_INT = 0x7fffffff;
    static const int MIN_INT = 0x80000000;

    bool isValidRoot(TreeNode *root, int &min_value, int &max_value) {
        if (root == NULL)
            return true;
        min_value = std::min(root->val, min_value);
        max_value = std::max(root->val, max_value);

        int _min_value = MAX_INT, _max_value = MIN_INT;
        // validate the left subtree
        if (!isValidRoot(root->left, _min_value, _max_value))
            return false;
        if (_max_value >= root->val)
            return false;
        min_value = std::min(_min_value, min_value);
        max_value = std::max(_max_value, max_value);

        // validate the right subtree
        _min_value = MAX_INT, _max_value = MIN_INT;
        if (!isValidRoot(root->right, _min_value, _max_value))
            return false;
        if (_min_value <= root->val)
            return false;
        min_value = std::min(_min_value, min_value);
        max_value = std::max(_max_value, max_value);
        return true;
    }

public:
    bool isValidBST(TreeNode *root) {
        int min_value = MAX_INT, max_value = MIN_INT;
        return isValidRoot(root, min_value, max_value);
    }
};