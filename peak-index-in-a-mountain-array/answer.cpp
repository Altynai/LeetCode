class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        for (int i = 1; i + 1 < n; i++) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1])
                return i;
        }
        return 1;
    }
};
