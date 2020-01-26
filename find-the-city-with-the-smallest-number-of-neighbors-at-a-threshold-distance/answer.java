import java.util.Arrays;

class Solution {
  public int findTheCity(int n, int[][] edges, int distanceThreshold) {
    final int[][] d = init(n, edges);
    floyd(n, d);

    int i = -1;
    long c = -1;
    for (int j = 0; j < n; j++) {
      long found = Arrays.stream(d[j]).filter(v -> v >= 0 && v <= distanceThreshold).count();
      if (c == -1 || found <= c) {
        c = found;
        i = j;
      }
    }
    return i;
  }

  private int[][] init(int n, int[][] edges) {
    final int[][] d = new int[n][n];
    for (int[] r : d) Arrays.fill(r, -1);
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int[] edge : edges) {
      int a = edge[0], b = edge[1], w = edge[2];
      d[a][b] = d[b][a] = w;
    }
    return d;
  }

  private void floyd(int n, int[][] d) {
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][k] != -1 && d[k][j] != -1) {
            int w = d[i][k] + d[k][j];
            if (d[i][j] == -1 || w < d[i][j]) d[i][j] = w;
          }
        }
      }
    }
  }
}

