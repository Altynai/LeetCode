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
  int count(vector<int> &a) {
    int n = a.size();
    if (n <= 1)
      return 0;

    vector<int> b = a;
    sort(b.begin(), b.end());

    int ans = 0;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (vis[i])
        continue;

      // find length of the loop
      int cnt = 0, j = i;
      while (!vis[j]) {
        vis[j] = 1;
        cnt++;
        j = lower_bound(b.begin(), b.end(), a[j]) - b.begin();
      }
      ans += cnt - 1;
    }
    return ans;
  }

  int minimumOperations(TreeNode *root) {
    vector<vector<int>> l;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int depth) {
      if (depth >= l.size())
        l.push_back({});

      l[depth].push_back(cur->val);
      if (cur->left)
        dfs(cur->left, depth + 1);
      if (cur->right)
        dfs(cur->right, depth + 1);
    };
    dfs(root, 0);

    int ans = 0;
    for (auto &v : l)
      ans += count(v);
    return ans;
  }
};
