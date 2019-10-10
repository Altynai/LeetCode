class Solution {
    private static int MOD = 1000000007;
    private int[][] dp;

    private void add(int i, int from, int to) {
        dp[i][to] = (dp[i][to] + dp[i - 1][from]) % MOD;
    }

    public int countVowelPermutation(int n) {
        dp = new int[n][5];
        for (int j = 0; j < 5; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++) {
            // Each vowel 'a' may only be followed by an 'e'.
            add(i, 0, 1);
            // Each vowel 'e' may only be followed by an 'a' or an 'i'.
            add(i, 1, 0);
            add(i, 1, 2);
            // Each vowel 'i' may not be followed by another 'i'.
            add(i, 2, 0);
            add(i, 2, 1);
            add(i, 2, 3);
            add(i, 2, 4);
            // Each vowel 'o' may only be followed by an 'i' or a 'u'.
            add(i, 3, 2);
            add(i, 3, 4);
            // Each vowel 'u' may only be followed by an 'a'.
            add(i, 4, 0);
        }
        int ans = 0;
        for (int j = 0; j < 5; j++)
            ans = (ans + dp[n - 1][j]) % MOD;
        return ans;
    }
}
