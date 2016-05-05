#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > gap;
    int n, m;

    int region(int r, int c) {
        if (r < 0 || c < 0)
            return 0;
        return gap[r][c];
    }

public:
    NumMatrix(vector<vector<int> > &matrix) {
        n = matrix.size();
        if (n == 0) {
            m = 0;
            return;
        }
        m = matrix[0].size();
        gap = vector<vector<int> >(n);
        for (int i = 0; i < n; ++i) {
            gap[i] = vector<int>(m, 0);
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                if (i > 0)
                    gap[i][j] = gap[i - 1][j];
                sum += matrix[i][j];
                gap[i][j] += sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return region(row2, col2) - region(row1 - 1, col2) - region(row2, col1 - 1) + region(row1 - 1, col1 - 1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);