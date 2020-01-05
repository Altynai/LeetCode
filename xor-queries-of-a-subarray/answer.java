class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        final int n = arr.length;
        int[] xor = new int[n + 1];
        for (int i = 1; i <= n; i++)
            xor[i] = xor[i - 1] ^ arr[i - 1];

        final int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; i++) {
            int l = queries[i][0] + 1;
            int r = queries[i][1] + 1;
            ans[i] = xor[r] ^ xor[l - 1];
        }
        return ans;
    }
}
