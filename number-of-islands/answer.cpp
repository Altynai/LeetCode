
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
private:
    vector<vector<bool> > visited;
    vector<vector<char> > grid;
    int n, m;

    void init(vector<vector<char> >& grid) {
        n = grid.size();
        if (n == 0)
            return;
        m = grid[0].size();
        visited = vector<vector<bool> >(n);
        for (int i = 0; i < n; ++i)
            visited[i] = vector<bool>(m, false);
        this->grid = grid;
    }

    void bfs(int x, int y) {
        queue<pair<int, int> > q;
        visited[x][y] = true;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            pair<int, int> position = q.front();
            q.pop();
            x = position.first, y = position.second;
            for (int i = 0; i < 4; ++i) {
                int _x = x + dx[i], _y = y + dy[i];
                if (_x >= 0 && _x < n && _y >= 0 && _y < m && grid[_x][_y] == '1' && !visited[_x][_y]) {
                    visited[_x][_y] = true;
                    q.push(make_pair(_x, _y));
                }
            }
        }
    }

    int solution() {
        if (n == 0)
            return 0;
        int islands = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    bfs(i, j);
                }
            }
        }
        return islands;
    }

public:
    int numIslands(vector<vector<char> >& grid) {
        init(grid);
        return solution();
    }
};