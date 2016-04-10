package main

import "testing"

func assert(t *testing.T, output []string, expected []string) {
	for i := 0; i < len(output); i++ {
		if output[i] != expected[i] {
			t.Fatal(output[i], expected[i])
		}
	}
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func TestBinaryTreePaths(t *testing.T) {
	values := []int{0, 1, 2, 3, 4, 5}
	n := len(values) - 1
	nodes := make([]TreeNode, n+1)
	for i := n; i >= 1; i-- {
		nodes[i] = TreeNode{values[i], nil, nil}
		if i*2 <= n {
			nodes[i].Left = &nodes[i*2]
		}
		if i*2+1 <= n {
			nodes[i].Right = &nodes[i*2+1]
		}
	}
	expected := []string{"1->2->4", "1->2->5", "1->3"}
	assert(t, binaryTreePaths(&nodes[1]), expected)
}
