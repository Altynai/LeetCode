
class Solution {
private:
    static const int N = 9;

    bool row_contains[N + 1][N + 1];
    bool column_contains[N + 1][N + 1];
    bool block_contains[N + 1][N + 1];
    vector<pair<int, int> > unfilled_cells;

    void init(vector<vector<char> > &board) {
        memset(row_contains, 0, sizeof(row_contains));
        memset(column_contains, 0, sizeof(column_contains));
        memset(block_contains, 0, sizeof(block_contains));
        unfilled_cells.clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') {
                    unfilled_cells.push_back(make_pair(i, j));
                    continue;
                }
                int index = board[i][j] - '0';
                row_contains[i][index] = true;
                column_contains[j][index] = true;
                int block_id = getBlockID(i, j);
                block_contains[block_id][index] = true;
            }
        }
    }

    int getBlockID(int x, int y) {
        int big_row = x / 3, big_column = y / 3;
        return big_row * 3 + big_column;
    }

    bool findSolution(vector<vector<char> > &board, int index) {
        int n = unfilled_cells.size();
        if (index == n)
            return true;
        pair<int, int> cell = unfilled_cells[index];
        int row_id = cell.first, column_id = cell.second;
        int block_id = getBlockID(row_id, column_id);
        for (int ch = 1; ch <= 9; ch++) {
            if (row_contains[row_id][ch] || \
                    column_contains[column_id][ch] || \
                    block_contains[block_id][ch])
                continue;
            board[row_id][column_id] = ch + '0';
            row_contains[row_id][ch] = true;
            column_contains[column_id][ch] = true;
            block_contains[block_id][ch] = true;
            if (findSolution(board, index + 1))
                return true;
            else {
                row_contains[row_id][ch] = false;
                column_contains[column_id][ch] = false;
                block_contains[block_id][ch] = false;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
        init(board);
        findSolution(board, 0);
    }
};
