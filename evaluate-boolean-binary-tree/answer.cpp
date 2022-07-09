/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    if (root->left == nullptr and root->right == nullptr) {
      return root->val;
    }

    bool x = root->left ? evaluateTree(root->left) : 0;
    bool y = root->right ? evaluateTree(root->right) : 0;
    return root->val == 2 ? (x | y) : (x & y);
  }
};
