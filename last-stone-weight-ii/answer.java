class Solution {
    public int lastStoneWeightII(int[] stones) {
        int n = stones.length;
        int m = n * 100 + 1;
        boolean[][][] dp = new boolean[n][m][2];
        dp[0][stones[0]][0] = dp[0][stones[0]][1] = true;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2; k++) {
                    // w[k] - w[k ^ 1] = j
                    if (dp[i][j][k]) {
                        // k
                        if (j + stones[i + 1] < m) {
                            dp[i + 1][j + stones[i + 1]][k] = true;
                        }
                        // k^1
                        if (j >= stones[i + 1]) {
                            dp[i + 1][j - stones[i + 1]][k] = true;
                        } else {
                            dp[i + 1][stones[i + 1] - j][k ^ 1] = true;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (dp[n - 1][j][0] || dp[n - 1][j][1])
                return j;
        }
        return -1;
    }
}
