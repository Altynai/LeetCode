/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private boolean dfs(TreeNode node, int sum, int limit) {
        sum += node.val;
        if (node.left == null && node.right == null)
            return sum < limit;
        int children = 0, count = 0;
        if (node.left != null) {
            children++;
            if (dfs(node.left, sum, limit)) {
                node.left = null;
                count++;
            }
        }
        if (node.right != null) {
            children++;
            if (dfs(node.right, sum, limit)) {
                node.right = null;
                count++;
            }
        }
        return children == count;
    }

    public TreeNode sufficientSubset(TreeNode root, int limit) {
        return dfs(root, 0, limit) ? null : root;
    }
}
