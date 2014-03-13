
class Solution {
private:
    static const int dx[];
    static const int dy[];

    int n, m; // board's size
    bool **visited;

    void initBoardSize(vector<vector<char> > &board) {
        n = board.size();
        m = board[0].size();
        visited = new bool*[n];
        for (int i = 0; i < n; i++)
            visited[i] = new bool[m];
    }

    void initVistied() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                visited[i][j] = false;
        }
    }

    bool inBoard(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool dfs(vector<vector<char> > &board, int i, int j, string &word, int index) {
        int length = word.size();
        if (index == length)
            return true;
        if (!inBoard(i, j) || board[i][j] != word[index] || visited[i][j])
            return false;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            if (dfs(board, i + dx[k], j + dy[k], word, index + 1))
                return true;
        }
        return visited[i][j] = false;
    }

    bool search(vector<vector<char> > &board, int i, int j, string &word) {
        initVistied();
        return dfs(board, i, j, word, 0);
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        initBoardSize(board);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && search(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
};

const int Solution::dx[] = {0, 1, 0, -1};
const int Solution::dy[] = {1, 0, -1, 0};
