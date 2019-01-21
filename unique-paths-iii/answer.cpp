#define N 20
#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SZ(a) (a).size()
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
private:
    int n, m, ans, total;
    int sx, sy;
    bool vis[N][N];
    VVI grid;
    
    bool outside(int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= m;
    }

    void init(VVI& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        FILL(vis, 0);
        total = ans = 0;
        FOR(i, 0, n) FOR(j, 0, m) {
            if (grid[i][j] != -1)
                total++;
            if (grid[i][j] == 1)
                sx = i, sy = j;
        }
    }

    void dfs(int x, int y, int cur) {
        if (grid[x][y] == 2) {
            if (cur == total - 1)
                ans++;
            return;
        }
        
        vis[x][y] = true;
        FOR(k, 0, 4) {
            int nx = x + dx[k], ny = y + dy[k];
            if (outside(nx, ny) || vis[nx][ny] || grid[nx][ny] == -1)
                continue;
            dfs(nx, ny, cur + 1);
        }
        vis[x][y] = false;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        init(grid);
        dfs(sx, sy, 0);
        return ans;
    }
};
