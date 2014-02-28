
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1)
            return;
        vector<vector<int> > temp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                temp[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = temp;
    }
};