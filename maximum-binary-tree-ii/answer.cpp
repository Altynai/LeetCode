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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        if (val > root->val) {
            TreeNode* nxt = new TreeNode(val);
            nxt->left = root;
            return nxt;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
