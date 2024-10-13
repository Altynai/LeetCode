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
  int kthLargestPerfectSubtree(TreeNode *root, int k) {
    vector<int> ans;

    // returns maximal height, size of subtree
    function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *cur) -> pair<int, int> {
      // leaf
      if (cur->left == nullptr and cur->right == nullptr) {
        ans.push_back(1);
        return {1, 1};
      }

      int cnt = 1, height = 1;
      if (cur->left != nullptr) {
        auto [h, size] = dfs(cur->left);
        height = max(height, h + 1);
        cnt += size;
      }
      if (cur->right != nullptr) {
        auto [h, size] = dfs(cur->right);
        height = max(height, h + 1);
        cnt += size;
      }

      // only consider possible and resonable height
      if (height <= 20 and cnt == (1 << height) - 1)
        ans.push_back(cnt);

      return {height, cnt};
    };
    dfs(root);

    sort(ans.rbegin(), ans.rend());
    return ans.size() >= k ? ans[k - 1] : -1;
  }
};
