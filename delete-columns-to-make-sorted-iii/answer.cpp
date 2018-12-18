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
private:
    bool less(vector<string>& A, int j, int k) {
        FOR(i, 0, A.size()) {
            if (A[i][j] > A[i][k])
                return false;
        }
        return true;
    }

public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        int dp[m], ans = 1;
        FOR(i, 0, m) dp[i] = 1;
        FOR(i, 0, m) FOR(j, 0, i) {
            if (less(A, j, i)) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
        return m - ans;
    }
};
