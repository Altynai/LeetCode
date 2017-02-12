class Solution {
public:
    int findStep(int s, int e) {
        return e <= s ? -1 : 1;
    }

    int countTopBottomDirection(vector<vector<int>>& grid, int sx, int ex, int sy, int ey) {
        int xstep = findStep(sx, ex);
        int ystep = findStep(sy, ey);
        int total = 0;
        for (int y = sy; y != ey; y += ystep) {
            int one = 0;
            for (int x = sx; x != ex; x += xstep) {
                if (grid[x][y] == 1)
                    one++;
                else {
                    if (one)
                        total++;
                    one = 0;
                }
            }
            if (one)
                total++;
        }
        return total;
    }

    int countLeftRightDirection(vector<vector<int>>& grid, int sx, int ex, int sy, int ey) {
        int xstep = findStep(sx, ex);
        int ystep = findStep(sy, ey);
        int total = 0;
        for (int x = sx; x != ex; x += xstep) {
            int one = 0;
            for (int y = sy; y != ey; y += ystep) {
                if (grid[x][y] == 1)
                    one++;
                else {
                    if (one)
                        total++;
                    one = 0;
                }
            }
            if (one)
                total++;
        }
        return total;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        int perimeter = 0;
        // top -> bottom
        perimeter += countTopBottomDirection(grid, 0, n, 0, m);
        // bottom -> top
        perimeter += countTopBottomDirection(grid, n - 1, -1, 0, m);
        // left -> right
        perimeter += countLeftRightDirection(grid, 0, n, 0, m);
        // right -> left
        perimeter += countLeftRightDirection(grid, 0, n, m - 1, -1);
        return perimeter;
    }
};