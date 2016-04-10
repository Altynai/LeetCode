package main

import "fmt"

type Solution struct {
	values []int
	paths  []string
}

func (self *Solution) savePath(depth int) {
	path := ""
	for i := 0; i < depth; i++ {
		if i == 0 {
			path = fmt.Sprintf("%s%d", path, self.values[i])
		} else {
			path = fmt.Sprintf("%s->%d", path, self.values[i])
		}
	}
	self.paths = append(self.paths, path)
}

func (self *Solution) findPath(root *TreeNode, depth int) {
	if depth >= len(self.values) {
		self.values = append(self.values, root.Val)
	} else {
		self.values[depth] = root.Val
	}
	if root.Left == nil && root.Right == nil {
		self.savePath(depth + 1)
		return
	}
	if root.Left != nil {
		self.findPath(root.Left, depth+1)
	}
	if root.Right != nil {
		self.findPath(root.Right, depth+1)
	}
}

func binaryTreePaths(root *TreeNode) []string {
	if root == nil {
		return make([]string, 0)
	}
	solution := &Solution{make([]int, 0), make([]string, 0)}
	solution.findPath(root, 0)
	return solution.paths
}
