class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                inc[i] = inc[i - 1] + 1;
            else
                inc[i] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1])
                dec[i] = dec[i + 1] + 1;
            else
                dec[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int len = inc[i] + dec[i] - 1;
            if (len >= 3 && inc[i] > 1 && dec[i] > 1 && len > ans)
                ans = len;
        }
        return ans;
    }
};
