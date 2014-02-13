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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        depthFirstSearch(root, 0, sum);
        return sum;
    }

private:
    void depthFirstSearch(TreeNode *root, int base, int &sum) {
        if (root == NULL)
            return;
        int new_base = base * 10 + root->val;
        if (isLeaf(root)) {
            sum += new_base;
            return;
        }
        depthFirstSearch(root->left, new_base, sum);
        depthFirstSearch(root->right, new_base, sum);
    }

    bool isLeaf(TreeNode *root) {
        return root->left == NULL && root->right == NULL;
    }
};