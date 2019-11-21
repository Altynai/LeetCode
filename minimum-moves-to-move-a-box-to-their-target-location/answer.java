import java.util.*;

class Solution {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public int minPushBox(char[][] grid) {
        PriorityQueue<State> pq = new
                PriorityQueue<>(new StateComparator());
        int[] b = new int[]{0, 0}, t = new int[]{0, 0}, s = new int[]{0, 0};
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 'B')
                    b = new int[]{i, j};
                if (grid[i][j] == 'T')
                    t = new int[]{i, j};
                if (grid[i][j] == 'S')
                    s = new int[]{i, j};
            }
        }
        pq.add(new State(b, t, s, 0, grid));
        Map<State, Integer> seen = new HashMap<>();
        while (!pq.isEmpty()) {
            State cs = pq.poll();
            if (cs.isGameEnd())
                return cs.moves;
            for (State ns : cs.next()) {
                if (!seen.containsKey(ns) || ns.moves < seen.get(ns)) {
                    seen.put(ns, ns.moves);
                    pq.offer(ns);
                }
            }
        }
        return -1;
    }

    class StateComparator implements Comparator<State> {

        @Override
        public int compare(State o1, State o2) {
            if (o1.moves == o2.moves)
                return Integer.compare(o1.h, o2.h);
            return Integer.compare(o1.moves, o2.moves);
        }
    }

    class State {
        int[] b, t, p;
        int moves;
        int h;
        char[][] grid;

        public State(int[] b, int[] t, int[] p, int moves, char[][] grid) {
            this.b = b;
            this.t = t;
            this.p = p;
            this.moves = moves;
            this.grid = grid;
            this.h = Math.abs(b[0] - t[0]) + Math.abs(b[1] - t[1]);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return Arrays.equals(b, state.b) &&
                    Arrays.equals(t, state.t) &&
                    Arrays.equals(p, state.p);
        }

        @Override
        public int hashCode() {
            int result = Arrays.hashCode(b);
            result = 31 * result + Arrays.hashCode(t);
            result = 31 * result + Arrays.hashCode(p);
            return result;
        }

        boolean isGameEnd() {
            return Arrays.equals(b, t);
        }

        boolean isBlock(int[] xy) {
            return grid[xy[0]][xy[1]] == '#';
        }

        boolean isClean(int[] xy) {
            return isInside(xy) && !Arrays.equals(xy, b) && !isBlock(xy);
        }

        boolean isInside(int[] xy) {
            int x = xy[0], y = xy[1];
            int n = grid.length, m = grid[0].length;
            return 0 <= x && x < n && 0 <= y && y < m;
        }

        boolean hasPath(int[] to) {
            boolean[][] vis = new boolean[grid.length][grid[0].length];
            return dfs(p, to, vis);
        }

        boolean dfs(int[] from, int[] to, boolean[][] vis) {
            if (Arrays.equals(from, to))
                return true;
            vis[from[0]][from[1]] = true;
            for (int k = 0; k < 4; k++) {
                int nx = from[0] + dx[k], ny = from[1] + dy[k];
                int[] nf = {nx, ny};
                if (isInside(nf) && !Arrays.equals(nf, b) && !isBlock(nf) && !vis[nx][ny]) {
                    if (dfs(nf, to, vis))
                        return true;
                }
            }
            return false;
        }

        List<State> next() {
            List<State> ans = new ArrayList<>();
            for (int k = 0; k < 4; k++) {
                int[] front = {b[0] + dx[k], b[1] + dy[k]};
                int[] back = {b[0] - dx[k], b[1] - dy[k]};
                if (isClean(front) && isClean(back) && hasPath(back)) {
                    ans.add(new State(front, t, back, moves + 1, grid));
                }
            }
            return ans;
        }
    }
}
