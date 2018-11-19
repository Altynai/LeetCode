#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy((v).begin(),(v).end(),std::ostream_iterator<int>(std::cout, " " ))

class Solution {
private:
    bool has(int i, int j) {
        return ((i >> j) & 1) == 1;
    }

    int common(const string& s, const string& t) {
        int sn = s.size();
        int m = min(s.size(), t.size());
        DFOR(i, m, 0) {
            if (s.substr(sn - i, i) == t.substr(0, i))
                return i;
        }
        return 0;
    }

    bool update(int& s, int t) {
        if (s == -1 || t < s) {
            s = t;
            return true;
        }
        return false;
    }

public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        int dp[1 << n][n], pre[1 << n][n], c[n][n];
        FILL(dp, -1), FILL(pre, -1);
        FOR(j, 0, n) dp[1 << j][j] = A[j].size();
        FOR(i, 0, n) FOR(j, 0, n) {
            if (i == j)
                continue;
            c[i][j] = common(A[i], A[j]);
        }

        FOR(i, 1, 1 << n) FOR(j, 0, n) FOR(k, 0, n) {
            if (dp[i][j] != -1 && !has(i, k) && j != k) {
                int m = dp[i][j] - c[j][k] + A[k].size();
                if (update(dp[i | (1 << k)][k], m))
                    pre[i | (1 << k)][k] = j;
            }
        }
        
        int ans = -1, j = 0;
        FOR(k, 0, n) {
            if (update(ans, dp[(1 << n) - 1][k]))
                j = k;
        }

        int i = (1 << n) - 1;
        vector<int> q;
        do {
            q.push_back(j);
            int k = pre[i][j];
            i = i ^ (1 << j);
            j = k;
        } while(j != -1);
        reverse(begin(q), end(q));

        string s = A[q[0]];
        FOR(i, 1, n) {
            int len = c[q[i - 1]][q[i]];
            s = s + A[q[i]].substr(len);
        }
        return s;
    }
};
