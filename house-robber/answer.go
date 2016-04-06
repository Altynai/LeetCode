package main

func rob(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 2)
	}
	value := nums[0]
	dp[0][0] = 0
	dp[0][1] = nums[0]
	for i := 1; i < n; i++ {
		// rob this house
		dp[i][1] = dp[i-1][0] + nums[i]
		if dp[i-1][0] < dp[i-1][1] {
			dp[i][0] = dp[i-1][1]
		} else {
			dp[i][0] = dp[i-1][0]
		}
		if value < dp[i][1] {
			value = dp[i][1]
		}
		if value < dp[i][0] {
			value = dp[i][0]
		}
	}
	return value
}
