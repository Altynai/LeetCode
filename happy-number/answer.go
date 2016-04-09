func loop(n int) int {
	ret := 0
	for n > 0 {
		value := n % 10
		ret += value * value
		n /= 10
	}
	return ret
}

func isHappy(n int) bool {
	if n <= 0 {
		return false
	}
	cache := make(map[int]bool)
	cache[n] = true
	for {
		n = loop(n)
		if n == 1 {
			return true
		} else if _, ok := cache[n]; ok {
			return false
		} else {
			cache[n] = true
		}
	}
	return true
}