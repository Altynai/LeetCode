
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) // trick
            return 0;
        int *dp = new int[n + 1];
        memset(dp, 0, sizeof(int) * (n + 1));
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // one digit
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            // two digits
            if (i >= 2 && s[i - 2] != '0') {
                int value = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (value <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        int result = dp[n];
        delete [] dp;
        return result;
    }
};
