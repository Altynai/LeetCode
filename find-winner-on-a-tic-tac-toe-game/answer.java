import java.util.Arrays;

class Solution {
    private final static int N = 3;
    private final static String[] WINNERS = new String[]{null, "A", "B"};

    public String tictactoe(int[][] moves) {
        int[][] s = new int[N][N];
        for (int i = 0; i < moves.length; i++) {
            int p = (i % 2) + 1;
            s[moves[i][0]][moves[i][1]] = p;
        }
        for (int i = 0; i < N; i++) {
            if (s[i][0] != 0 && s[i][0] == s[i][1] && s[i][1] == s[i][2])
                return WINNERS[s[i][0]];
        }
        for (int j = 0; j < N; j++) {
            if (s[0][j] != 0 && s[0][j] == s[1][j] && s[1][j] == s[2][j])
                return WINNERS[s[1][j]];
        }
        if (s[0][0] != 0 && s[0][0] == s[1][1] && s[1][1] == s[2][2])
            return WINNERS[s[0][0]];
        if (s[0][2] != 0 && s[0][2] == s[1][1] && s[1][1] == s[2][0])
            return WINNERS[s[0][2]];
        return moves.length == N * N ? "Draw" : "Pending";
    }
}
