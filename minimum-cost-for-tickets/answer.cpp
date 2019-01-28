#define N 1
#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SZ(a) (a).size()
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        VI dp(n + 1, -1);
        dp[0] = 0;

        FOR(i, 1, n + 1) {
            dp[i] = dp[i - 1] + costs[0];
            DFOR(j, i - 1, -1) {
                int diff = (j == 0) ? days[i - 1] : days[i - 1] - days[j - 1];
                int weight = (j == 0) ? 0 : dp[j - 1];
                if (diff < 7)
                    dp[i] = min(dp[i], weight + costs[1]);
                if (diff < 30)
                    dp[i] = min(dp[i], weight + costs[2]);
            }
        }
        return dp[n];
    }
};
