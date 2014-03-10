
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool **is_palindrome = new bool*[n];
        for (int i = 0; i < n; i++) {
            is_palindrome[i] = new bool[n];
            memset(is_palindrome[i], 0, sizeof(bool) * n);
        }
        // 1, 3, 5, ...
        for (int i = 0; i < n; i++)
            is_palindrome[i][i] = true;
        // 2, 4, 6, ...
        for (int i = 0; i + 1 < n; i++)
            is_palindrome[i][i + 1] = (s[i] == s[i + 1]);
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j + i - 1 < n; j++)
                is_palindrome[j][j + i - 1] = (is_palindrome[j + 1][j + i - 2]) && (s[j] == s[j + i - 1]);
        }
        int *dp = new int[n];
        for (int i = 0; i < n; i++)
            dp[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (is_palindrome[j][i]) {
                    if (j)
                        dp[i] = std::min(dp[i], dp[j - 1] + 1);
                    else
                        dp[i] = std::min(dp[i], 0);
                }
            }
        }
        return dp[n - 1];
    }
};