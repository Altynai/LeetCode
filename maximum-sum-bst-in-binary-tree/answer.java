/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
  private int ans;

  private int[] dfs(TreeNode root) {
    if (root.left == null && root.right == null) {
      ans = Math.max(ans, root.val);
      // sum, min, max, isBinary
      return new int[] {root.val, root.val, root.val, 1};
    }
    int isBinary = 1, val = root.val, sum = root.val, min = root.val, max = root.val;
    if (root.left != null) {
      int[] l = dfs(root.left);
      min = Math.min(min, l[1]);
      max = Math.max(max, l[2]);
      if (l[3] == 0 || l[2] >= val) isBinary = 0;
      sum += l[0];
    }
    if (root.right != null) {
      int[] r = dfs(root.right);
      min = Math.min(min, r[1]);
      max = Math.max(max, r[2]);
      if (r[3] == 0 || r[1] <= val) isBinary = 0;
      sum += r[0];
    }
    if (isBinary == 1) ans = Math.max(ans, sum);
    return new int[] {sum, min, max, isBinary};
  }

  public int maxSumBST(TreeNode root) {
    ans = 0;
    dfs(root);
    return ans;
  }
}
