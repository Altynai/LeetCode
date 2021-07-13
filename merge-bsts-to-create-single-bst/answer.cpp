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
  TreeNode *canMerge(vector<TreeNode *> &trees) {
    int n = trees.size(), m = 0;
    map<int, int> rootIndex;
    for (int i = 0; i < n; i++)
      rootIndex[trees[i]->val] = i;

    vector<bool> used(n, 0);
    for (int i = 0; i < n; i++) {
      vector<TreeNode *> children = {trees[i]->left, trees[i]->right};
      m++;
      for (int j = 0; j < 2; j++) {
        TreeNode *child = children[j];
        if (child != nullptr) {
          m++;
          auto it = rootIndex.find(child->val);
          if (it == rootIndex.end())
            continue;
          if (used[it->second])
            return nullptr;

          if (j == 0)
            trees[i]->left = trees[it->second];
          else
            trees[i]->right = trees[it->second];

          m -= 1; // uniq nodes decreased by 1 when merging
          used[it->second] = 1;
        }
      }
    }

    int p = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        if (p != -1)
          return nullptr;
        p = i;
      }
    }
    if (p == -1)
      return nullptr;

    int cnt = 0;
    function<bool(TreeNode *, int, int)> dfs = [&](TreeNode *root, int l,
                                                   int r) -> bool {
      int val = root->val;
      cnt++;
      if (val <= l || val >= r)
        return 0;

      if (root->left && !dfs(root->left, l, val))
        return 0;
      if (root->right && !dfs(root->right, val, r))
        return 0;
      return 1;
    };

    return dfs(trees[p], INT_MIN, INT_MAX) && m == cnt ? trees[p] : nullptr;
  }
};
