import java.util.HashMap;
import java.util.Map;
import java.util.stream.IntStream;

class Solution {
    private String convert(int[] row, boolean flip) {
        int n = row.length;
        StringBuilder sb = new StringBuilder();
        for (int i : row) {
            sb.append(flip ? i ^ 1 : i);
        }
        return sb.toString();
    }

    private boolean isSame(int[] row) {
        return IntStream.of(row).sum() == row.length * row[0];
    }

    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix.length, ans = 0;
        boolean[] same = new boolean[n];
        String[] keys = new String[n];
        Map<String, Integer> counter = new HashMap<>();
        for (int i = 0; i < n; i++) {
            same[i] = isSame(matrix[i]);
            if (same[i])
                ans++;
            keys[i] = convert(matrix[i], false);
            if (counter.containsKey(keys[i]))
                counter.put(keys[i], counter.get(keys[i]) + 1);
            else
                counter.put(keys[i], 1);
        }
        for (int i = 0; i < n; i++) {
            if (same[i])
                continue;
            String yek = convert(matrix[i], true);
            int a = counter.getOrDefault(keys[i], 0);
            int b = counter.getOrDefault(yek, 0);
            ans = Math.max(ans, a);
            ans = Math.max(ans, b);
            ans = Math.max(ans, a + b);
        }
        return ans;
    }
}

