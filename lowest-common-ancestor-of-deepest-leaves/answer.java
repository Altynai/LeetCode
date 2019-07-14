import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Set<TreeNode> deepest;
    private int deepth;
    private TreeNode ans;

    private boolean isLeaf(TreeNode root) {
        return root != null && root.left == null && root.right == null;
    }

    private void find(TreeNode root, int current) {
        if (root == null)
            return;
        else if (isLeaf(root)) {
            if (current == deepth)
                deepest.add(root);
            else if (current > deepth) {
                deepth = current;
                deepest = new HashSet<>(Arrays.asList(root));
            }
        } else {
            find(root.left, current + 1);
            find(root.right, current + 1);
        }
    }


    public TreeNode lcaDeepestLeaves(TreeNode root) {
        deepest = new HashSet<>();
        deepth = 0;
        ans = null;

        find(root, 0);
        dfs(root, 0);
        return ans;
    }

    private Set<TreeNode> dfs(TreeNode root, int current) {
        Set<TreeNode> nodes = new HashSet<>();
        if (isLeaf(root) && current == deepth)
            nodes.add(root);
        else {
            if (root.left != null && ans == null)
                nodes.addAll(dfs(root.left, current + 1));
            if (root.right != null && ans == null)
                nodes.addAll(dfs(root.right, current + 1));
        }
        if (ans == null && nodes.equals(deepest))
            ans = root;
        return nodes;
    }
}
