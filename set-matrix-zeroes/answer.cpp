
class Solution {
private:
    void setRow(vector<vector<int> > &matrix, int row) {
        int n = matrix[row].size();
        for (int j = 0; j < n; j++)
            matrix[row][j] = 0;
    }

    void setColumn(vector<vector<int> > &matrix, int column) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            matrix[i][column] = 0;
    }

public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        bool *row = new bool[n];
        for (int i = 0; i < n; i++)
        	row[i] = false;
        bool *column = new bool[m];
        for (int j = 0; j < m; j++)
        	column[j] = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (row[i])
                setRow(matrix, i);
        }
        for (int j = 0; j < m; j++) {
            if (column[j])
                setColumn(matrix, j);
        }
    }
};