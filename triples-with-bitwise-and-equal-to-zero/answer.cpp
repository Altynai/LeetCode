#define N 2
#define M 1 << 16
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

int dp[N][M];

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        FILL(dp, 0);
        int cur = 1, pre = 0;
        FOR(i, 0, n)
            dp[pre][A[i]] += 1;
        FOR(k, 0, 2) {
            FILL(dp[cur], 0);
            FOR(i, 0, n) FOR(j, 0, M)
                dp[cur][j & A[i]] += dp[pre][j];
            swap(cur, pre);
        }
        return dp[pre][0];
    }
};
