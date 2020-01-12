import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
  public int makeConnected(int n, int[][] connections) {
    final DSU dsu = new DSU(n);
    int cables = 0;
    for (int[] connection : connections) {
      int a = dsu.find(connection[0]), b = dsu.find(connection[1]);
      if (a == b) cables++;
      dsu.join(a, b);
    }
    int parts = IntStream.range(0, n).boxed().map(dsu::find).collect(Collectors.toSet()).size();
    return cables < parts - 1 ? -1 : parts - 1;
  }
}

class DSU {
  private int n;
  private int[] p;

  public DSU(int n) {
    this.n = n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  public int find(int x) {
    int r = x;
    while (p[r] != r) r = p[r];
    int i = x;
    while (p[i] != r) {
      int j = p[i];
      p[i] = r;
      i = j;
    }
    return r;
  }

  public void join(int x, int y) {
    p[x] = y;
  }
}

