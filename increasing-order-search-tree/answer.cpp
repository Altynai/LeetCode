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
    TreeNode* head, *cur;
    
    void add(int val) {
        TreeNode* node = new TreeNode(val);
        if (cur == NULL) {
            head = cur = node;
        } else {
            cur->right = node;
            cur = cur->right;
        }
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        add(root->val);
        dfs(root->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        head = cur = NULL;
        dfs(root);
        return head;
    }
};
