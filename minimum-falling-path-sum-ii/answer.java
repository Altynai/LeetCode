import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int minFallingPathSum(int[][] arr) {
        final int n = arr.length;
        int[][] dp = new int[n][n];
        for (int j = 0; j < n; j++)
            dp[0][j] = arr[0][j];
        for (int i = 1; i < n; i++) {
            TreeMap<Integer, Integer> counter = new TreeMap<>();
            for (int j = 0; j < n; j++)
                counter.put(dp[i - 1][j], counter.getOrDefault(dp[i - 1][j], 0) + 1);
            for (int j = 0; j < n; j++) {
                Iterator<Map.Entry<Integer, Integer>> it = counter.entrySet().iterator();
                final Map.Entry<Integer, Integer> first = it.next();
                if (first.getKey() != dp[i - 1][j] || first.getValue() > 1)
                    dp[i][j] = first.getKey() + arr[i][j];
                else {
                    dp[i][j] = it.next().getKey() + arr[i][j];
                }
            }
        }
        return Arrays.stream(dp[n - 1]).min().getAsInt();
    }
}
