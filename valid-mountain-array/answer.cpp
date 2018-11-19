class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 1, n = A.size();
        while (i < n && A[i] > A[i - 1])
            i++;
        if (i == 1 || i == n || A[i] == A[i - 1])
            return false;
        while (i < n && A[i] < A[i - 1])
            i++;
        return i == n;
    }
};
