func containsNearbyDuplicate(nums []int, k int) bool {
	n := len(nums)
	if n == 0 {
		return false
	} else {
		cache := make(map[int]int)
		for i := 0; i < n; i++ {
			if index, ok := cache[nums[i]]; ok {
				if i-index <= k {
					return true
				}
			}
			cache[nums[i]] = i
		}
		return false
	}
}