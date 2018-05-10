func max(a, b int) int {
    if (a > b) {
        return a
    } else {
        return b
    }
}

func min(a, b int) int {
    if (a < b) {
        return a
    } else {
        return b
    }
}

func maxIncreaseKeepingSkyline(grid [][]int) int {
    r, c := len(grid), len(grid[0])
    rmax := make([]int, r)
    cmax := make([]int, c)
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            rmax[i] = max(rmax[i], grid[i][j]);
            cmax[j] = max(cmax[j], grid[i][j]);
        }
    }
    sum := 0
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            sum += min(rmax[i], cmax[j]) - grid[i][j]
        }
    }
    return sum
}
