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
  string getDirections(TreeNode *root, int src, int dst) {
    vector<int> path, ps, pd;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *r, int dep) {
      if (r == nullptr)
        return;

      int val = r->val;
      if (dep == path.size())
        path.push_back(val);
      else
        path[dep] = val;

      if (val == src)
        ps = vector<int>(path.begin(), path.begin() + dep + 1);
      if (val == dst)
        pd = vector<int>(path.begin(), path.begin() + dep + 1);

      dfs(r->left, dep + 1);
      dfs(r->right, dep + 1);
    };
    dfs(root, 0);

    // find lca
    int i = 0;
    for (; i < min(ps.size(), pd.size()); i++) {
      if (ps[i] != pd[i])
        break;
    }
    int lca = ps[max(0, i - 1)];
    assert(lca != -1);

    string ans(ps.size() - i, 'U');

    TreeNode *cur = root;
    bool ok = false;
    for (int i = 1; i < pd.size(); i++) {
      if (cur->val == lca)
        ok = true;

      if (cur->left && cur->left->val == pd[i]) {
        if (ok)
          ans.push_back('L');
        cur = cur->left;
      } else {
        if (ok)
          ans.push_back('R');
        cur = cur->right;
      }
    }
    return ans;
  }
};
