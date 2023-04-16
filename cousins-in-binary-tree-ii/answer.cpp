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
  TreeNode *replaceValueInTree(TreeNode *root) {
    map<TreeNode *, int> childrenSum;
    map<int, int> levelSum;

    function<void(TreeNode *, int d)> dfs = [&](TreeNode *cur, int d) {
      levelSum[d] += cur->val;
      if (cur->left) {
        childrenSum[cur] += cur->left->val;
        dfs(cur->left, d + 1);
      }
      if (cur->right) {
        childrenSum[cur] += cur->right->val;
        dfs(cur->right, d + 1);
      }
    };
    dfs(root, 0);

    function<void(TreeNode *, TreeNode *, int d)> dfs2 =
        [&](TreeNode *cur, TreeNode *fa, int d) {
          cur->val = (d == 0 ? 0 : levelSum[d] - childrenSum[fa]);
          if (cur->left)
            dfs2(cur->left, cur, d + 1);
          if (cur->right)
            dfs2(cur->right, cur, d + 1);
        };

    dfs2(root, nullptr, 0);
    return root;
  }
};
