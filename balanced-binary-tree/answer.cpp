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
    int depthFirstSearch(TreeNode *root, bool &result) {
        // find the tree is not balanced, directly return;
        if (!result)
            return 0;
        if (root == NULL)
            return 0;
        int left_depth = depthFirstSearch(root->left, result);
        int right_depth = depthFirstSearch(root->right, result);
        if (std::abs(left_depth - right_depth) > 1)
            result = false;
        return std::max(left_depth, right_depth) + 1;
    }

public:
    bool isBalanced(TreeNode *root) {
        bool result = true;
        depthFirstSearch(root, result);
        return result;
    }
};