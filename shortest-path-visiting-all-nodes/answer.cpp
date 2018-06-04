#define N 12

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int dp[1 << N][N];
        memset(dp, -1, sizeof(dp));
        int n = graph.size();
        for (int i = 0; i < n; i++)
            dp[1 << i][i] = 0;

        for (int i = 0; i < (1 << n); i++) {
            bool repeat = true;
            while (repeat) {
                repeat = false;
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == -1)
                        continue;
                    for (int k : graph[j]) {
                        int& w = dp[i | (1 << k)][k];
                        if (w == -1 || dp[i][j] + 1 < w) {
                            w = dp[i][j] + 1;
                            if (i & (1 << k))
                                repeat = true;
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int j = 0; j < n; j++) {
            int w = dp[(1 << n) - 1][j];
            if (w == -1)
                continue;
            if (ans == -1 || w < ans)
                ans = w;
        }
        return ans;
    }
};
