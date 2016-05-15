#define UNDEFINED -1

class Solution {
private:
    int n, m;
    vector<vector<int> > health;
    vector<vector<bool> > in_queue;

    void init(vector<vector<int> >& dungeon) {
        n = dungeon.size();
        if (n == 0)
            return;
        m = dungeon[0].size();
        health = vector<vector<int> >(n);
        in_queue = vector<vector<bool> >(n);
        for (int i = 0; i < n; ++i) {
            health[i] = vector<int>(m, UNDEFINED);
            in_queue[i] = vector<bool>(m, false);
        }
    }

    int solve(vector<vector<int> >& dungeon) {
        queue<pair<int, int> > q;
        health[n - 1][m - 1] = dungeon[n - 1][m - 1] >= 0 ? 1 : 1 - dungeon[n - 1][m - 1];
        q.push(make_pair(n - 1, m - 1));
        in_queue[n - 1][m - 1] = true;
        while (!q.empty()) {
            pair<int, int> coordinate = q.front();
            q.pop();
            int x = coordinate.first, y = coordinate.second;
            in_queue[x][y] = false;
            int min_health = 0, grid = 0;
            // left
            if (x > 0) {
                grid = dungeon[x - 1][y];
                if (grid >= 0)
                    min_health = grid >= health[x][y] ? 1 : health[x][y] - grid;
                else
                    min_health = health[x][y] - grid;
                if (health[x - 1][y] == UNDEFINED || min_health < health[x - 1][y]) {
                    health[x - 1][y] = min_health;
                    if (!in_queue[x - 1][y]) {
                        q.push(make_pair(x - 1, y));
                        in_queue[x - 1][y] = true;
                    }
                }
            }
            // up
            if (y > 0) {
                grid = dungeon[x][y - 1];
                if (grid >= 0)
                    min_health = grid >= health[x][y] ? 1 : health[x][y] - grid;
                else
                    min_health = health[x][y] - grid;
                if (health[x][y - 1] == UNDEFINED || min_health < health[x][y - 1]) {
                    health[x][y - 1] = min_health;
                    if (!in_queue[x][y - 1]) {
                        q.push(make_pair(x, y - 1));
                        in_queue[x][y - 1] = true;
                    }
                }
            }
        }
        return health[0][0];
    }
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        this->init(dungeon);
        if (n == 0)
            return 1;
        return this->solve(dungeon);
    }
};