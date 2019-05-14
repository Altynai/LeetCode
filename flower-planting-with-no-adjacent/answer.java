import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    private int[] c;
    private HashMap<Integer, HashSet<Integer>> g;

    public int[] gardenNoAdj(int N, int[][] paths) {
        init(N, paths);
        for (int i = 0; i < N; i++) {
            if (c[i] == -1)
                dfs(i);
        }
        return c;
    }

    private void dfs(int i) {
        if (c[i] != -1)
            return;
        HashSet<Integer> seen = new HashSet<>();
        for (int j : g.get(i)) {
            if (c[j] != -1)
                seen.add(c[j]);
        }
        for (int j = 1; j <= 4; j++) {
            if (!seen.contains(j)) {
                c[i] = j;
                break;
            }
        }
        for (int j : g.get(i))
            dfs(j);
    }

    private void init(int N, int[][] paths) {
        c = new int[N];
        Arrays.fill(c, -1);
        g = new HashMap<>();
        for (int i = 0; i < N; i++) {
            g.put(i, new HashSet<>());
        }
        for (int[] path : paths) {
            int a = path[0] - 1;
            int b = path[1] - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }
    }
}
