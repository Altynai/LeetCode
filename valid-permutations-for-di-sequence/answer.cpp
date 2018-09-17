#define N 201

class Solution {
public:
    int numPermsDISequence(string S) {
        int mod = 1000000000 + 7;
        int dp[N][N] = {0};
        
        int n = S.size();
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (S[i - 1] == 'D') {
                    for (int k = j; k <= i; k++)
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                } else {
                    for (int k = 0; k < j; k++)
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j <= n; j++)
            ans = (ans + dp[n][j]) % mod;
        return ans;
    }
};
