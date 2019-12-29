import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public boolean canReach(int[] arr, int start) {
        final int n = arr.length;
        final boolean[] visited = new boolean[n];
        final Queue<Integer> queue = new ArrayDeque<>();

        visited[start] = true;
        queue.offer(start);
        while (!queue.isEmpty()) {
            final int i = queue.poll();
            if (arr[i] == 0)
                return true;
            for (int j : new int[]{i + arr[i], i - arr[i]}) {
                if (0 <= j && j < n && !visited[j]) {
                    visited[j] = true;
                    queue.offer(j);
                }
            }
        }
        return false;
    }
}
