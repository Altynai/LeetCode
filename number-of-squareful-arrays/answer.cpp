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
private:
    bool squareful(int x) {
        int root = (int)sqrt((double)(x));
        return root * root == x;
    }

public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        if (n == 1)
            return 1;

        int dp[1 << n][n];
        unordered_map<int, int> cnt;
        FILL(dp, 0);
        FOR(i, 0, n) {
            cnt[A[i]]++;
            dp[1 << i][i] = 1;
        }

        FOR(i, 0, 1 << n) FOR(j, 0, n) FOR(k, 0, n) {
            if (j == k || dp[i][j] == 0 || (i & (1 << k)))
                continue;
            if (squareful(A[j] + A[k]))
                dp[i | (1 << k)][k] += dp[i][j];
        }
        
        int ans = 0;
        FOR(j, 0, n) ans += dp[(1 << n) - 1][j];
        for (const auto& it : cnt) {
            FOR(i, 1, it.second + 1)
                ans /= i;
        }
        return ans;
    }
};
