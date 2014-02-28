
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if (n == 0)
            return result;
        for (int i = 0; i < n; i++)
            result.push_back(vector<int>(n, 0));
        int step = 0, total = n * n;
        int x = 0, y = -1, dx = 0, dy = 1;
        int times = 1, horizontal = n, vertical = n - 1;
        while (step < total) {
            if (times % 2 == 1) {
                dx = 0, dy = 1;
                for (int i = 0; step < total && i < horizontal; i++) {
                    x += dx, y += dy;
                    step++;
                    result[x][y] = step;
                }
                dx = 1, dy = 0;
                for (int i = 0; step < total && i < vertical; i++) {
                    x += dx, y += dy;
                    step++;
                    result[x][y] = step;
                }
            } else {
                dx = 0, dy = -1;
                for (int i = 0; step < total && i < horizontal; i++) {
                    x += dx, y += dy;
                    step++;
                    result[x][y] = step;
                }
                dx = -1, dy = 0;
                for (int i = 0; step < total && i < vertical; i++) {
                    x += dx, y += dy;
                    step++;
                    result[x][y] = step;
                }
            }
            times += 1;
            horizontal -= 1;
            vertical -= 1;
        }
        return result;
    }
};