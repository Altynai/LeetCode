#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000000 + 7;

class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size(), dp[n + 1], last[26];
        FILL(dp, 0);
        FILL(last, -1);

        dp[0] = 1;
        FOR(i, 1, n + 1) {
            dp[i] = (dp[i - 1] * 2) % MOD;
            int j = S[i - 1] - 'a';
            if (last[j] != -1)
                dp[i] = (dp[i] - dp[last[j]] + MOD) % MOD;
            last[j] = i - 1;
        }
        return dp[n] - 1;
    }
};
