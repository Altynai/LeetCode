class Solution {
public:
    int countRoutes(vector<int>& a, int s, int t, int f) {
        int n = a.size();
        int mod = 1e9 + 7, dp[n][f + 1];
        memset(dp, 0, sizeof(dp));
        dp[s][f] = 1;
        
        for (int j = f; j > 0; j--) {
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (i == k || abs(a[i] - a[k]) > j)
                        continue;
                    int rem = j - abs(a[i] - a[k]);
                    dp[k][rem] = (dp[k][rem] + dp[i][j]) % mod;
                }
            }
        }
        
        int ans = 0;
        for (int j = f; j >= 0; j--)
            ans = (ans + dp[t][j]) % mod;
        return ans;
    }
};
