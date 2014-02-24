
class Solution {
private:
    int findRowIndex(vector<vector<int> > &matrix, int n, int target) {
        int low = 0, high = n - 1, mid, index = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (target >= matrix[mid][0]) {
                index = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return index;
    }

    int findColumnIndex(vector<int> &row, int m, int target) {
        int low = 0, high = m - 1, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (target == row[mid])
                return mid;
            else if (target > row[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (!n)
            return false;
        int m = matrix[0].size();
        if (!m)
            return false;
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;
        int row = findRowIndex(matrix, n, target);
        return findColumnIndex(matrix[row], m, target) != -1;
    }
};