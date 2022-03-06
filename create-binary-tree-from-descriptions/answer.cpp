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
  TreeNode *createBinaryTree(vector<vector<int>> &des) {
    const int N = 1e5 + 1;
    vector<TreeNode *> nodes(N, nullptr);
    vector<bool> hasParent(N, false);

    for (auto &d : des) {
      for (int i = 0; i < 2; i++)
        if (!nodes[d[i]])
          nodes[d[i]] = new TreeNode(d[i]);

      hasParent[d[1]] = true;
      if (d[2] == 1)
        nodes[d[0]]->left = nodes[d[1]];
      else
        nodes[d[0]]->right = nodes[d[1]];
    }

    for (int i = 1; i <= N; i++) {
      if (nodes[i] and !hasParent[i])
        return nodes[i];
    }
    return nullptr;
  }
};
