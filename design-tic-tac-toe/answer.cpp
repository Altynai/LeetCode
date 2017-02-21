class TicTacToe {
public:
    int n;
    vector<int> rowx, colx;
    vector<int> rowo, colo;
    vector<int> diax, diao;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rowx = vector<int>(n, 0);
        colx = vector<int>(n, 0);
        rowo = vector<int>(n, 0);
        colo = vector<int>(n, 0);
        diax = vector<int>(2, 0);
        diao = vector<int>(2, 0);
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        vector<int>& rowCounter = (player == 1) ? rowx : rowo;
        vector<int>& colCounter = (player == 1) ? colx : colo;
        vector<int>& diaCounter = (player == 1) ? diax : diao;
        rowCounter[row]++;
        if (rowCounter[row] == n)
            return player;
        colCounter[col]++;
        if (colCounter[col] == n)
            return player;
        if (row == col)
            diaCounter[0]++;
        if (row + col == n - 1)
            diaCounter[1]++;
        return (diaCounter[0] == n || diaCounter[1] == n) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */