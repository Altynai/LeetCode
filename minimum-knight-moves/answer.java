import java.util.*;

class Solution {
    private static int[][] MOVES = new int[][]{
            {-2, -1}, {-2, 1},
            {-1, -2}, {-1, 2},
            {1, -2}, {1, 2},
            {2, -1}, {2, 1}
    };
    private Set<Integer> seen;
    private Queue<List<Integer>> q;

    private Integer hash(int x, int y) {
        return 1000000007 * x + y;
    }

    public int minKnightMoves(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        seen = new HashSet<>();
        q = new ArrayDeque<>();

        q.add(Arrays.asList(0, 0, 0));
        seen.add(hash(0, 0));

        while (!q.isEmpty()) {
            List<Integer> cur = q.poll();
            if (cur.get(0) == x && cur.get(1) == y)
                return cur.get(2);

            for (int[] move : MOVES) {
                int nx = cur.get(0) + move[0], ny = cur.get(1) + move[1];
                Integer next = hash(nx, ny);
                if (!seen.contains(next) && nx > -4 && ny > -4) {
                    seen.add(next);
                    q.add(Arrays.asList(nx, ny, cur.get(2) + 1));
                }
            }
        }
        return -1;
    }
}

