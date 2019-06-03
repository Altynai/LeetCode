import java.util.HashMap;
import java.util.Map;

class Solution {
    private int[][] sums;
    private int n;
    private int m;

    private int solve(int i, int j, int target) {
        Map<Integer, Integer> counter = new HashMap<>();
        counter.put(0, 1);
        int ans = 0, key = 0;
        for (int k = 0; k < m; k++) {
            key += (i == 0) ? sums[j][k] : sums[j][k] - sums[i - 1][k];
            int value = counter.getOrDefault(key - target, 0);
            ans += value;
            counter.put(key, counter.getOrDefault(key, 0) + 1);
        }
        return ans;
    }

    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        n = matrix.length;
        m = matrix[0].length;
        sums = new int[n][m];
        for (int j = 0; j < m; j++) {
            sums[0][j] = matrix[0][j];
            for (int i = 1; i < n; i++)
                sums[i][j] = sums[i - 1][j] + matrix[i][j];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += solve(i, j, target);
            }
        }
        return ans;
    }
}
