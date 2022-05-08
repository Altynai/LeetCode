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
  int averageOfSubtree(TreeNode *root) {
    int ans = 0;

    function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *cur) -> pair<int, int> {
      int sum = cur->val, cnt = 1;

      vector<TreeNode *> nodes = {cur->left, cur->right};
      for (auto node : nodes) {
        if (node) {
          auto res = dfs(node);
          sum += res.first;
          cnt += res.second;
        }
      }
      if (sum / cnt == cur->val)
        ans++;
      return {sum, cnt};
    };

    dfs(root);
    return ans;
  }
};
