import java.util.*;

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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        final TreeIterator[] iters = new TreeIterator[]{new TreeIterator(root1), new TreeIterator(root2)};
        final List<Integer> ans = new ArrayList<>();
        final TreeNode[] nodes = new TreeNode[2];
        for (int i = 0; i < 2; i++)
            nodes[i] = iters[i].hasNext() ? iters[i].next() : null;

        while (nodes[0] != null || nodes[1] != null) {
            final int i = (nodes[0] == null || (nodes[1] != null && nodes[1].val <= nodes[0].val)) ? 1 : 0;
            ans.add(nodes[i].val);
            nodes[i] = iters[i].hasNext() ? iters[i].next() : null;
        }
        return ans;
    }
}

class TreeIterator implements Iterator<TreeNode> {
    final private Stack<TreeNode> stack;

    public TreeIterator(TreeNode root) {
        this.stack = new Stack<>();
        pushLeft(root);
    }

    private void pushLeft(TreeNode node) {
        if (node == null)
            return;
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }

    @Override
    public boolean hasNext() {
        return !stack.isEmpty();
    }

    @Override
    public TreeNode next() {
        final TreeNode top = stack.pop();
        pushLeft(top.right);
        return top;
    }
}
