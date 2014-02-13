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
    int maxPathSum(TreeNode *root) {
        int max_val = findMaxVal(root);
        if (max_val <= 0)
            return max_val;
        int max_sum = 0;
        depthFirstSearch(root, max_sum);
        return max_sum;
    }

private:
    int depthFirstSearch(TreeNode *root, int &max_sum) {
        if (root == NULL)
            return 0;
        int left_max = depthFirstSearch(root->left, max_sum);
        int right_max = depthFirstSearch(root->right, max_sum);
        max_sum = std::max(left_max, max_sum);
        max_sum = std::max(right_max, max_sum);
        max_sum = std::max(left_max + right_max + root->val, max_sum);

        int result = std::max(left_max, right_max) + root->val;
        return std::max(result, 0);
    }

    bool isLeaf(TreeNode *root) {
        return root->left == NULL && root->right == NULL;
    }

    int findMaxVal(TreeNode *root) {
        if (isLeaf(root))
            return root->val;
        int val = root->val;
        if (root->left != NULL)
            val = std::max(val, findMaxVal(root->left));
        if (root->right != NULL)
            val = std::max(val, findMaxVal(root->right));
        return val;
    }
};