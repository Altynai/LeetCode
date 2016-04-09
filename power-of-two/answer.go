func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	for n > 1 {
		if n%2 != 0 {
			return false
		} else {
			n /= 2
		}
	}
	return n == 1
}