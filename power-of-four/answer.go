package main

func isPowerOfFour(num int) bool {
	if num <= 0 {
		return false
	}
	for num > 1 {
		if mod := num % 4; mod != 0 {
			return false
		}
		num = num / 4
	}
	return true
}
