#include "queue"
#include "vector"
#include "cstdio"
#include "string"
#include "cassert"
#include "cstring"
using namespace std;


class Solution {
private:
    static const int dx[4];
    static const int dy[4];

    void clearQueue(queue<int> &q) {
        while (!q.empty())
            q.pop();
    }

    bool insideRegion(int x, int y, int n, int m) {
        return x >= 1 && x < n - 1 && y >= 1 && y < m - 1;
    }

    vector<pair<int, int> > findRegions(vector<vector<char> > &board) {
        vector<pair<int, int> > result;
        int n = board.size(), m = 0;
        if (n == 0)
            return result;
        m = board[0].size();
        bool flag = true; // check if the region is validate
        bool **visited = new bool*[n];
        for (int i = 0; i < n; i++) {
            visited[i] = new bool[m];
            memset(visited[i], 0, sizeof(bool) * m);
        }

        queue<int> q;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] != 'O' || visited[i][j])
                    continue;
                flag = true;
                clearQueue(q);
                q.push(i), q.push(j);
                visited[i][j] = true;
                while (!q.empty()) {
                    int x = q.front(); q.pop();
                    int y = q.front(); q.pop();
                    for (int k = 0; k < 4; k++) {
                        int _x = x + dx[k];
                        int _y = y + dy[k];
                        if (board[_x][_y] == 'X' || visited[_x][_y])
                            continue;
                        if (board[_x][_y] == 'O' && !insideRegion(_x, _y, n, m)) {
                            flag = false;
                            continue;
                        }
                        // if (i == 3 && j == 2)
                        //     printf("%d %d\n", _x, _y);
                        visited[_x][_y] = true;
                        q.push(_x), q.push(_y);
                    }
                }
                if (flag) {
                    // printf("%d %d\n", i, j);
                    result.push_back(make_pair(i, j));
                }
            }
        }
        return result;
    }

    void markRegion(vector<vector<char> > &board, vector<pair<int, int> > &regions) {
        int n = board.size(), m = 0;
        if (n == 0)
            return;
        m = board[0].size();
        bool **visited = new bool*[n];
        for (int i = 0; i < n; i++) {
            visited[i] = new bool[m];
            memset(visited[i], 0, sizeof(bool) * m);
        }
        queue<int> q;
        for (int index = 0; index < regions.size(); index++) {
            int i = regions[index].first, j = regions[index].second;
            clearQueue(q);
            q.push(i), q.push(j);
            board[i][j] = 'X';
            visited[i][j] = true;
            while (!q.empty()) {
                int x = q.front(); q.pop();
                int y = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int _x = x + dx[k];
                    int _y = y + dy[k];
                    if (board[_x][_y] != 'O' || !insideRegion(_x, _y, n, m) || visited[_x][_y])
                        continue;
                    board[_x][_y] = 'X';
                    visited[_x][_y] = true;
                    q.push(_x), q.push(_y);
                }
            }
        }
    }

public:
    void solve(vector<vector<char> > &board) {
        vector<pair<int, int> > regions = findRegions(board);
        // printf("point %d %d\n", regions[0].first, regions[0].second);
        markRegion(board, regions);
    }
};

const int Solution::dx[4] = {0, -1, 0, 1};
const int Solution::dy[4] = { -1, 0, 1, 0};

void printBoard(vector<vector<char> > &board) {
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution;
    vector<vector<char> > board;
    // case 1
    // for (int i = 0; i < 3; i++)
    //     board.push_back(std::vector<char>(3, 'X'));
    // board[1][1] = 'O';
    // solution->solve(board);
    // assert(board[1][1] == 'X');

    // case 2
    // board.clear();
    // string s2[] = {"XOXOXO", "OXOXOX", "XOXOXO", "OXOXOX"};
    // for (int i = 0; i < 4; i++) {
    //     const char *ch = s2[i].c_str();
    //     board.push_back(std::vector<char>(ch, ch + 6));
    // }
    // solution->solve(board);
    // assert(board[1][1] == 'X');

    // case 3
    board.clear();
    string s3[] = {"OXOOOX", "OOXXXO", "XXXXXO", "OOOOXX", "XXOOXO", "OOXXXX"};
    for (int i = 0; i < 6; i++) {
        const char *ch = s3[i].c_str();
        board.push_back(std::vector<char>(ch, ch + 6));
    }
    printBoard(board);
    printf("------------------\n");
    solution->solve(board);
    printBoard(board);
    return 0;
}