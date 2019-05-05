class Solution {
    private int minMove(int[] s) {
        int n = s.length, ans = s.length;
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            queue.offer(i);
            // find widest interval [a, b] meets b - a - 1 <= n - 2
            while (!queue.isEmpty() && s[queue.getLast()] - s[queue.getFirst()] >= n)
                queue.removeFirst();
            // corner case "3,4,5,6,10", interval [3,6] meets:
            // 1. queue size equals n - 1
            // 2. no extra gap in queue
            if (queue.size() == n - 1 && s[queue.getLast()] - s[queue.getFirst()] == n - 2)
                ans = Math.min(ans, 2);
            else
                ans = Math.min(ans, n - queue.size());
        }
        return ans;
    }
    
    private int maxMove(int[] s) {
        int n = s.length;
        // choose an endpoint as start will leads to 2 different results
        return Math.max(s[n - 1] - s[1], s[n - 2] - s[0]) - n + 2;
    }

    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        return new int[]{minMove(stones), maxMove(stones)};
    }
}
