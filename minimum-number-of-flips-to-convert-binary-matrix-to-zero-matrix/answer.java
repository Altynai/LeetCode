import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Solution {
    private final static int[] dx = new int[]{0, 1, 0, -1};
    private final static int[] dy = new int[]{1, 0, -1, 0};
    private int[] steps;
    private int r;
    private int c;

    private boolean inside(int i, int j) {
        return 0 <= i && i < r && 0 <= j && j < c;
    }

    private int reverse(int state, int i, int j) {
        return state ^ (1 << (i * c + j));
    }

    private int toState(int[][] mat) {
        int state = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                state |= (mat[i][j] << (i * c + j));
        }
        return state;
    }

    public int minFlips(int[][] mat) {
        r = mat.length;
        c = mat[0].length;
        final int n = r * c;
        steps = new int[1 << n];
        Arrays.fill(steps, -1);
        return bfs(toState(mat));
    }

    private int bfs(int start) {
        Queue<Integer> queue = new ArrayDeque<>();
        steps[start] = 0;
        queue.add(start);
        while (!queue.isEmpty()) {
            int state = queue.poll();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int curState = reverse(state, i, j);
                    for (int k = 0, ni, nj; k < 4; k++) {
                        ni = i + dx[k];
                        nj = j + dy[k];
                        if (inside(ni, nj))
                            curState = reverse(curState, ni, nj);
                    }
                    if (steps[curState] == -1 || steps[state] + 1 < steps[curState]) {
                        steps[curState] = steps[state] + 1;
                        queue.offer(curState);
                    }
                }
            }
        }
        return steps[0];
    }
}
