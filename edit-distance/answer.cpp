
class Solution {
private:
    void transferStatus(int &a, int b) {
        if (a == -1 || b < a)
            a = b;
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        word1.insert(word1.begin(), ' ');
        word2.insert(word2.begin(), ' ');
        int **dp = new int* [n + 1];
        // dp[i][j] means the minimum number of steps
        // required to convert word1.substr(1, i) to word2.substr(1, j).
        for (int i = 0; i <= n; i++) {
            dp[i] = new int [m + 1];
            memset(dp[i], -1, sizeof(int) * (m + 1));
        }
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i] == word2[j])
                    transferStatus(dp[i][j], dp[i - 1][j - 1]);
                else{
                	int minValue = std::min(dp[i - 1][j], dp[i][j - 1]);
                	minValue = std::min(minValue, dp[i - 1][j - 1]);
                    transferStatus(dp[i][j], minValue + 1);
                }
            }
        }
        return dp[n][m];
    }
};