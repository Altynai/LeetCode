class Solution {
public:
    int n, m;
    bool vis[505][505];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool dfs(vector<vector<char>>& a, int i, int j, int pi, int pj) {
        vis[i][j] = 1;
        char ch = a[i][j];
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            if (ni == pi && nj == pj)
                continue;
            if (a[ni][nj] != ch)
                continue;
            if (vis[ni][nj])
                return 1;
            if (dfs(a, ni, nj, i, j))
                return 1;
        }
        return 0;
    }

    bool containsCycle(vector<vector<char>>& a) {
        n = a.size();
        m = a[0].size();
        
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && dfs(a, i, j, -1, -1))
                    return 1;
            }
        }
        return 0;
    }
};
