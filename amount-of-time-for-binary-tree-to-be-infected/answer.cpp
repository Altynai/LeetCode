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
  int amountOfTime(TreeNode *root, int start) {
    map<int, vector<int>> adj;

    function<void(TreeNode *)> dfs = [&](TreeNode *u) {
      if (u->left) {
        adj[u->val].push_back(u->left->val);
        adj[u->left->val].push_back(u->val);
        dfs(u->left);
      }
      if (u->right) {
        adj[u->val].push_back(u->right->val);
        adj[u->right->val].push_back(u->val);
        dfs(u->right);
      }
    };
    dfs(root);

    function<int(int, int)> dfs2 = [&](int u, int fa) -> int {
      int dep = 0;
      for (int v : adj[u]) {
        if (v != fa) {
          dep = max(dep, dfs2(v, u) + 1);
        }
      }
      return dep;
    };
    return dfs2(start, -1);
  }
};
