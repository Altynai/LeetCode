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
    bool findOther(TreeNode* root, int value, TreeNode* self) {
        if (root == NULL)
            return false;
        if (root->val == value && root != self)
            return true;
        else if (root->val > value && root->left != NULL)
            return findOther(root->left, value, self);
        else if (root->val < value && root->right != NULL)
            return findOther(root->right, value, self);
        return false;
    }
    
    bool dfs(TreeNode* root, TreeNode* current, int k) {
        if (current == NULL)
            return false;
        if (findOther(root, k - current->val, current))
            return true;
        if (current->left && dfs(root, current->left, k))
            return true;
        if (current->right && dfs(root, current->right, k))
            return true;
        return false;
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);    
    }
};