import javafx.util.Pair;

class Solution {
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};

    private boolean isEscapePossible(int[][] blocked, int[] source, int[] target, int steps) {
        int n = blocked.length, ans = 0;
        Set<Pair<Integer, Integer>> banned = new HashSet<>();
        Set<Pair<Integer, Integer>> seen = new HashSet<>();

        for(int i = 0; i < n; i++)
            banned.add(new Pair<>(blocked[i][0], blocked[i][1]));

        Queue<int[]> queue = new ArrayDeque<>();
        int x = source[0], y = source[1];
        seen.add(new Pair<>(x, y));
        queue.add(new int[]{x, y});
        ans = 1;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            x = cur[0];
            y = cur[1];
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0  || ny < 0 || seen.contains(new Pair<>(nx, ny)) || banned.contains(new Pair<>(nx, ny)))
                    continue;
                seen.add(new Pair<>(nx, ny));
                queue.offer(new int[]{nx, ny});
                ans++;
            }
            if (ans >= steps)
                return true;
        }
        return false;
    }

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        int n = blocked.length;
        return isEscapePossible(blocked, source, target, n * n + 1);
    }
}
