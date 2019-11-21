import java.util.Arrays;

class Solution {
    public int maxSumDivThree(int[] nums) {
        int ans = Arrays.stream(nums).filter(num -> num % 3 == 0).sum();
        int[] p = Arrays.stream(nums).filter(num -> num % 3 != 0).toArray();
        int m = p.length;
        int[][] dp = new int[m + 1][3];
        for (int i = 1; i <= m; i++) {
            int val = p[i - 1];
            // not choose
            for (int j = 0; j < 3; j++)
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            // choose
            for (int j = 0; j < 3; j++) {
                int k = dp[i - 1][j] == 0 ? val % 3 : (j + val) % 3;
                dp[i][k] = Math.max(dp[i][k], dp[i - 1][j] + val);
            }
        }
        return ans + dp[m][0];
    }
}

