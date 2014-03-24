#include "string"
#include "cstdio"
#include "cstring"
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.size(), m = T.size();
        if (n < m)
            return 0;
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new int[m + 1];
            memset(dp[i], 0, sizeof(int) * (m + 1));
        }
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S[i - 1] == T[j - 1])
                    dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    printf("%d\n", solution->numDistinct("abbt", "abt"));
    return 0;
}