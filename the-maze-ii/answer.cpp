#define NIL -1
#define x first
#define y second
#define Point pair<int, int>
#define MP(a, b) make_pair((a), (b))
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = { -1, 0, 1, 0};

struct Node {
    Point p;
    int dis;
    Node(Point _p, int _dis) {
        p = _p;
        dis = _dis;
    }

    friend bool operator<(const Node& lh, const Node& rh) {
        return lh.dis >= rh.dis;
    }
};

class Solution {
public:
    int n, m;

    bool within(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze.size() == 0 ? 0 : maze[0].size();
        if (n == 0 || m == 0)
            return -1;
        if (start[0] == destination[0] && start[1] == destination[1])
            return 0;
        vector<vector<int>> distance = vector<vector<int>>(n, vector<int>(m, NIL));
        priority_queue<Node> q;
        int x = start[0], y = start[1];
        distance[x][y] = 0;
        q.push(Node(MP(x, y), distance[x][y]));
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            if (node.p.x == destination[0] && node.p.y == destination[1])
                return node.dis;
            for (int i = 0; i < 4; ++i) {
                int nx = node.p.x + dx[i], ny = node.p.y + dy[i];
                while (within(nx, ny) && maze[nx][ny] == 0)
                    nx += dx[i], ny += dy[i];
                nx -= dx[i], ny -= dy[i];
                int d = abs(node.p.x - nx) + abs(node.p.y - ny);
                if (distance[nx][ny] == NIL || distance[nx][ny] > distance[node.p.x][node.p.y] + d) {
                    distance[nx][ny] = distance[node.p.x][node.p.y] + d;
                    q.push(Node(MP(nx, ny), distance[nx][ny]));
                }
            }
        }
        return -1;
    }
};