package main

func countBits(num int) []int {
	ret := make([]int, num+1)
	for i := 1; i <= num; i++ {
		ret[i] = ret[i>>1] + i&1
	}
	return ret
}

func main() {
	countBits(262144)
}
