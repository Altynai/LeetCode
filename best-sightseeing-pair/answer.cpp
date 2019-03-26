class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int ans = A[0] + A[1] - 1;
        int i = (A[0] > A[1] + 1) ? 0 : 1;
        for (int j = 2; j < n; j++) {
            ans = max(ans, A[i] + A[j] + i - j);
            if (A[j] + j > A[i] + i)
                i = j;
        }
        return ans;
    }
};
