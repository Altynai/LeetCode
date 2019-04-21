class Solution {
    private int solve(int[] A, int L, int M) {
        int n = A.length, sum = 0;
        int[] prefix = new int[n];
        for (int i = 0; i < L; i++)
            sum += A[i];
        prefix[L - 1] = sum;
        for (int i = L; i < n; i++) {
            sum = sum - A[i - L] + A[i];
            prefix[i] = Math.max(sum, prefix[i - 1]);
        }

        int[] suffix = new int[n];
        sum = 0;
        for (int i = n - 1; i >= n - M; i--)
            sum += A[i];
        suffix[n - M] = sum;
        for (int i = n - M - 1; i >= 0; i--) {
            sum = sum - A[i + M] + A[i];
            suffix[i] = Math.max(sum, suffix[i + 1]);
        }
        
        int ans = 0;
        for (int i = L - 1; i + 1 <= n - M; i++)
            ans = Math.max(ans, prefix[i] + suffix[i + 1]);
        return ans;
    }

    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        return Math.max(solve(A, L, M), solve(A, M, L));
    }
}
