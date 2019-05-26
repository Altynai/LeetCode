import java.util.Arrays;

class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] w = Arrays.copyOf(heights, n);
        Arrays.sort(w);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] != heights[i])
                ans++;
        }
        return ans;
    }
}
