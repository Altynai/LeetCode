#define N 105
#define M 1229
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

bool cmp(const vector<int>& lh, const vector<int>& rh) {
    return lh[0] <= rh[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        int dp[n][n + 1];
        FILL(dp, -1);
        sort(clips.begin(), clips.end(), cmp);
        int mx = 0;
        FOR(i, 0, n) if (clips[i][0] == 0) {
            mx = max(mx, clips[i][1]);
            dp[i][1] = mx;
        }
        FOR(k, 2, n + 1) FOR(j, k - 1, n) FOR(i, 0, j) {
            if (dp[i][k - 1] == -1)
                continue;
            int s = clips[j][0], e = clips[j][1];
            if (dp[i][k - 1] >= s)
                dp[j][k] = max(dp[j][k] , max(e, dp[i][k - 1]));
        }
        FOR(j, 1, n + 1) FOR(i, 0, n) {
            if (dp[i][j] >= T)
                return j;
        }
        return -1;
    }
};
