import java.util.Arrays;

class Solution {
    public int lastStoneWeight(int[] stones) {
        int n = stones.length;
        while (n > 1) {
            Arrays.sort(stones, 0, n);
            int x = stones[n - 1], y = stones[n - 2];
            if (x == y) {
                n -= 2;
            } else {
                stones[n - 2] = Math.abs(x - y);
                n -= 1;
            }
        }
        return (n == 0) ? 0 : stones[0];
    }
}
