import static java.lang.Math.max;
import static java.lang.Math.min;

class Solution {
    public int maxSumAfterPartitioning(int[] A, int K) {
        int n = A.length;
        int[] dp = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            int mx = 0;
            for (int k = 1; k <= min(K, j) ; k++) {
                mx = max(mx, A[j - k]);
                dp[j] = max(dp[j], dp[j - k] + mx * k);
            }
        }
        return dp[n];
    }
}
