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
    private int sum;
    
    private TreeNode dfs(TreeNode root) {
        if (root == null)
            return null;
        root.right = dfs(root.right);
        sum += root.val;
        root.val = sum;
        root.left = dfs(root.left);
        return root;
    }

    public TreeNode bstToGst(TreeNode root) {
        sum = 0;
        return dfs(root);
    }
}
