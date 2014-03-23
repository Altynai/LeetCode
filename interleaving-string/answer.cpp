
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        int length = s3.size();
        if (n + m != length)
            return false;
        if (n == 0 || m == 0)
            return (n == 0) ? (s2 == s3) : (s1 == s3);
        bool **dp = new bool* [n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new bool[m + 1];
            memset(dp[i], 0, sizeof(bool) * (m + 1));
        }
        // dp[i][j] = true means
        // isInterleave(s1.substr(0, i), s2.substr(0, j), \
        //              s3.substr(0, i + j) = true
        if (s1[0] == s3[0])
            dp[1][0] = true;
        if (s2[0] == s3[0])
            dp[0][1] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!dp[i][j])
                    continue;
                // s1 match's s3
                if (s1[i] == s3[i + j] && i < n)
                    dp[i + 1][j] = true;
                // s2 match's s3
                if (s2[j] == s3[i + j] && j < m)
                    dp[i][j + 1] = true;
            }
        }
        return dp[n][m];
    }
};
