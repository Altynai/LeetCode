#define N 1
#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size(), ans = 1;
        VVI dp(n, VI(2, 1));
        FOR(i, 1, n) {
            if (A[i] > A[i - 1])
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            if (A[i] < A[i - 1])
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};
