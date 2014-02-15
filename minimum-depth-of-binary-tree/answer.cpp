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
    void depthFirstSearch(TreeNode *root, int depth, int &min_depth) {
        if (isLeaf(root)) {
            min_depth = std::min(depth, min_depth);
            return;
        }
        if (root->left != NULL)
            depthFirstSearch(root->left, depth + 1, min_depth);
        if (root->right != NULL)
            depthFirstSearch(root->right, depth + 1, min_depth);
    }

    bool isLeaf(TreeNode *root) {
        return root->left == NULL && root->right == NULL;
    }

public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int result = 0x7fffffff;
        depthFirstSearch(root, 1, result);
        return result;
    }
};