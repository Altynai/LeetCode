class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] d =  new int[]{a, b, c};
        Arrays.sort(d);
        int mn = (d[1] - d[0] == 1 ? 0 : 1) + (d[2] - d[1] == 1 ? 0 : 1);
        // for "1, 3, 5", move 1 to 4
        if (d[1] - d[0] == 2 || d[2] - d[1] == 2)
            mn = 1;
        int mx = d[2] - d[0] - 2;
        return new int[]{mn, mx};
    }
}
