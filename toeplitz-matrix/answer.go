func isToeplitzMatrix(matrix [][]int) bool {
    n, m := len(matrix), len(matrix[0])
    i, j := n - 1, 0
    for {
        val := matrix[i][j]
        for x, y := i, j; x < n && y < m; {
            if matrix[x][y] != val {
                return false
            }
            x += 1
            y += 1
        }
        if (i == 0 && j == m - 1) {
            break
        }
        if i == 0 {
            j++
        } else {
            i--
        }
    }
    return true
}
