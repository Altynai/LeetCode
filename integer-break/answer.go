package main

func integerBreak(n int) int {
	if n <= 3 {
		return n - 1
	} else {
		answer := 1
		for n > 4 {
			answer *= 3
			n -= 3
		}
		return answer * n
	}
}
