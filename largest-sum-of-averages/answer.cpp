#define N 102
double dp[N][N];

class Solution {
private:
    int n;
    vector<int> A;

    double average(int i, int j) {
        double total = (i == 0) ? A[j] : A[j] - A[i - 1];
        return total / (j - i + 1);
    }

    void init(vector<int>& A) {
        this->A = A;
        n = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = 0;
            }
        }
    }

    void preSum() {
        for (int i = 1; i < n; ++i)
            A[i] += A[i - 1];
    }

    double dfs(int i, int k) {
        if (dp[i][k] > 0)
            return dp[i][k];
        if (k == 1)
            return dp[i][k] = average(0, i);
        // k > 1
        dp[i][k] = 0;
        for (int p = i; p >= 1; p--) {
            double w = dfs(p - 1, k - 1);
            dp[i][k] = max(dp[i][k], average(p, i) + w);
        }
        return dp[i][k];
    }

public:
    double largestSumOfAverages(vector<int>& A, int K) {
        init(A);
        preSum();
        dfs(n - 1, K);
        return dp[n - 1][K];
    }
};

// [4,1,7,5,6,2,3]
// 4
// [9,1,2,3,9]
// 3
// [1,2,3,4,5,6,7]
// 4