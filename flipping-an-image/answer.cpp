class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 0)
            return A;
        int m = A[0].size();
        for (int i = 0; i < n; i++) {
            reverse(A[i].begin(), A[i].end());
            for (int j = 0; j < m; j++)
                A[i][j] = 1 - A[i][j];
        }
        return A;
    }
};
