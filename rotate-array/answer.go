package main

func rotateRange(nums []int, low, high int) {
	var swap int
	for low < high {
		swap = nums[low]
		nums[low] = nums[high-1]
		nums[high-1] = swap
		low++
		high--
	}
}

func rotate(nums []int, k int) {
	count := len(nums)
	if k %= count; k == 0 {
		return
	} else {
		rotateRange(nums, 0, count-k)
		rotateRange(nums, count-k, count)
		rotateRange(nums, 0, count)
	}
}
