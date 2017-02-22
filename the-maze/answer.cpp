#define x first
#define y second
#define Point pair<int, int>
#define MP(a, b) make_pair((a), (b))
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = { -1, 0, 1, 0};

class Solution {
public:
    int n, m;

    bool within(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze.size() == 0 ? 0 : maze[0].size();
        if (n == 0 || m == 0)
            return false;
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        queue<Point> q;
        Point u = MP(start[0], start[1]);
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            visited[u.x][u.y] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = u.x + dx[i], ny = u.y + dy[i];
                while (within(nx, ny) && maze[nx][ny] == 0)
                    nx += dx[i], ny += dy[i];
                nx -= dx[i], ny -= dy[i];
                if (visited[nx][ny])
                    continue;
                if (nx == destination[0] && ny == destination[1])
                    return true;
                Point v = MP(nx, ny);
                q.push(v);
            }
        }
        return false;
    }
};