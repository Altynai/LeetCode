#define N 1
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

const i64 MOD = 1000000000 + 7;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        if (n <= 1)
            return 0;

        int m = accumulate(begin(rods), end(rods), 0);
        int dp[n][m + 1];
        FILL(dp, -1);

        dp[0][0] = dp[0][rods[0]] = 0;
        FOR(i, 1, n) FOR(j, 0, m) {
            // no use
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][j];

            // large use
            if (j >= rods[i] && dp[i - 1][j - rods[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - rods[i]]);

            // small use
            if (j + rods[i] <= m && dp[i - 1][j + rods[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + rods[i]] + rods[i]);

            if (rods[i] - j >= 0 && dp[i - 1][rods[i] - j] != - 1) {
                int x = dp[i - 1][rods[i] - j];
                int y = x + rods[i] - j;
                dp[i][j] = max(dp[i][j], y);
            }
        }

        return dp[n - 1][0];
    }
};
