
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size();
        int m = n > 0 ? image[0].size() : 0;
        if (n == 0 || m == 0)
            return 0;
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        pair<int, int> u = make_pair(x, y);
        q.push(u);
        visited[x][y] = true;
        int minx = x, maxx = x;
        int miny = y, maxy = y;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i];
                int ny = u.second + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                else if (visited[nx][ny])
                    continue;
                else if (image[nx][ny] == '0')
                    continue;
                else {
                    pair<int, int> v = make_pair(nx, ny);
                    minx = min(minx, nx);
                    maxx = max(maxx, nx);
                    miny = min(miny, ny);
                    maxy = max(maxy, ny);
                    visited[nx][ny] = true;
                    q.push(v);
                }
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};