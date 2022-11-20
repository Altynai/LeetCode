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
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    set<int> s;

    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      s.insert(cur->val);
      if (cur->left)
        dfs(cur->left);
      if (cur->right)
        dfs(cur->right);
    };
    dfs(root);

    vector<vector<int>> ans;
    for (int x : queries) {
      int mi = -1, ma = -1;

      auto it = s.upper_bound(x);
      if (it != s.begin())
        mi = *prev(it);

      it = s.lower_bound(x);
      if (it != s.end())
        ma = *it;

      ans.push_back({mi, ma});
    }
    return ans;
  }
};
