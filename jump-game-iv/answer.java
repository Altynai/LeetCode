import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Solution {
  public int minJumps(int[] arr) {
    final int n = arr.length;
    final Map<Integer, List<Integer>> g = new HashMap<>();
    for (int i = 0; i < n; i++) {
      final List<Integer> idx = g.getOrDefault(arr[i], new LinkedList<>());
      idx.add(i);
      g.put(arr[i], idx);
    }

    final Map<Integer, Integer> first = new HashMap<>();
    final Queue<Integer> q = new ArrayDeque<>();
    final int[] d = new int[n];
    Arrays.fill(d, -1);

    for (int i : g.get(arr[0])) {
      d[i] = i == 0 ? 0 : 1;
      q.add(i);
    }
    first.put(arr[0], 0);

    while (!q.isEmpty()) {
      final int i = q.poll();
      if (i == n - 1) return d[n - 1];

      for (int j : new int[] {i + 1, i - 1}) {
        if (j < 0 || j >= n) continue;
        if (arr[i] == arr[j]) continue;
        if (!first.containsKey(arr[j]) || d[i] + 1 < d[first.get(arr[j])]) {
          first.put(arr[j], j);
          for (int k : g.get(arr[j])) {
            q.add(k);
            int v = (j == k) ? d[i] + 1 : d[i] + 2;
            if (d[k] == -1 || v < d[k]) d[k] = v;
          }
        }
        if (d[j] == -1 || d[i] + 1 < d[j]) {
          q.add(j);
          d[j] = d[i] + 1;
        }
      }
    }
    return -1;
  }
}

