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
  TreeNode *reverseOddLevels(TreeNode *root) {
    map<int, vector<TreeNode *>> levels;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *r, int dep) {
      if (dep % 2 == 1) {
        levels[dep].push_back(r);
      }
      if (r->left)
        dfs(r->left, dep + 1);
      if (r->right)
        dfs(r->right, dep + 1);
    };
    dfs(root, 0);

    for (auto &[dep, nodes] : levels) {
      int m = nodes.size();
      for (int i = 0; i < m / 2; i++)
        swap(nodes[i]->val, nodes[m - 1 - i]->val);
    }
    return root;
  }
};
