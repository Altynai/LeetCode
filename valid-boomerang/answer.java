class Solution {
    public boolean isBoomerang(int[][] points) {
        int y1 = points[1][1] - points[0][1], x1 = points[1][0] - points[0][0];
        int y2 = points[2][1] - points[0][1], x2 = points[2][0] - points[0][0];
        return y1 * x2 != y2 * x1;
    }
}
