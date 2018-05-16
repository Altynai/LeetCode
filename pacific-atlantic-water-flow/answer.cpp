#define N 150
#define M 4
#define MP make_pair

int dx[M] = {0, 0, -1, 1};
int dy[M] = {1, -1, 0, 0};

class Solution {
private:
    bool visited[N][N];
    int count[N][N];
    int n, m;
    vector<vector<int>> matrix;
    queue<pair<int, int>> q;

    bool inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void emptyQueue() {
        while(!q.empty())
            q.pop();
    }

    bool init(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0)
            return false;
        m = matrix[0].size();
        this->matrix = matrix;
        return true;
    }

    void bfs() {
        while(!q.empty()) {
            pair<int, int> pii = q.front();
            q.pop();
            int x = pii.first, y = pii.second;
            for (int i = 0; i < M; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (inside(xx, yy) && !visited[xx][yy] && matrix[xx][yy] >= matrix[x][y]) {
                    count[xx][yy]++;
                    visited[xx][yy] = true;
                    q.push(MP(xx, yy));
                }
            }
        }
    }

    void pacific() {
        emptyQueue();
        memset(visited, false, sizeof(visited));
        for (int i = n - 1, j = 0; j < m;) {
            count[i][j]++;
            visited[i][j] = true;
            q.push(MP(i, j));
            i - 1 >= 0 ? i-- : j++;
        }
        bfs();
    }

    void atlantic() {
        emptyQueue();
        memset(visited, false, sizeof(visited));
        for (int i = n - 1, j = 0; i >= 0;) {
            count[i][j]++;
            visited[i][j] = true;
            q.push(MP(i, j));
            j + 1 < m ? j++ : i--;
        }
        bfs();
    }

    vector<pair<int, int>> solve() {
        memset(count, 0, sizeof(count));
        pacific();
        atlantic();
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (count[i][j] == 2)
                    ans.push_back(MP(i, j));
            }
        }
        return ans;
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (!init(matrix))
            return vector<pair<int, int>>();
        return solve();
    }
};
