
class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> sum;
    int n, m;

    int changeBit(int i) {
        return i & (-i);
    }

    int sumRange(int row, int col) {
        int ans = 0;
        for (int i = row; i >= 1; i -= changeBit(i)) {
            for (int j = col; j >= 1; j -= changeBit(j)) {
                ans += sum[i][j];
            }
        }
        return ans;
    }

    void updatePosition(int row, int col, int diff) {
        for (int i = row; i <= n; i += changeBit(i)) {
            for (int j = col; j <= m; j += changeBit(j)) {
                sum[i][j] += diff;
            }
        }
    }

public:
    NumMatrix(vector<vector<int>> matrix) {
        this->matrix = matrix;
        n = matrix.size();
        m = n > 0 ? matrix[0].size() : 0;
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                updatePosition(i + 1, j + 1, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        updatePosition(row + 1, col + 1, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;
        return sumRange(row2, col2) - sumRange(row1 - 1, col2) - \
               sumRange(row2, col1 - 1) + sumRange(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */