class Solution {
private:
    int n, m;
    vector<vector<int> >* matrix;

    bool search(int x0, int y0, int x1, int y1, int target) {
        if (x0 > x1 || y0 > y1)
            return false;
        if (x0 == x1 && y0 == y1)
            return (*matrix)[x0][y0] == target;
        int midx = (x0 + x1) >> 1, midy = (y0 + y1) >> 1;
        if (target == (*matrix)[midx][midy])
            return true;
        else if (target < (*matrix)[midx][midy])
            return search(x0, y0, midx - 1, y1, target) || \
                   search(midx, y0, x1, midy - 1, target);
        else
            return search(x0, midy + 1, midx, y1, target) || \
                   search(midx + 1, y0, x1, y1, target);
    }

public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        n = matrix.size();
        if (n == 0)
            return false;
        this->matrix = &matrix;
        m = matrix[0].size();
        // quick return
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;
        return search(0, 0, n - 1, m - 1, target);
    }
};