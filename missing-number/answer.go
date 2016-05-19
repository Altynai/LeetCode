package main

func missingNumber(nums []int) int {
    n := len(nums)
    sum := 0
    for i := 0; i < n; i++ {
        sum += nums[i]
    }
    return n * (n + 1) / 2 - sum
}