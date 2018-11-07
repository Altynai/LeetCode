#define MOD 1000000007
#define M 10

vector<vector<int>> jump = {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {0, 3, 9},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
};

class Solution {
private:
    void addition(int& a, int b) {
        a = (a + b) % MOD;
    }

public:
    int knightDialer(int N) {
        int dp[N][M];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < M; j++)
            dp[0][j] = 1;
        for (int i = 0; i + 1 < N; i++) {
            for (int j = 0; j < M; j++)
                for (int& k : jump[j])
                    addition(dp[i + 1][k], dp[i][j]);
        }
        int ans = 0;
        for (int j = 0; j < M; j++)
            addition(ans, dp[N - 1][j]);
        return ans;
    }
};
