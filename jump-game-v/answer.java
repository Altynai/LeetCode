import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Solution {
  private int n;
  private Map<Integer, List<Integer>> g;
  private int[] dp;

  private int dfs(int i) {
    if (dp[i] != -1) return dp[i];
    dp[i] = 0;
    for (int j : g.get(i)) dp[i] = Math.max(dp[i], 1 + dfs(j));
    return dp[i];
  }

  public int maxJumps(int[] arr, int d) {
    n = arr.length;
    g = new HashMap<>();
    for (int i = 0; i < n; i++) {
      final List<Integer> nodes = new LinkedList<>();
      for (int j = i + 1; j < n && j <= i + d && arr[j] < arr[i]; j++) nodes.add(j);
      for (int j = i - 1; j >= 0 && j >= i - d && arr[j] < arr[i]; j--) nodes.add(j);
      g.put(i, nodes);
    }
    dp = new int[n];
    Arrays.fill(dp, -1);
    for (int i = 0; i < n; i++) dfs(i);
    return Arrays.stream(dp).max().getAsInt() + 1;
  }
}

