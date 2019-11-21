import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        Integer[][] ans = new Integer[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = i + k / m, c = j + k % m;
                r = (r + c / m) % n;
                c %= m;
                ans[r][c] = grid[i][j];
            }
        }
        return Arrays.stream(ans).map(Arrays::asList).collect(Collectors.toList());
    }
}
