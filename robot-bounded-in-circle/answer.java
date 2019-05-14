class Solution {

    private static int[] dx = {0, 1, 0, -1};

    private static int[] dy = {1, 0, -1, 0};

    public boolean isRobotBounded(String instructions) {
        int n = instructions.length();
        int m = n * n * 4, k = 0, x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            char ch = instructions.charAt(i % n);
            if (ch == 'G') {
                x += dx[k];
                y += dy[k];
            } else if (ch == 'L') {
                k = (k + 3) % 4;
            } else {
                k = (k + 1) % 4;
            }
            if ((i + 1) % n == 0 && x == 0 && y == 0 && k == 0)
                return true;
        }
        return false;
    }
}
