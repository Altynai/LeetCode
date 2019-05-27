import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int ans = 0, n = customers.length;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                ans += customers[i];
        }
        int sum = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < X; i++) {
            queue.offer(i);
            if (grumpy[i] == 1)
                sum += customers[i];
        }
        int mx = sum;
        for (int i = X; i < n; i++) {
            queue.offer(i);
            if (grumpy[i] == 1)
                sum += customers[i];
            int j = queue.poll();
            if (grumpy[j] == 1)
                sum -= customers[j];
            mx = Math.max(mx, sum);
        }
        return ans + mx;
    }
}
