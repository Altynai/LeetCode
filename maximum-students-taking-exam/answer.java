import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
  private static final int N = 8;
  private int n;
  private int m;
  private char[][] seats;
  private int[][] dp;

  private int getRowValue(int x) {
    return IntStream.range(0, m).filter(y -> seats[x][y] == '.').map(y -> 1 << y).sum();
  }

  private boolean isBitSet(int v, int i) {
    return (v & (1 << i)) > 0;
  }

  private int countBits(int v) {
    return (int) IntStream.range(0, N + 1).boxed().filter(i -> isBitSet(v, i)).count();
  }

  private boolean isRowConflict(int v) {
    return IntStream.range(0, N)
        .filter(i -> isBitSet(v, i) && isBitSet(v, i + 1))
        .findAny()
        .isPresent();
  }

  private boolean areRowsConflict(int v0, int v1) {
    for (int i = 0; i <= N; i++) {
      if (isBitSet(v1, i)) {
        if (i > 0 && isBitSet(v0, i - 1)) return true;
        if (isBitSet(v0, i + 1)) return true;
      }
    }
    return false;
  }

  private void init(char[][] seats) {
    this.seats = seats;
    n = seats.length;
    m = seats[0].length;
    dp = new int[n][1 << N];
    for (int[] row : dp) Arrays.fill(row, -1);
  }

  public int maxStudents(char[][] seats) {
    init(seats);

    int mask = getRowValue(0);
    for (int j = mask; j >= 0; j = (j == 0 ? -1 : mask & (j - 1))) {
      if (!isRowConflict(j)) dp[0][j] = countBits(j);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int mask0 = getRowValue(i - 1), mask1 = getRowValue(i);
      for (int j = mask0; j >= 0; j = (j == 0 ? -1 : mask0 & (j - 1))) {
        if (dp[i - 1][j] == -1) continue;
        for (int k = mask1; k >= 0; k = (k == 0 ? -1 : mask1 & (k - 1))) {
          if (isRowConflict(k)) continue;
          if (areRowsConflict(j, k)) continue;
          ans = Math.max(ans, dp[i][k] = Math.max(dp[i][k], dp[i - 1][j] + countBits(k)));
        }
      }
    }
    return ans;
  }
}

