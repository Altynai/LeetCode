class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> B;
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < m; i++)
            B.push_back(vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                B[j][i] = A[i][j];
        }
        return B;
    }
};
