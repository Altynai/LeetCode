#define int64 long long
const int64 MOD = 1000000000 + 7;

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int64 dp[L + 1][N + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] += dp[i - 1][j - 1] * (N - j + 1) % MOD;
                dp[i][j] += dp[i - 1][j] * max(0, j - K) % MOD;
                dp[i][j] %= MOD;
            }
        }
        return dp[L][N];
    }
};
