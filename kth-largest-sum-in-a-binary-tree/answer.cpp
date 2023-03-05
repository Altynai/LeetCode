using int64 = long long;

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
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<int64> sum;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *r, int level) {
      if (level >= sum.size())
        sum.push_back(0LL);
      sum[level] += r->val;

      if (r->left)
        dfs(r->left, level + 1);
      if (r->right)
        dfs(r->right, level + 1);
    };
    dfs(root, 0);

    if (sum.size() < k)
      return -1;
    nth_element(sum.begin(), sum.begin() + k - 1, sum.end(), std::greater{});
    return sum[k - 1];
  }
};
