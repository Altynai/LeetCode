#define M 500
double dp[M][M];

class Solution {
private:
    void init(int N) {
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= N; j++)
                dp[i][j] = -1;
    }

    double dfs(int i, int j) {
        if (i <= 0)
            return j > 0 ? 1 : 0.5;
        else if (j <= 0)
            return 0;
        else if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = 0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
    }

public:
    double soupServings(int N) {
        N = (N % 25 == 0) ? N / 25 : N / 25 + 1;
        if (N >= M)
            return 1.0;
        init(N);
        return dfs(N, N);
    }
};
