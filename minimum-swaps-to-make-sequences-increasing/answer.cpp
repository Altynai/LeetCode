#define N 1005

class Solution {
private:
    int dp[N][2], n;

    void update(int& a, int b) {
        if (a == -1 || a > b)
            a = b;
    }

public:
    int minSwap(vector<int>& A, vector<int>& B) {
        n = A.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0, dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                int a = A[i - 1], b = B[i - 1];
                if (j & 1)
                    swap(a, b);
                int c = A[i], d = B[i];
                if (j & 2)
                    swap(c, d);
                if (a < c && b < d && dp[i - 1][j & 1] != -1) {
                    int k = (j & 2) >> 1;
                    update(dp[i][k], dp[i - 1][j & 1] + k);
                }
            }
        }
        int ans = -1;
        update(ans, dp[n - 1][0]);
        update(ans, dp[n - 1][1]);
        return ans;
    }
};
