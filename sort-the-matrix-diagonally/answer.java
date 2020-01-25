import java.util.ArrayList;
import java.util.List;

class Solution {
  private void sort(int[][] mat, int n, int m, int i, int j, int[][] ans) {
    int x = i, y = j;
    final List<Integer> arr = new ArrayList<>();
    while (x < n && y < m) arr.add(mat[x++][y++]);
    arr.sort(Integer::compareTo);

    x = i;
    y = j;
    for (Integer integer : arr) ans[x++][y++] = integer;
  }

  public int[][] diagonalSort(int[][] mat) {
    final int n = mat.length;
    final int m = mat[0].length;
    final int[][] ans = new int[n][m];
    for (int i = 0; i < n; i++) sort(mat, n, m, i, 0, ans);
    for (int j = 1; j < m; j++) sort(mat, n, m, 0, j, ans);
    return ans;
  }
}

