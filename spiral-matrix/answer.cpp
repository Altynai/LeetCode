
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0)
            return result;
        int n = matrix[0].size();
        if (n == 0)
            return result;
        int step = 0, total = n * m;
        int x = 0, y = -1, dx = 0, dy = 1;
        int times = 1, horizontal = n, vertical = m - 1;
        while (step < total) {
            if (times % 2 == 1) {
                dx = 0, dy = 1;
                for (int i = 0; step < total && i < horizontal; i++) {
                    x += dx, y += dy;
                    result.push_back(matrix[x][y]);
                    step++;
                }
                dx = 1, dy = 0;
                for (int i = 0; step < total && i < vertical; i++) {
                    x += dx, y += dy;
                    result.push_back(matrix[x][y]);
                    step++;
                }
            } else {
                dx = 0, dy = -1;
                for (int i = 0; step < total && i < horizontal; i++) {
                    x += dx, y += dy;
                    result.push_back(matrix[x][y]);
                    step++;
                }
                dx = -1, dy = 0;
                for (int i = 0; step < total && i < vertical; i++) {
                    x += dx, y += dy;
                    result.push_back(matrix[x][y]);
                    step++;
                }
            }
            times += 1;
            horizontal -= 1;
            vertical -= 1;
        }
        return result;
    }
};
