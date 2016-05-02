package main

func productExceptSelf(nums []int) []int {
	n := len(nums)
	answer := make([]int, n)
	answer[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		answer[i] = answer[i+1] * nums[i]
	}
	answer[0] = answer[1]
	product := nums[0]
	for i := 1; i+1 < n; i++ {
		answer[i] = product * answer[i+1]
		product = product * nums[i]
	}
	answer[n-1] = product
	return answer
}
