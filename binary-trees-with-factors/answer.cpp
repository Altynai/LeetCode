#define int64 long long
const int64 MOD = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        vector<int64> dp(n, 1);
        sort(A.begin(), A.end());
        map<int64, int> cache;
        for (int i = 0; i < n; i++)
            cache[A[i]] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((int64)A[j] * A[j] == (int64)A[i]) {
                    dp[i] += dp[j] * dp[j] % MOD;
                }
                if (A[i] % A[j] == 0) {
                    int64 div = A[i] / A[j];
                    auto it = cache.find(div);
                    if (div < A[j] && it != cache.end()) {
                        int pos = it->second;
                        dp[i] += dp[j] * dp[pos] * 2 % MOD;
                    }
                } 
            }
        }
        int64 sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + dp[i]) % MOD;
        }
        return sum;
    }
};