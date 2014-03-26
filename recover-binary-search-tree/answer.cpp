
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
    TreeNode *big_node, *small_node, *pre_node;

    void init() {
        big_node = small_node = pre_node = NULL;
    }

    void inOrderTraversal(TreeNode *root) {
        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        if (pre_node && (pre_node->val > root->val)) {
            if (big_node == NULL)
                big_node = pre_node;
            small_node = root;
        }
        pre_node = root;
        inOrderTraversal(root->right);
    }

    void recovery() {
        std::swap(big_node->val, small_node->val);
    }

public:
    void recoverTree(TreeNode *root) {
        init();
        inOrderTraversal(root);
        recovery();
    }
};
