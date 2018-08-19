#define int64 long long
const int64 MOD = 1000000000 + 7;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        vector<int64> twos(A.size(), 1);
        for (int i = 1; i < A.size(); i++)
            twos[i] = (twos[i - 1] * 2) % MOD;
        sort(A.begin(), A.end());
        int64 ans = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                ans += (twos[i] - 1) * A[i];
                ans %= MOD;
            }
            if (i + 1 < n) {
                ans -= (twos[n - i - 1] - 1) * A[i];
                while (ans < 0)
                    ans += MOD;
                ans %= MOD;
            }
        }
        return ans;
    }
};
