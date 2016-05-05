#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    vector<vector<int> > gap;
    int n, m;

    void init(vector<vector<char> >& matrix) {
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
                sum += matrix[i][j] - '0';
                gap[i][j] += sum;
            }
        }
    }

    int region(int r, int c) {
        if (r < 0 || c < 0)
            return 0;
        return gap[r][c];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return region(row2, col2) - region(row1 - 1, col2) - region(row2, col1 - 1) + region(row1 - 1, col1 - 1);
    }

    int solve() {
        if (n == 0)
            return 0;
        int answer = 0;
        int edge = std::min(n, m);
        for (int k = 1; k <= edge; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                for (int j = 0; j + k - 1 < m; ++j) {
                    int area = sumRegion(i, j, i + k - 1, j + k - 1);
                    if (area == k * k)
                        answer = std::max(answer, area);
                }
            }
        }
        return answer;
    }

public:
    int maximalSquare(vector<vector<char> >& matrix) {
        init(matrix);
        return solve();
    }
};