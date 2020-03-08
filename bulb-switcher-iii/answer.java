class Solution {
  private int[] fenwick;

  void update(int i, int n, int value) {
    while (i <= n) {
      fenwick[i] += value;
      i += i & (-i);
    }
  }

  int sum(int i) {
    int ans = 0;
    while (i >= 1) {
      ans += fenwick[i];
      i -= i & (-i);
    }
    return ans;
  }

  public int numTimesAllBlue(int[] light) {
    final int n = light.length;
    fenwick = new int[n + 1];
    int blue = 0, max = 0;
    for (int i = 0; i < n; i++) {
      update(light[i], n, 1);
      max = Math.max(max, light[i]);
      if (sum(max) == max) blue++;
    }
    return blue;
  }
}

