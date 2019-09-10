class Solution {
private:
    void min(int& a, int b) {
        if (a == -1 || (b != -1 && b < a))
            a = b;
    }

    int find(vector<int>& v, int i, int value) {
        auto last = upper_bound(v.begin() + i, v.end(), value);
        return last == v.end() ? -1 : last - v.begin();
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr2.push_back(-1);
        sort(arr2.begin(), arr2.end());
        auto last = unique(arr2.begin(), arr2.end());
        arr2.erase(last, arr2.end());

        int n = arr1.size(), m = arr2.size();
        int dp[n][m][2];
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < m; j++) {
            dp[0][j][0] = 0;
            if (j >= 1)
                dp[0][j][1] = 1;
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2; k++) {
                    if (dp[i][j][k] == -1)
                        continue;
                    int value = (k == 0) ? arr1[i] : arr2[j];
                    // 不换
                    if (value < arr1[i + 1])
                        min(dp[i + 1][j][0], dp[i][j][k]);
                    // 硬换
                    int index = find(arr2, j + 1, value);
                    if (index != -1)
                        min(dp[i + 1][index][1], dp[i][j][k] + 1);
                }
            }
        }
        int ans = -1;
        for (int j = 0; j < m; j++) {
            min(ans, dp[n - 1][j][0]);
            min(ans, dp[n - 1][j][1]);
        }
        return ans;
    }
};