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
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    map<int, int> dep;
    map<int, int> hei; // max height in sub-tree
    map<int, multiset<int>> level;

    function<int(TreeNode *, int)> dfs = [&](TreeNode *cur, int d) -> int {
      int val = cur->val;
      dep[val] = d;

      int h = d;
      if (cur->left)
        h = max(h, dfs(cur->left, d + 1));
      if (cur->right)
        h = max(h, dfs(cur->right, d + 1));

      hei[val] = h;
      level[d].insert(h);
      return h;
    };
    dfs(root, 0);

    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int val = queries[i];
      int d = dep[val];

      multiset<int> &s = level[d];
      s.erase(s.find(hei[val]));
      if (s.empty())
        ans[i] = d - 1;
      else
        ans[i] = *prev(s.end());

      s.insert(hei[val]);
    }
    return ans;
  }
};
