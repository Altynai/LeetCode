package main

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func area(A int, B int, C int, D int) int {
	return (C - A) * (D - B)
}

func computeArea(A int, B int, C int, D int, E int, F int, G int, H int) int {
	left := max(A, E)
	right := min(C, G)
	up := min(D, H)
	down := max(B, F)
	common := 0
	if left > right || down > up {
		common = 0
	} else {
		common = (right - left) * (up - down)
	}
	return area(A, B, C, D) + area(E, F, G, H) - common
}
