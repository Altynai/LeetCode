import java.util.HashSet;
import java.util.Set;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class FindElements {

    private Set<Integer> seen;

    public FindElements(TreeNode root) {
        seen = new HashSet<>();
        dfs(root, 0);
    }

    private void dfs(TreeNode root, int val) {
        seen.add(val);
        if (root.left != null) dfs(root.left, val * 2 + 1);
        if (root.right != null) dfs(root.right, val * 2 + 2);
    }

    public boolean find(int target) {
        return seen.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
