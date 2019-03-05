#define N 35
#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SZ(a) (a).size()
#define MP(a, b) mate_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

class Solution {
private:
    int dp[N][N][N];
    int sum[N];

public:
    int mergeStones(vector<int>& stones, int m) {
        int n = stones.size();
        if ((n - 1) % (m - 1) != 0)
            return -1;

        sum[0] = 0;
        FILL(dp, 0x3f);
        FOR(i, 1, n + 1) sum[i] = sum[i - 1] + stones[i - 1];
        FOR(i, 1, n + 1) dp[i][i][1] = 0;

        FOR(len, 2, n + 1) FOR(i, 1, n - len + 2) {
            int j = i + len - 1;
            FOR(k, 2, m + 1) FOR(t, i + 1, j + 1)
                dp[i][j][k] = min(dp[i][j][k], dp[i][t - 1][k - 1] + dp[t][j][1]);
            dp[i][j][1] = min(dp[i][j][1], dp[i][j][m] + sum[j] - sum[i - 1]);
        }
        return dp[1][n][1];
    }
};
