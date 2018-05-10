func xorGame(nums []int) bool {
    xor := 0
    for _, num := range nums {
        xor ^= num
    }
    return xor == 0 || len(nums) % 2 == 0
}
