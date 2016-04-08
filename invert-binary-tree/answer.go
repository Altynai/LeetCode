
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	right := invertTree(root.Left)
	left := invertTree(root.Right)
	root.Left = left
	root.Right = right
	return root
}