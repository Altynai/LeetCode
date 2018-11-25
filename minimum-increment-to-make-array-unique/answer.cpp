class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return 0;

        sort(A.begin(), A.end());
        int ans = 0, s = A[0];
        for (int i = 0; i < n; i++) {
            ans += abs(s - A[i]);
            s++;
            if (i + 1 < n)
                s = max(s, A[i + 1]);
        }
        return ans;
    }
};
