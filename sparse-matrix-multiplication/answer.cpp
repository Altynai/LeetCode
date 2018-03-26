class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int x = A.size(), y = A[0].size(), z = B[0].size();
        vector<vector<int>> ans = vector<vector<int>>(x, vector<int>(z, 0));
        vector<bool> zeroRow = vector<bool>(x, false);
        vector<bool> zeroColumn = vector<bool>(z, false);
        for (int i = 0; i < x; i++) {
            int sum = 0;
            for (int j = 0; j < y; j++)
                sum += A[i][j];
            if (sum == 0)
                zeroRow[i] = true;
        }
        for (int j = 0; j < z; j++) {
            int sum = 0;
            for (int i = 0; i < y; i++)
                sum += B[i][j];
            if (sum == 0)
                zeroColumn[j] = true;
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < z; j++) {
                if (zeroRow[i] || zeroColumn[j])
                    continue;
                for (int k = 0; k < y; k++)
                    ans[i][j] += A[i][k] * B[k][j];
            }
        }
        return ans;
    }
};