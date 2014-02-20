
class Solution {
private:
    bool isRowValid(vector<vector<char> > &board, int row) {
        int count[10] = {0}, index;
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == '.')
                continue;
            index = board[row][j] - '0';
            if (count[index])
                return false;
            count[index] += 1;
        }
        return true;
    }

    bool isColumnValid(vector<vector<char> > &board, int column) {
        int count[10] = {0}, index;
        for (int i = 0; i < 9; i++) {
            if (board[i][column] == '.')
                continue;
            index = board[i][column] - '0';
            if (count[index])
                return false;
            count[index] += 1;
        }
        return true;
    }

    bool isBlockValid(vector<vector<char> > &board, int block) {
        int count[10] = {0}, index;
        int row = (block / 3) * 3;
        int column = (block % 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                index = board[i][j] - '0';
                if (count[index])
                    return false;
                count[index] += 1;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            if (!isRowValid(board, i))
                return false;
            if (!isColumnValid(board, i))
                return false;
            if (!isBlockValid(board, i))
                return false;
        }
        return true;
    }
};