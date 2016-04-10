package main

import "testing"

func assert(t *testing.T, output int, expected int) {
	if output != expected {
		t.Fatal(output, expected)
	}
}

func TestComputeArea(t *testing.T) {
	assert(t, computeArea(0, 0, 0, 0, -1, -1, 1, 1), 4)
	assert(t, computeArea(-2, -2, 2, 2, -2, -2, 2, 2), 16)
}
