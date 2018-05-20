
func min(a, b int) int {
    if a == -1 || b < a {
        return b
    }
    return a
}

func minimumDeleteSum(s1 string, s2 string) int {
    n, m := len(s1), len(s2)
    dp := make([][]int, n + 1)
    for i := range dp {
        dp[i] = make([]int, m + 1)
    }

    setup := func() {
        for i := 0; i <= n; i++ {
            for j := 0; j <= m; j++ {
                dp[i][j] = -1
            }
        }
        dp[0][0] = 0
        for i, sum := 1, 0; i <= n; i++ {
            sum += int(s1[i - 1])
            dp[i][0] = sum
        }
        for j, sum := 1, 0; j <= m; j++ {
            sum += int(s2[j - 1])
            dp[0][j] = sum
        }
    }

    solve := func() int {
        for i := 1; i <= n; i++ {
            for j := 1; j <= m; j++ {
                if s1[i - 1] == s2[j - 1] {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
                } else{
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + int(s1[i - 1]) + int(s2[j - 1]))
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + int(s1[i - 1]))
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + int(s2[j - 1]))
            }
        }
        return dp[n][m]
    }

    setup()
    return solve()
}
