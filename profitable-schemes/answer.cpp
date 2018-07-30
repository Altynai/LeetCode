#define N 102
#define int64 long long
const int64 mod = 1000000000 + 7;

class Solution {
private:
    int64 dp[N][N][N];

public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = profit.size();
        memset(dp, 0, sizeof(dp));
        // dp[N][G][P + 1]
        dp[0][0][0] = dp[0][group[0]][profit[0]] = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= G; j++) {
                for (int k = 0; k < N; k++) {
                    if (dp[i][j][k] == 0)
                        continue;
                    int pre = dp[i][j][k];
                    int g = group[i + 1], p = profit[i + 1];
                    // no pick
                    dp[i + 1][j][k] = (dp[i + 1][j][k] + pre) % mod;
                    // pick
                    int np = (p + k > 100) ? 101 : p + k;
                    if (g + j > G)
                        continue;
                    dp[i + 1][j + g][np] = (dp[i + 1][j + g][np] + pre) % mod;
                }
            }
        }
        int64 ans = 0;
        for (int j = 0; j <= G; j++) {
            for (int k = P; k < N; k++) {
                ans += dp[n - 1][j][k];
                ans %= mod;
            }
        }
        return ans;
    }
};
