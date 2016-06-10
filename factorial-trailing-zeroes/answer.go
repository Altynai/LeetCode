package main

func trailingZeroes(n int) int {
	five := 0
	for n > 0 {
		five += n / 5
		n /= 5
	}
	return five
}
