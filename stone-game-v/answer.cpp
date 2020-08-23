class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        int dp[n + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
        
        function<int(int, int)> dfs = [&](int l, int r) {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];

            int ans = 0;
            for (int k = l; k < r; k++) {
                int s1 = sum[k] - sum[l - 1];
                int s2 = sum[r] - sum[k];
                if (s1 < s2) ans = max(ans, s1 + dfs(l, k));
                else if (s2 < s1) ans = max(ans, s2 + dfs(k + 1, r));
                else ans = max(ans, s1 + max(dfs(l, k), dfs(k + 1, r)));
            }
            return dp[l][r] = ans;
        };
        
        return dfs(1, n);
    }
};
