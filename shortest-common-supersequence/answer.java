class Solution {
    private int[][] get(final String str1, final String str2) {
        int n = str1.length(), m = str2.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1))
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp;
    }

    public String shortestCommonSupersequence(String str1, String str2) {
        int[][] dp = get(str1, str2);
        int n = str1.length(), m = str2.length();
        StringBuilder sb = new StringBuilder();
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j - 1] + 1 && str1.charAt(i - 1) == str2.charAt(j - 1)) {
                sb.append(str1.charAt(--i));
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1])
                sb.append(str1.charAt(--i));
            else
                sb.append(str2.charAt(--j));
        }
        while (i > 0) sb.append(str1.charAt(--i));
        while (j > 0) sb.append(str2.charAt(--j));
        return sb.reverse().toString();
    }
}
