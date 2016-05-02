package main

import "fmt"

func oneAt(num int, pos int) bool {
	return (num & (1 << uint32(pos))) >= 1
}

func singleNumber(nums []int) []int {
	n := len(nums)
	xor := 0
	for i := 0; i < n; i++ {
		xor ^= nums[i]
	}
	numA, numB := 0, 0
	for i := 0; i < 32; i++ {
		if oneAt(xor, i) {
			for j := 0; j < n; j++ {
				if oneAt(nums[j], i) {
					numA ^= nums[j]
				} else {
					numB ^= nums[j]
				}
			}
			break
		}
	}
	return []int{numA, numB}
}

func main() {
	nums := []int{1, 2, 1, 3, 2, 5}
	fmt.Println(singleNumber(nums))
}
