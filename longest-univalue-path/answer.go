/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}

func dfs(root *TreeNode, ans *int) int {
    if root.Left == nil && root.Right == nil {
        return 1
    }
    leftCount, rightCount, sumCount := 0, 0, 0
    if root.Left != nil {
        leftCount = dfs(root.Left, ans)
        if (root.Left.Val == root.Val) {
            sumCount += leftCount
        } else {
            leftCount = 0
        }
    }
    if root.Right != nil {
        rightCount = dfs(root.Right, ans)
        if (root.Right.Val == root.Val) {
            sumCount += rightCount
        } else {
            rightCount = 0
        }
    }
    *ans = max(*ans, sumCount + 1)
    return max(leftCount, rightCount) + 1
}

func longestUnivaluePath(root *TreeNode) int {
    if root == nil {
        return 0
    }
    ans := 1
    dfs(root, &ans)
    return ans - 1
}
