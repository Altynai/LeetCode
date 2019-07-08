import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
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
    private List<TreeNode> ans;
    private Set<Integer> seen;

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        ans = new ArrayList<>();
        seen = new HashSet<>();
        for (int i : to_delete)
            seen.add(i);
        dfs(root, true);
        return ans;
    }

    private TreeNode dfs(TreeNode root, boolean parentDeleted) {
        if (root == null)
            return null;
        int value = root.val;
        if (seen.contains(value)) {
            dfs(root.left, true);
            dfs(root.right, true);
            return null;
        } else {
            if (parentDeleted)
                ans.add(root);
            root.left = dfs(root.left, false);
            root.right = dfs(root.right, false);
            return root;
        }
    }
}

