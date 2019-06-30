import java.util.Arrays;

class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int n = books.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int j = i, w = 0, h = 0;
            while (j >= 1 && w + books[j - 1][0] <= shelf_width) {
                w += books[j - 1][0];
                h = Math.max(h, books[j - 1][1]);
                if (dp[i] == -1 || dp[j - 1] + h < dp[i])
                    dp[i] = dp[j - 1] + h;
                j--;
            }
        }
        return dp[n];
    }
}
