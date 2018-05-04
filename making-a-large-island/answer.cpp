#define N 52 * 52

class Solution {
private:
    int pre[N], size[N], n, m;
    vector<vector<int>> grid;

    int convert(int x, int y) {
        return x * n + y;
    }

    int findRoot(int x) {
        int r = x, i = x, j;
        while(pre[r] != r) {
            r = pre[r];
        }
        while(i != r) {
            j = pre[i];
            pre[i] = r;
            i = j;
        }
        return r;
    }

    void init(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0)
            return;
        m = grid[0].size();
        this->grid = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = convert(i, j);
                pre[u] = u;   
                size[u] = (grid[i][j] == 1) ? 1 : 0;
            }
        }
    }
    
    void unionFind() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                int u = convert(i, j);
                int uroot = findRoot(u);
                // up
                if (i > 0 && grid[i - 1][j] == 1) {
                    int v = convert(i - 1, j);
                    int vroot = findRoot(v);
                    if (uroot != vroot) {
                        pre[vroot] = uroot;
                        size[uroot] += size[vroot];
                    }
                }
                // left
                if (j > 0 && grid[i][j - 1] == 1) {
                    int v = convert(i, j - 1);
                    int vroot = findRoot(v);
                    if (uroot != vroot) {
                        pre[vroot] = uroot;
                        size[uroot] += size[vroot];
                    }
                }
            }
        }
    }

    int solve() {
        int ans = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int u = convert(i, j);
                    ans = max(ans, size[u]);
                    continue;
                }
                int tmp = 1;
                set<int> cache;
                for (int k = 0; k < 4; k++) {
                    int ii = i + dx[k], jj = j + dy[k];
                    if (ii < 0 || ii >=n || jj < 0 || jj >= m)
                        continue;
                    if (grid[ii][jj] == 1) {
                        int u = convert(ii, jj);
                        int uroot = findRoot(u);
                        if (cache.find(uroot) == cache.end())
                            tmp += size[uroot];
                        cache.insert(uroot);
                    }
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        init(grid);
        if (n == 0)
            return 0;
        unionFind();
        return solve();
    }
};