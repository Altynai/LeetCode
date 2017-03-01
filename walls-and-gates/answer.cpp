#define inf 2147483647
#define unreached -2
#define Point pair<int, int>
#define x first
#define y second
const int dx[4] = { -1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms.size() ? rooms[0].size() : 0;
        if (n == 0 || m == 0)
            return;
        queue<Point> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            Point u = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = u.x + dx[i];
                int ny = u.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (rooms[nx][ny] == -1)
                    continue;
                int d = rooms[u.x][u.y] + 1;
                if (rooms[nx][ny] > d) {
                    rooms[nx][ny] = d;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
};