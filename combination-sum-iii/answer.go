package main

import "fmt"

func bitCount(value int) int {
	answer := 0
	for i := 8; i >= 0; i-- {
		if (value & (1 << uint(i))) >= 1 {
			answer++
		}
	}
	return answer
}

func bitSum(value int) int {
	answer := 0
	for i := 8; i >= 0; i-- {
		if (value & (1 << uint(i))) >= 1 {
			answer += 9 - i
		}
	}
	return answer
}

func makeAnswer(value int) []int {
	answer := make([]int, 0)
	for i := 8; i >= 0; i-- {
		if (value & (1 << uint(i))) >= 1 {
			answer = append(answer, 9-i)
		}
	}
	return answer
}

func combinationSum3(k int, n int) [][]int {
	m := (1 << 9) - 1
	answer := make([][]int, 0)
	for i := m; i >= 0; i-- {
		if bitSum(i) == n && bitCount(i) == k {
			answer = append(answer, makeAnswer(i))
		}
	}
	return answer
}

func main() {
	fmt.Println(combinationSum3(3, 9))
}
