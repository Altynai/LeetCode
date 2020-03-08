/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
  private int ans;

  private int[] dfs(TreeNode root) {
    if (root.left == null && root.right == null) return new int[] {0, 0};
    final int[] p = new int[2];
    if (root.left != null) p[0] = dfs(root.left)[1] + 1;
    if (root.right != null) p[1] = dfs(root.right)[0] + 1;
    ans = Math.max(ans, p[0]);
    ans = Math.max(ans, p[1]);
    return p;
  }

  public int longestZigZag(TreeNode root) {
    ans = 0;
    dfs(root);
    return ans;
  }
}
